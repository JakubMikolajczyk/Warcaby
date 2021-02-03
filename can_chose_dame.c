#include "essential.h"


bool can_chose_dame(int index){

    extern struct game *game;
    int i;

    for(i=index+7;!out_of_board_check(i);i+=7)
        if(game->board[i]==1)
            return true;

    for(i=index-7;!out_of_board_check(i);i-=7)
        if(game->board[i]==1)
            return true;

    for(i=index+9;!out_of_board_check(i);i+=9)
        if(game->board[i]==1)
            return true;

    for(i=index-9;!out_of_board_check(i);i-=9)
        if(game->board[i]==1)
            return true;

    return false;
}
