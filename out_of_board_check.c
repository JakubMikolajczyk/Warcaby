#include "essential.h"

bool out_of_board_check(int index){

   int x=index%8;
   int y=index/8;

    if(x<0 || x>7 || y<0 || y>7)
        return true;
    else
        return false;


}
