#include "essential.h"

void buttons_switch( int color,bool on_off){

    extern struct game *game;

    if(color==0){
        for(int i=0;i<8*8;i++){
            if(game->board[i]==2 || game->board[i]==4)
                    gtk_widget_set_sensitive(game->buttons[i], on_off);

        }
    }

    if(color==1) {
        for (int i = 0; i < 8 * 8; i++) {
            if (game->board[i] == 3 || game->board[i] == 5)
                gtk_widget_set_sensitive(game->buttons[i], on_off);
        }
    }

    if(color==2){
        for(int i=0; i < 8 * 8; i++){
            if(game->board[i]==1)
                gtk_widget_set_sensitive(game->buttons[i],on_off);
        }

    }

}

void button_switch( int index, bool on_off){

    extern struct game *game;

    gtk_widget_set_sensitive(game->buttons[index], on_off);

}