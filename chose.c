#include "essential.h"

void chose(GtkWidget *click,  int index){


    extern struct game *game;


    if(game->available_chose[index]==0)
        return;


    if(index==game->chosen){

        game->chosen=0;
        buttons_switch(game->turn,true);
        buttons_switch(2,false);
        return;
    }

    game->back=game;    //save game before make move

    game->chosen=index;


    buttons_switch(game->turn,false);
    button_switch(index,true);


    if(game->board[index]==2||game->board[index]==3)
        show_available_moves_pawn(false);
    else
        show_available_moves_dame(false);

}
