#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "xmas_tree.h"

static char* TEXT = "********************************************************";

int main(int argc, char *argv[]) {

    printf("\e[?25l");

    while (1) {
        for (int i = 0; i < ABSOLUTE_PADDING_TOP; i++) {
            printf("\n");
        }
        drawTree(TEXT);
        usleep(150000);
        system("clear");
    }
}