#include "essential.h"

void show_available_moves_pawn(bool hit){

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

    if(!out_of_board_check(index-7) &&(game->board[index-7]==a||game->board[index-7]==b))
        if(!out_of_board_check(index-14) && game->board[index-14]==1){
            hit=true;
            button_switch(index-14,true);
        }


    if(!out_of_board_check(index-9) &&(game->board[index-9]==a||game->board[index-9]==b))
        if(!out_of_board_check(index-18) && game->board[index-18]==1){
            hit=true;
            button_switch(index-18,true);
        }

    if(!out_of_board_check(index+7) &&(game->board[index+7]==a||game->board[index+7]==b))
        if(!out_of_board_check(index+14) && game->board[index+14]==1){
            hit=true;
            button_switch(index+14,true);
        }

    if(!out_of_board_check(index+9) &&(game->board[index+9]==a||game->board[index+9]==b))
        if(!out_of_board_check(index+18) && game->board[index+18]==1){
            hit=true;
            button_switch(index+18,true);
        }

    if(hit)
        return;
    if(game->turn) {
        if(!out_of_board_check(index+7) &&game->board[index+7]==1)
            button_switch(index+7,true);

        if(!out_of_board_check(index+9) && game->board[index+9]==1)
            button_switch(index + 9, true);

    }
    else{

        if (!out_of_board_check(index - 7) && game->board[index - 7] == 1)
            button_switch(index - 7, true);


        if (!out_of_board_check(index - 9) && game->board[index - 9] == 1)
            button_switch(index - 9, true);


    }


}