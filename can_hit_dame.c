#include "essential.h"

bool can_hit_dame(bool color, int index){

    extern struct game *game;

    int a;
    int b;

    if(game->turn){
        a=2;
        b=4;
    }
    else{
        a=3;
        b=5;
    }

    int i;
    bool posible_hit;

    for(i=index+7, posible_hit=false;!out_of_board_check(i);i+=7){

        if(posible_hit){
            if(game->board[i]==1){
                return true;
            }
            else
                break;
        }

        if(game->board[i]==a||game->board[i]==b)
            posible_hit=true;

    }

    for(i=index+9, posible_hit=false;!out_of_board_check(i);i+=9){

        if(posible_hit){
            if(game->board[i]==1){
                return true;
            }
            else
                break;
        }

        if(game->board[i]==a||game->board[i]==b)
            posible_hit=true;

    }

    for(i=index-7, posible_hit=false;!out_of_board_check(i);i-=7){

        if(posible_hit){
            if(game->board[i]==1){
                return true;
            }
            else
                break;
        }

        if(game->board[i]==a||game->board[i]==b)
            posible_hit=true;

    }

    for(i=index-9, posible_hit=false;!out_of_board_check(i);i-=9){

        if(posible_hit){
            if(game->board[i]==1){
                return true;
            }
            else
                break;
        }

        if(game->board[i]==a||game->board[i]==b)
            posible_hit=true;

    }

    return false;

}

