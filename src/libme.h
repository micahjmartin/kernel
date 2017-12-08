/*
 * Core functions for the kernel
 */
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define VIDEO_MEMORY 0xb8000
#define VIDEO_MEMORY_LIM (SCREEN_WIDTH * SCREEN_HEIGHT)
// Colors of screen (FG_BG)
#define WHITE_BLACK 0x07
void color_screen(unsigned int color);

void clear_screen();

void print_string(const char *str, int len);

int read_input(void);

