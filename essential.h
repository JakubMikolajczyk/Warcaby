/*
    color:
    0 - white
    1 - black
    2 - empty dark

    FLAG:
    0 - empty light
    1 - empty dark
    2 - white pawn
    3 - black pawn
    4 - white dame
    5 - black dame
 */


#ifndef WARCABY_ESSENTIAL_H
#define WARCABY_ESSENTIAL_H

#include <gtk/gtk.h>
#include <stdbool.h>

#define test(x)    printf(#x":%d\n",x)
struct game{

    GtkWidget *gtk_board;
    GtkWidget *buttons[8*8];
    int board[8*8];        //board by flag
    bool turn;      //false - white, true - black
    struct game *back;
    bool available_chose[8*8];
    int pawns[2];      //remaining pawns
    int chosen;        //chosen pawn
    bool end_game;
};

int indexer(int x, int y);      //return index
void init();    //init game

void buttons_switch(int flag, bool on_off);       //switch all buttons clickable by flag
void button_switch(int index,bool on_off);     //switch one button by index
void change_turn();
void board_change(int index, int flag);      //change button image

void chose(GtkWidget *click, int index);      //chose pawn by user click
void move(GtkWidget *click,int index);      //move chosen pawn by user click

bool can_hit_pawn(bool color, int index);
bool can_hit_dame(bool color, int index);
void show_available_moves_pawn(bool hit);        //show available moves for actual chose pawn
void show_available_moves_dame(bool hit);        //show available moves for actual chose dame


bool remove_hit(int start, int end);        //remove hit pawn
bool out_of_board_check(int index);     //return true if out of board
void update_available_chose();
bool can_chose_pawn(bool color,int index);
bool can_chose_dame(int index);

void check_winner();
void print_winner(bool color);
#endif //WARCABY_ESSENTIAL_H
