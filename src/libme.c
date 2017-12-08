/*
 * Core functions for the kernel
 * Micah Martin (knif3)
 */

#include "libme.h"

// Global Variables for printing
int cursor_x = 0;
int cursor_y = 0;
unsigned int screen_color = 0x07;
char *screen = (char*)VIDEO_MEMORY; // Start of the video array
unsigned int screen_limit = VIDEO_MEMORY_LIM; // Max indexes for the Vidmem

void put_ch(char c)
{
    int pos = 0;
    switch(c)
    {
	case 0x08 :
	    // Backspace
	    if(cursor_x != 0)
		cursor_x = cursor_x - 1;
	    break; 
	case 0x09 :
	    // Backspace
	    cursor_x = (cursor_x + 8) & ~(8 - 1); // Tab only till the next 8
	    break;
	case '\n' :
	    // newline
	    cursor_x = 0;
	    cursor_y = cursor_y + 1;
	    break;
	case '\r' :
	    // return
	    cursor_x = 0;
	    break;
	default :
	    pos = (cursor_y * SCREEN_WIDTH) + cursor_x; // Calc the new pos
	    screen[pos*2] = c;
	    screen[pos*2+1] = screen_color;
	    cursor_x = cursor_x + 1;
	    break;
    }
    // Make sure we havent passed 80
    if(cursor_x >= SCREEN_WIDTH)
    {
	cursor_y = cursor_y + 1;
	cursor_x = 0;
    }
}


// Clear the screen with a given color
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

// Set the screen with a given color
void color_screen(unsigned int color)
{
    screen_color = color;
    clear_screen();
    return;
}

// Print a string but leave the color the same
void print_string(const char *str, int len)
{
    int i = 0;
    // Make sure we arnt over writing the screen array
    /*if(len > VIDEO_MEMORY_LIM)
    {
	len = VIDEO_MEMORY_LIM;
    }
    */
    // Print the character keeping the color the same
    while(i < len)
    {
	/*if(str[i] == '\0')
	{
	    break;
	}
	*/
	put_ch(str[i]);
	i = i + 1;
    }

    return;
}

int read_input(void);

