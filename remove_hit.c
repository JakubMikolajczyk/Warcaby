#include "essential.h"
bool remove_hit(int start,int end){

    extern struct game *game;

    if(start>end){
        int temp=start;
        start=end;
        end=temp;

    }


    if(start%8<end%8){
        for(int i=start+9;i!=end;i+=9){
            if(game->board[i]!=1){
                if(game->board[i]==2||game->board[i]==4)
                    game->pawns[0]--;
                else
                    game->pawns[1]--;

                board_change(i,1);
                return true;
            }
        }
    } else
        for (int i = start+7; i != end; i+=7) {
            if(game->board[i]!=1){

                if(game->board[i]==2||game->board[i]==4)
                    game->pawns[0]--;
                else
                    game->pawns[1]--;

                board_change(i,1);
                return true;
            }
        }


    return false;

}