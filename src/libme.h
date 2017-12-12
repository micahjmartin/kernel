/*
 * Core functions for the kernel
 */
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define VIDEO_MEMORY 0xb8000
#define VIDEO_MEMORY_LIM (SCREEN_WIDTH * SCREEN_HEIGHT)
// Colors of screen (FG_BG)
#define WHITE_BLACK 0x07

void init_cur(void);

void cur_debug(unsigned int color);

void set_color(unsigned int color);

void set_cursor(int x, int y);

void set_cursor_x(int x);

void set_cursor_y(int y);

void set_cursor_col(int x);

void set_cursor_wrap(int x);

int get_color(void);

int get_cursor_x(void);

int get_cursor_y(void);

int get_cursor_wrap();

int get_cursor_col();

void put_ch(char ch);

void clear_screen();

void print_string(const char *str, int len);

int read_input(void);

