#include "essential.h"
#include <stdlib.h>
void init(){

    extern struct game *game;

    {
       int tab[] = {0, 3, 0, 3, 0, 3, 0, 3,
                    3, 0, 3, 0, 3, 0, 3, 0,
                    0, 3, 0, 3, 0, 3, 0, 3,
                    1, 0, 1, 0, 1, 0, 1, 0,
                    0, 1, 0, 1, 0, 1, 0, 1,
                    2, 0, 2, 0, 2, 0, 2, 0,
                    0, 2, 0, 2, 0, 2, 0, 2,
                    2, 0, 2, 0, 2, 0, 2, 0};

    for(int i=0;i<8*8;i++)
        game->board[i]=tab[i];

        bool tab2[] = { 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0,
                        0, 1, 0, 1, 0, 1, 0, 1,
                        0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0,
                        1, 0, 1, 0, 1, 0, 1, 0,
                        0, 0, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 0, 0, 0, 0,};

    for(int i=0;i<8*8;i++)
        game->available_chose[i]=tab2[i];


    }

    game->turn=false;
    game->chosen=0;
    game->pawns[0]=12;
    game->pawns[1]=12;
    game->back==NULL;
    game->end_game=false;
    //****************************************************************************
    //GTK

    game->gtk_board=gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_position(GTK_WINDOW(game->gtk_board), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(game->gtk_board), 800, 800);
    gtk_window_set_title(GTK_WINDOW(game->gtk_board), "Warcaby");

    gtk_container_set_border_width(GTK_CONTAINER(game->gtk_board), 5);

    GtkWidget *table = gtk_table_new(8, 8, TRUE);
    gtk_table_set_row_spacings(GTK_TABLE(table), 1);
    gtk_table_set_col_spacings(GTK_TABLE(table), 1);


    for(int i=0; i < 8 * 8; i++) {
        if (game->board[i] == 0)
            game->buttons[i] = gtk_image_new_from_file("img/light.jpg");

        if (game->board[i] == 1) {
            GtkWidget *image = gtk_image_new_from_file("img/dark.jpg");
            game->buttons[i] = gtk_button_new();
            gtk_button_set_image(GTK_BUTTON(game->buttons[i]), image);
            gtk_widget_set_sensitive(game->buttons[i], FALSE);
            g_signal_connect(game->buttons[i],"clicked",G_CALLBACK(move),i);


        }

        if (game->board[i] == 2) {
            GtkWidget *image = gtk_image_new_from_file("img/dark_white_pawn.jpg");
            game->buttons[i] = gtk_button_new();
            gtk_button_set_image(GTK_BUTTON(game->buttons[i]), image);
            g_signal_connect(game->buttons[i],"clicked",G_CALLBACK(chose),i);
        }

        if (game->board[i] == 3) {
            GtkWidget *image = gtk_image_new_from_file("img/dark_black_pawn.jpg");
            game->buttons[i] = gtk_button_new();
            gtk_button_set_image(GTK_BUTTON(game->buttons[i]), image);
            gtk_widget_set_sensitive(game->buttons[i], FALSE);
            g_signal_connect(game->buttons[i],"clicked",G_CALLBACK(chose),i);
        }
    }

    for (int x = 0; x < 8; x++)
        for (int y = 0; y < 8; y++)
            gtk_table_attach_defaults (GTK_TABLE(table), game->buttons[indexer(x,y)], x, x+1, y, y+1);

    gtk_container_add(GTK_CONTAINER(game->gtk_board),table);
    g_signal_connect(G_OBJECT(game->gtk_board), "destroy", G_CALLBACK(gtk_main_quit), NULL);
}