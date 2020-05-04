//
// Created by Nan Wu on 02/05/2020.
//

int check(square board[BOARD_SIZE][BOARD_SIZE],player players[PLAYERS_NUM],int player_num,int flag[1]){
    flag[0]=1; //pretend this player gonna lose the game, flag initialise to 1
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++) {
            //if there is at least one color of token on the board still match player's color, change flag to 0, this player don't lose
            if(players[player_num].own==0 && board[i][j].stack != NULL && board[i][j].type == VALID && board[i][j].stack->p_color == players[player_num].player_color) {
                flag[0]=0;
            }
        }
    }
    return flag[1];
}
