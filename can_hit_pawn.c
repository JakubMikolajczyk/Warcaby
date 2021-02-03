#include "essential.h"


bool can_hit_pawn(bool color,  int index){

    extern struct game *game;

     int a;
     int b;

    if(color){
        a=2;
        b=4;
    }
    else{
        a=3;
        b=5;
    }

    if(!out_of_board_check(index-7) &&(game->board[index-7]==a||game->board[index-7]==b))
        if(!out_of_board_check(index-14) && game->board[index-14]==1)
            return true;

    if(!out_of_board_check(index-9) &&(game->board[index-9]==a||game->board[index-9]==b))
        if(!out_of_board_check(index-18) && game->board[index-18]==1)
            return true;

    if(!out_of_board_check(index+7) &&(game->board[index+7]==a||game->board[index+7]==b))
        if(!out_of_board_check(index+14) && game->board[index+14]==1)
            return true;

    if(!out_of_board_check(index+9) &&(game->board[index+9]==a||game->board[index+9]==b))
        if(!out_of_board_check(index+18) && game->board[index+18]==1)
            return true;

    return false;

}
