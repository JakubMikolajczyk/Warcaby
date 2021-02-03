#include "essential.h"

void show_available_moves_dame(bool hit){

    extern struct game *game;
    int index = game->chosen;

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
                hit=true;
                button_switch(i,true);
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
                hit=true;
                button_switch(i,true);
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
                hit=true;
                button_switch(i,true);
            }
            else
                break;
        }

        if(game->board[i]==a||game->board[i]==b)
            posible_hit = true;

    }

    for(i=index-9, posible_hit=false;!out_of_board_check(i);i-=9){

        if(posible_hit){
            if(game->board[i]==1){
                hit=true;
                button_switch(i,true);
            }
            else
                break;
        }

        if(game->board[i]==a||game->board[i]==b)
            posible_hit = true;

    }

    if(hit)
        return;


        for(i=index+7;!out_of_board_check(i)&&game->board[i]==1;i+=7)
                button_switch(i,true);

        for(i=index-7;!out_of_board_check(i)&&game->board[i]==1;i-=7)
                button_switch(i,true);

        for(i=index+9;!out_of_board_check(i)&&game->board[i]==1;i+=9)
                button_switch(i,true);

        for(i=index-9;!out_of_board_check(i)&&game->board[i]==1;i-=9)
                button_switch(i,true);

}