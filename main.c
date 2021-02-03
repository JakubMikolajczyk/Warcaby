#include "essential.h"
#include <stdlib.h>

struct game *game;

int main(int argc, char *argv[]) {

    game=(struct game *) malloc(sizeof(struct game));

    gtk_init(&argc, &argv);

    init();

    gtk_widget_show_all(game->gtk_board);
    gtk_main();

    return 0;
}
