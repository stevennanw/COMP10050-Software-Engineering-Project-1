#include <stdio.h>

#include "input_output.h"

#include "move.h"
#include "move.c"
#include "check.h"
#include "check.c"

int main() {

    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];

    initialize_players(players);

    initialize_board(board);

    int num=0,player_num;
    players[0].own=0;
    players[0].capture=0;
    players[1].own=0;
    players[1].capture=0;

    for(int k=0;;k++){
        int flag[1]={0};
        player_num=num%2; //get the player's number

        print_board(board); //print the board

        printf("------------------------------------------\n");

        move(board,players,player_num); //move a piece/stack

        check(board,players,player_num,flag); //check if this player lose the game

        //if this player lose, print its information and end the program.
        if(flag[0]==1){
            printf("Player %d, %s, You lost the game!\n", player_num + 1, players[player_num].name);
            return 0;
        }

        num++;
    }
}
