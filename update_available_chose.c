#include "essential.h"

void update_available_chose(){

    extern struct game *game;

    for(int i=0;i<8;i++)
        if(game->board[i]==2)
            board_change(i,4);

    for(int i=56;i<64;i++)
        if(game->board[i]==3)
            board_change(i,5);

    bool hit=false;

    int a,b;

    if(game->turn){
        a=2;
        b=4;
    }
    else{
        a=3;
        b=5;
    }

    bool endgame=true;


    for(int i=0;i<8*8;i++) {
        if (game->board[i] == 0 || game->board[i] == 1 || game->board[i] == a || game->board[i] == b)
            continue;

        if (game->board[i] == 2 || game->board[i] == 3) {   //pawn

            if (hit) {
                game->available_chose[i] = can_hit_pawn(game->turn, i);
            } else {
                if (can_hit_pawn(game->turn, i)) {
                    hit = true;
                    for (int j = 0; j < i; j++) {
                        game->available_chose[j] = false;
                    }
                    game->available_chose[i] = true;
                    endgame = false;
                } else {
                    if (can_chose_pawn(game->turn, i)) {
                        game->available_chose[i] = true;
                        endgame = false;
                    }
                }
            }

        } else {     //dame

            if (hit) {
                game->available_chose[i] = can_hit_dame(game->turn, i);
            } else {
                if (can_hit_dame(game->turn, i)) {
                    hit = true;
                    for (int j = 0; j < i; j++) {
                        game->available_chose[j] = false;
                    }
                    game->available_chose[i] = true;
                    endgame = false;

                } else {
                    if (can_chose_dame(i)) {
                        game->available_chose[i] = true;
                        endgame = false;
                    }
                }
            }
        }
    }
    game->end_game=endgame;

}