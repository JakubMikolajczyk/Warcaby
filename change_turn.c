#include "essential.h"

void change_turn(){

    extern struct game *game;

        buttons_switch(game->turn, false);
        buttons_switch(!(game->turn),true);
        buttons_switch(2,false);

    //check_winner();

    game->turn=!game->turn;
    game->chosen=0;
    update_available_chose();
    check_winner();

}