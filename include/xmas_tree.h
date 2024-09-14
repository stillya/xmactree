#include <unistd.h>

enum color{
    RED,
    GREEN,
    BLUE,
    YELLOW
};

static const char* const COLORS_VAL[] = {
        [RED] = "\033[0;31m",
        [GREEN] = "\033[0;32m",
        [BLUE] = "\033[0;34m",
        [YELLOW] = "\033[1;33m"
};

static const u_int32_t ABSOLUTE_PADDING_LEFT = 80;
static const u_int32_t ABSOLUTE_PADDING_TOP = 10;

void draw_tree(const char* text);

static void draw_wood(u_int32_t height);
static enum color rand_color();
