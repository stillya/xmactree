#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define internal static

typedef u_int32_t u_int;

typedef enum COLORS {
    RED,
    GREEN,
    BLUE,
    YELLOW
} COLORS;

static const char *const COLORS_VAL[] = {
        [RED] = "\033[0;31m",
        [GREEN] = "\033[0;32m",
        [BLUE] = "\033[0;34m",
        [YELLOW] = "\033[1;33m"
};

static const u_int ABSOLUTE_PADDING_LEFT = 80;
static const u_int ABSOLUTE_PADDING_TOP = 10;

void drawTree(char* text);

internal void drawWood(u_int height);

internal COLORS getRandomColor();