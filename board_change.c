#include "essential.h"

void board_change( int index,  int flag){

    extern struct game *game;

    g_signal_handlers_disconnect_by_func(GTK_BUTTON(game->buttons[index]),G_CALLBACK(move),index);
    g_signal_handlers_disconnect_by_func(GTK_BUTTON(game->buttons[index]),G_CALLBACK(chose),index);

    if(flag==1){
        GtkWidget *image=gtk_image_new_from_file("img/dark.jpg");
        gtk_button_set_image (GTK_BUTTON (game->buttons[index]), image);
        game->board[index]=1;
        button_switch(index,false);
        g_signal_connect(GTK_BUTTON(game->buttons[index]),"clicked",G_CALLBACK(move),index);
        return;
    }

    if(flag==2){
        GtkWidget *image=gtk_image_new_from_file("img/dark_white_pawn.jpg");
        gtk_button_set_image (GTK_BUTTON (game->buttons[index]), image);
        game->board[index]=2;
        button_switch(index,false);
        g_signal_connect(GTK_BUTTON(game->buttons[index]),"clicked",G_CALLBACK(chose),index);
        return;
    }

    if(flag==3){
        GtkWidget *image=gtk_image_new_from_file("img/dark_black_pawn.jpg");
        gtk_button_set_image (GTK_BUTTON (game->buttons[index]), image);
        game->board[index]=3;
        button_switch(index,false);
        g_signal_connect(GTK_BUTTON(game->buttons[index]),"clicked",G_CALLBACK(chose),index);
        return;
    }

    if(flag==4){
        GtkWidget *image=gtk_image_new_from_file("img/dark_white_dame.jpg");
        gtk_button_set_image (GTK_BUTTON (game->buttons[index]), image);
        game->board[index]=4;
        button_switch(index,false);
        g_signal_connect(GTK_BUTTON(game->buttons[index]),"clicked",G_CALLBACK(chose),index);
        return;
    }

    if(flag==5){
        GtkWidget *image=gtk_image_new_from_file("img/dark_black_dame.jpg");
        gtk_button_set_image (GTK_BUTTON (game->buttons[index]), image);
        game->board[index]=5;
        button_switch(index,false);
        g_signal_connect(GTK_BUTTON(game->buttons[index]),"clicked",G_CALLBACK(chose),index);
        return;
    }

}

