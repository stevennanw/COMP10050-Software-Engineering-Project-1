//
// Created by Nan Wu on 26/04/2020.
//
#include <stdio.h>
#include <stdlib.h>

int choice(player players[PLAYERS_NUM], int player_choice[1]);
int loc1(square board[BOARD_SIZE][BOARD_SIZE],player players[PLAYERS_NUM],int player_num,int location[4]);
void direction(square board[BOARD_SIZE][BOARD_SIZE],int location[4]);
void move_stack(square board[BOARD_SIZE][BOARD_SIZE],player players[PLAYERS_NUM],int player_num,int location[4]);
int loc2(square board[BOARD_SIZE][BOARD_SIZE],int location[4]);
struct piece *put(color value, struct piece *top);

void move(square board[BOARD_SIZE][BOARD_SIZE],player players[PLAYERS_NUM],int player_num) {
    printf("Hi,player %d, %s, this is your turn.\n", player_num + 1, players[player_num].name);

    int player_choice[1];
    int location[4] = {0}; //location[0] for old_col, location[1] for old_row, location[2] for new_col, location[3] for new_row

    choice(players, player_choice); //ask player to move a piece/stack or put a new one.

    //if player want to move a piece/stack
    if(player_choice[0]==1){
        loc1(board, players, player_num, location); //get the location of token which player want to move

        direction(board, location); //get the direction player want to move, up/down/left/right

        move_stack(board,players,player_num,location); //move a piece/stack
    }

    //if player want to put a new one
    if(player_choice[0]==2){
        loc2(board, location); //get the location of token which player want to put
        board[location[2]][location[3]].stack = put(players[player_num].player_color,board[location[2]][location[3]].stack); //put a new piece on the board
        board[location[2]][location[3]].num_pieces++;
        players[player_num].own--; //player's own minus one
    }
}

//ask player to move a piece/stack or put a new one.
int choice(player players[PLAYERS_NUM], int player_choice[1]){
    player_choice[0]=0;
    do{
        printf("You can enter 1 to move a piece/stack or enter 2 to place a token from your hand: ");
        scanf("%d",&player_choice[0]);
    }while(player_choice[0]!=1 && player_choice[0]!=2);

    //if player choose to put a new one however they don't have any left, change to move a piece/stack automatically
    if(player_choice[0]==2 && players->own==0){
        printf("You don't have any token in hand, you have to move a piece/stack.");
        player_choice[0]=1;
    }

    return player_choice[1]; //return the choice
}

//get the location of token which player want to move
int loc1(square board[BOARD_SIZE][BOARD_SIZE],player players[PLAYERS_NUM],int player_num,int location[4]) {
    int old_col, old_row;

    //ask player to enter the location
    printf("Which square do you want to move\n");
    printf("Please enter column: ");
    scanf("%d", &old_col);
    printf("Please enter row: ");
    scanf("%d", &old_row);

    //if the location is invalid, print its specific invalid reason and ask user to enter a new one
    while (old_row < 0 || old_col < 0 || old_row > 7 || old_col > 7 || board[old_col][old_row].type == INVALID ||
           board[old_col][old_row].stack->p_color != players[player_num].player_color || board[old_col][old_row].stack == NULL) {
        if (board[old_col][old_row].stack == NULL) {
            printf("There is no token here\n");
        } else if (old_row < 0 || old_col < 0 || old_row > 7 || old_col > 7 ||
                   board[old_col][old_row].type == INVALID) {
            printf("Invalid input, please enter again\n");
        } else if (board[old_col][old_row].stack->p_color != players[player_num].player_color){
            printf("This is not your color, please enter again\n");
        }
        printf("Please enter column: ");
        scanf("%d", &old_col);
        printf("Please enter row: ");
        scanf("%d", &old_row);
    }

    //assign data to location array
    location[0] = old_col;
    location[1] = old_row;
    location[2] = old_col;
    location[3] = old_row;

    return location[4]; //return location
}

//get the direction player want to move, up/down/left/right
void direction(square board[BOARD_SIZE][BOARD_SIZE],int location[4]){
    int dir;
    int col=location[0],row=location[1];
    int length=board[location[0]][location[1]].num_pieces;

    //initialise col and row
    location[0]=col;
    location[1]=row;
    printf("----------you must move tokens to a valid place!----------\n");

    //ask player to enter the direction
    for(int i=0;i<length;i++){
        printf("You can move %d steps, this is step %d, which direction do you want to move?\n",length,i+1);
        printf("Please enter 1 for up, 2 for down, 3 for left and 4 for right: ");
        scanf("%d",&dir);

        //calculate the location after move
        switch (dir) {
            case 1:
                location[0]--;
                break;
            case 2:
                location[0]++;
                break;
            case 3:
                location[1]--;
                break;
            case 4:
                location[1]++;
                break;
            default:
                break;
        }
    }

    //assign data to location array
    location[2]=location[0];
    location[3]=location[1];
    location[0]=col;
    location[1]=row;

    //print move information
    printf("Remove %d tokens from (%d,%d) to (%d,%d)\n",length,location[0],location[1],location[2],location[3]);
}

//move a piece/stack
void move_stack(square board[BOARD_SIZE][BOARD_SIZE],player players[PLAYERS_NUM],int player_num,int location[4]){
    //move old piece/stack to the top of new piece/stack
    piece * top = board[location[0]][location[1]].stack;
    board[location[0]][location[1]].stack = NULL;
    board[location[0]][location[1]].num_pieces=0;
    piece * curr = top;
    int size=1;
    while(curr->next != NULL){
        curr = curr->next;
        size++;
    }
    curr-> next =board[location[2]][location[3]].stack;
    board[location[2]][location[3]].stack = top;
    board[location[2]][location[3]].num_pieces += size;

    //pieces are removed from the bottom of the stack to keep its size equal to 5.
    int count = 1;
    piece *last = NULL;
    piece *remove = NULL;

    //find the first 5 pieces and move to the 5th piece
    while(curr != NULL){
        if(count < 5){
            curr = curr -> next;
            count++;
        } else {
            last = curr;
        }
    }

    //determine if the pieces to remove is the player's color
    if(last != NULL){
        curr = curr->next;
        while(curr != NULL){
            //if it is, players.own +1
            if(curr->p_color == players[player_num].player_color){
                players[player_num].own++;
            }
            //if it is not, players.capture +1
            if(curr->p_color != players[player_num].player_color){
                players[player_num].capture++;
            }
            //then delete this piece and move to next one until the last one
            remove = curr;
            curr = curr->next;
            free(remove);
        }
        last->next = NULL;
    }
}

//get the location of token which player want to put
int loc2(square board[BOARD_SIZE][BOARD_SIZE],int location[4]) {
    int col, row;

    //ask player to enter the location
    printf("Which square do you want to put it\n");
    printf("Please enter column: ");
    scanf("%d", &col);
    printf("Please enter row: ");
    scanf("%d", &row);

    //if the location is invalid, print its invalid and ask user to enter a new one
    while (row < 0 || col < 0 || row > 7 || col > 7 || board[col][row].type == INVALID) {
        printf("Invalid input, please enter again\n");
        printf("Please enter column: ");
        scanf("%d", &col);
        printf("Please enter row: ");
        scanf("%d", &row);
    }

    //assign data to location array
    location[0] = col;
    location[1] = row;
    location[2] = col;
    location[3] = row;

    return location[4]; //return location
}

//put a new piece on the board
struct piece *put(color value, struct piece *top){
    struct piece *curr = top;
    top = malloc(sizeof(piece));
    top->p_color = value;
    top->next = curr;
    return top;
}