#include "essential.h"

bool can_chose_pawn(bool color,int index){

    extern struct game *game;

    if(color){

        if(!out_of_board_check(index+7) &&game->board[index+7]==1)
            return true;

        if(!out_of_board_check(index+9) && game->board[index+9]==1)
            return true;


    }else{

        if (!out_of_board_check(index - 7) && game->board[index - 7] == 1)
            return true;

        if (!out_of_board_check(index - 9) && game->board[index - 9] == 1)
            return true;


    }


    return false;
}
