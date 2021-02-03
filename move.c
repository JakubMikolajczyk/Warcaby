#include "essential.h"

void move(GtkWidget *click,int index){

    extern struct game *game;
    bool was_hit=remove_hit(game->chosen,index);

    board_change(index,game->board[game->chosen]);
    board_change(game->chosen,1);

    if(game->board[index]==2||game->board[index]==3) {

        if (was_hit && can_hit_pawn(game->turn, index)) {
            game->chosen = index;
            show_available_moves_pawn(true);
        } else {
            change_turn();
        }
    } else{

        if (was_hit && can_hit_dame(game->turn, index)) {
            game->chosen = index;
            buttons_switch(2,false);
            show_available_moves_dame(true);
        } else {
            change_turn();
        }
    }
}