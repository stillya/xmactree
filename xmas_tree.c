#include <string.h>
#include "xmas_tree.h"

void drawTree(char *text) {

    u_int contentLength = strlen(text);
    u_int index = 0;
    u_int height = 0;

    for (int chInStr = 1; index < contentLength; chInStr += 2) {
        int space = ((ABSOLUTE_PADDING_LEFT - chInStr) / 2);
        printf("%*s", space, "");
        for (int j = 0; j < chInStr; j++) {
            printf(COLORS_VAL[getRandomColor()]);
            if (index < contentLength) {
                printf("%c", text[index]);
            } else {
                printf("%c", '*');
            }
            index++;
        }

        height++;
        printf("\n");
    }
    printf("\033[1;33m");
    drawWood(height);
}

void drawWood(u_int height) {
    u_int middle = ABSOLUTE_PADDING_LEFT / 2;
    u_int start = middle - (height / 4);
    u_int end = middle + (height / 4);

    for (int i = 0; i < (height / 6); i++) {
        printf("%*s", start, "|");
        printf("%*s\n", end - start, "|");
    }
}

COLORS getRandomColor() {
    return rand() % 4;
}
