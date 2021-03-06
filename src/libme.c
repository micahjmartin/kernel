/*
 * Core functions for the kernel
 * Micah Martin (knif3)
 */

#include "libme.h"
#include "string.h"

// Global Variables for printing
int cursor_x = 0;
int cursor_y = 0;
int IO_CUR_COL = 0; // When we goto a \n, where to set the cursor at
int IO_CUR_WRAP = SCREEN_WIDTH; // Position to wrap the cursor
unsigned int screen_color = 0x07;
char *screen = (char*)VIDEO_MEMORY; // Start of the video array
unsigned int screen_limit = VIDEO_MEMORY_LIM; // Max indexes for the Vidmem

void init_cur(void)
{
    set_cursor(0,0);
    set_cursor_wrap(SCREEN_WIDTH);
    set_cursor_col(0);
}

void cur_debug(unsigned int color)
{
    
    char str[6] = "\0\0\0\0\0\0";
    unsigned int tmp_color = screen_color;
    set_color(color);
    int tmp_x = cursor_x;
    int tmp_y = cursor_y;
    int tmp_wrap = IO_CUR_WRAP;
    int tmp_col = IO_CUR_COL;
    set_cursor_col(0);
    set_cursor_wrap(SCREEN_WIDTH);
    set_cursor(0,0);
    
    print_string("Cursor location: ",-1);
    itoc(tmp_x, str);
    print_string(str,-1);
    
    print_string(" ",1);
    itoc(tmp_y, str);
    print_string(str,-1);
    
    print_string("\nCOL: ",-1);
    itoc(tmp_col, str);
    print_string(str,-1);
    print_string(" WRAP: ",-1);
    itoc(tmp_wrap, str);
    print_string(str,-1);

    set_color(tmp_color);
    set_cursor_col(tmp_col);
    set_cursor_wrap(tmp_wrap);
    set_cursor(tmp_x, tmp_y);
}

/*
 * Put a character onto the screen wherever the cursor is
 */
void put_ch(char c)
{
    int pos = 0;
    int num;
    switch(c)
    {
	case 0x08 :
	    // Backspace
	    if(cursor_x != IO_CUR_COL)
		cursor_x = cursor_x - 1;
	    break; 
	case 0x09 :
	    // tab
	    num = (cursor_x + 8) & ~(8 - 1); // Tab only till the next 8
	    num = num - cursor_x;
	    while(num > 0)
	    {
		put_ch('\0');
		num = num - 1;
	    }
	    break;
	case '\n' :
	    // newline
	    cursor_x = IO_CUR_COL;
	    cursor_y = cursor_y + 1;
	    break;
	case '\r' :
	    // return
	    set_cursor_x(IO_CUR_COL);
	    cursor_x = IO_CUR_COL;
	    break;
	default :
	    pos = (cursor_y * SCREEN_WIDTH) + cursor_x; // Calc the new pos
	    screen[pos*2] = c;
	    screen[pos*2+1] = screen_color;
	    cursor_x = cursor_x + 1;
	    break;
    }
    // Make sure we havent passed the wrap
    if(cursor_x >= IO_CUR_WRAP)
    {
	cursor_y = cursor_y + 1;
	cursor_x = IO_CUR_COL;
    }
}

void set_cursor(int x, int y)
{
    set_cursor_x(x);
    set_cursor_y(y);
}
void set_cursor_x(int x)
{
    if(x >= SCREEN_WIDTH)
    {
	cursor_x = 0;
    } else {
	cursor_x = x;
    }
}
void set_cursor_y(int y)
{
    if (y >= SCREEN_HEIGHT)
    {
	y = SCREEN_HEIGHT - 1;
    }
    cursor_y = y;
}

void set_cursor_wrap(int x)
{
    if(x < SCREEN_WIDTH)
    {
	IO_CUR_WRAP = x;
    } else {
	IO_CUR_WRAP = SCREEN_WIDTH;
    }
}

void set_cursor_col(int x)
{
    if(x < SCREEN_WIDTH)
    {
	IO_CUR_COL = x;
    } else {
	IO_CUR_COL = 0;
    }
    set_cursor_x(IO_CUR_COL);
    put_ch('\n');
}

int get_color(void)
{
    return screen_color;
}

int get_cursor_x(void)
{
    return cursor_x;
}

int get_cursor_y(void)
{
    return cursor_y;
}

int get_cursor_wrap(void)
{
    return IO_CUR_WRAP;
}

int get_cursor_col(void)
{
    return IO_CUR_COL;
}

// Clear the screen
void clear_screen(void)
{
    unsigned int i = 0; // Index counter
    // Loop through the memory and write the 
    while(i < screen_limit)
    {
	screen[i*2] = ' '; // Set a space character
	screen[i*2+1] = screen_color; // Set the color
	i = i + 1; // Loop
    }
    return;
}

// Set the color
void set_color(unsigned int color)
{
    screen_color = color;
    return;
}

// Print a string but leave the color the same
void print_string(const char *str, int len)
{
    int i = 0;
    if(len == -1)
    {
	len = strlen(str);
    }
    // Make sure we arnt over writing the screen array
    if(len > VIDEO_MEMORY_LIM)
    {
	len = VIDEO_MEMORY_LIM;
    }
    
    // Print the character keeping the color the same
    while(i < len)
    {
	if(str[i] == '\0')
	{
	    break;
	}
	
	//screen[i*2] = str[i];
	//screen[i*2+1] = screen_color;
	put_ch(str[i]);
	i = i + 1;
    }

    return;
}

int read_input(void);

