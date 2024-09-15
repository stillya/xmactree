#include <unistd.h>

enum color { RED, GREEN, BLUE, YELLOW };

static const u_int32_t ABSOLUTE_PADDING_LEFT = 80;
static const u_int32_t ABSOLUTE_PADDING_TOP = 10;

void draw_tree(const char *text);
