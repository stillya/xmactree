#include <string.h>
#include "xmas_tree.h"


void drawTree(char* text) {
    u_int height = getHeightOfTreeOnText(strlen(text));
    u_int maxLength = height * 2;
    u_int index = 0;
    for (int i = 1; i < maxLength; i += 2) {
        int space = ((maxLength - i) / 2) + ABSOLUTE_PADDING_LEFT;
        printf("%*s", space, "");
        for (int j = 0; j < i; j++) {
            printf(COLORS_VAL[getRandomColor()]);
            printf("%c", text[index]);
            index++;
        }

        printf("\n");
    }
    printf("\033[1;33m");
    drawWood(maxLength, height);
}

void drawWood(u_int maxLength, u_int height) {
    u_int start = ((maxLength / 2) - (maxLength / 8)) + ABSOLUTE_PADDING_LEFT;
    u_int end = ((maxLength / 2) + (maxLength / 8)) + ABSOLUTE_PADDING_LEFT;

    printf("%*s", start, "|");
    printf("%*s\n", end - start, "|");

    for (int i = 0; i < (height / 6); i++) {
        printf("%*s", start, "|");
        printf("%*s\n", end - start, "|");
    }
}

COLORS getRandomColor() {
    return rand() % 4;
}

int getHeightOfTreeOnText(size_t count) {
    return count / 9;
}








