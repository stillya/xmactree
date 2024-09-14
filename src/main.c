#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <xmas_tree.h>


static void init_text(FILE* input);
static char* sanitize_text(char* text);
static void hide_cursor();
static void show_cursor();
static void catch_exit(int sig);

static char* TEXT = NULL;

int main(int argc, char* argv[]) {
    init_text(stdin);
    hide_cursor();
    signal(SIGINT, catch_exit);
    signal(SIGTSTP, catch_exit);
    signal(SIGTERM, catch_exit);

    while (1) {
        for (int i = 0; i < ABSOLUTE_PADDING_TOP; i++) {
            printf("\n");
        }
        draw_tree(TEXT);
        usleep(150000);
        system("clear");
    }

    return 0;
}

static void init_text(FILE* input) {
    if (isatty(STDIN_FILENO)) {
        TEXT = "********************************************************";
    } else {
        FILE* f = input;
        fseek(f, 0, SEEK_END);
        long fsize = ftell(f);
        fseek(f, 0, SEEK_SET);

        TEXT = malloc(fsize + 1);
        fread(TEXT, 1, fsize, f);
        fclose(f);

        TEXT[fsize] = '\0';
        TEXT = sanitize_text(TEXT);
    }
}

static char* sanitize_text(char* text) {
    int count = 0;

    for (int i = 0; text[i]; i++) {
        if (text[i] != ' ' && text[i] != '\n') {
            text[count++] = text[i];
        }
    }
    text[count++] = '\0';
    char* ntext = realloc(text, count);
    if (!ntext) {
        printf("Error reallocating memory\n");
        exit(1);
    }

    return ntext;
}

/* catch sigint, sigterm and sigtstp */
static void catch_exit(int sig) {
    show_cursor();
    exit(0);
}

static void hide_cursor() {
    printf("\e[?25l");
}

static void show_cursor() {
    printf("\e[?25h");
    fflush(stdout);
}
