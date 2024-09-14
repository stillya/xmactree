#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <xmas_tree.h>

void draw_tree(const char* text) {

    u_int32_t contentLength = strlen(text);
    u_int32_t index = 0;
    u_int32_t height = 0;

    for (int chInStr = 1; index < contentLength; chInStr += 2) {
        int space = ((ABSOLUTE_PADDING_LEFT - chInStr) / 2);
        printf("%*s", space, "");
        for (int j = 0; j < chInStr; j++) {
            printf("%s", COLORS_VAL[rand_color()]);
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
    draw_wood(height);
}

static void draw_wood(u_int32_t height) {
    u_int32_t middle = ABSOLUTE_PADDING_LEFT / 2;
    u_int32_t start = middle - (height / 4);
    u_int32_t end = middle + (height / 4);

    for (int i = 0; i < (height / 6); i++) {
        printf("%*s", start, "|");
        printf("%*s\n", end - start, "|");
    }
}

static enum color rand_color() {
    return rand() % 4;
}
