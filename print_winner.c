#include "essential.h"


void print_winner(bool color){

    extern struct game *game;

    if(color){

        GtkWidget *dialog;
        dialog = gtk_message_dialog_new(GTK_WINDOW(game->gtk_board), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "END GAME\nBLACK IS WINNER");
        gtk_window_set_title(GTK_WINDOW(dialog), "END GAME");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);

    } else{

        GtkWidget *dialog;
        dialog = gtk_message_dialog_new(GTK_WINDOW(game->gtk_board), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "END GAME\nWHITE IS WINNER");
        gtk_window_set_title(GTK_WINDOW(dialog), "END GAME");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);

    }


}
