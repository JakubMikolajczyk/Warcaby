#include "essential.h"

void check_winner(){

    extern struct game *game;

    if(game->pawns[0]==0) {
        print_winner(1);
        return;
    }
    if(game->pawns[1]==0) {
        print_winner(0);
        return;
    }
    if(game->end_game) {
        print_winner(!game->turn);
        return;
    }
}