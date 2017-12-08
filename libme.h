/*
 * Core functions for the kernel
 */
#define VIDEO_MEMORY 0xb8000
#define VIDEO_MEMORY_LIM 2000
// Colors of screen (FG_BG)
#define WHITE_BLACK 0x07
void color_screen(unsigned int color);

void clear_screen(unsigned int color);

void print_string(const char *str, unsigned int len);

int read_input(void);

