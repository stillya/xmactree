#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "xmas_tree.h"

static char *TEXT = NULL;

void initText();

void sanitizeText(char** data);

int main(int argc, char *argv[]) {

    initText();

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

void initText() {
    if (isatty(STDIN_FILENO)) {
        TEXT = "********************************************************";
    } else {
        FILE *f = stdin;
        fseek(f, 0, SEEK_END);
        long fsize = ftell(f);
        fseek(f, 0, SEEK_SET);

        TEXT = malloc(fsize + 1);
        fread(TEXT, 1, fsize, f);
        fclose(f);

        TEXT[fsize] = '\0';
        sanitizeText(&TEXT);
    }
}

void sanitizeText(char **data) {
    char *text = *data;
    int count = 0;

    for (int i = 0; text[i]; i++) {
        if (text[i] != ' ' && text[i] != '\n') {
            text[count++] = text[i];
        }
    }
    text[count] = '\0';
    count++;
    *data = realloc(*data, count);
}