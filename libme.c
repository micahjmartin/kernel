/*
 * Core functions for the kernel
 * Micah Martin (knif3)
 */

#include "libme.h"

// Clear the screen with a given color
void clear_screen(unsigned int color)
{
    unsigned int i = 0; // Index counter
    char *screen = (char*)VIDEO_MEMORY; // Start of the video array
    unsigned int screen_limit = VIDEO_MEMORY_LIM; // Max indexes for the Vidmem
    // Loop through the memory and write the 
    while(i < screen_limit)
    {
	screen[i*2] = ' '; // Set a space character
	screen[i*2+1] = color; // Set the color
	i = i + 1; // Loop
    }

    return;
}

// Set the screen with a given color
void color_screen(unsigned int color)
{
    unsigned int i = 0; // Index counter
    char *screen = (char*)VIDEO_MEMORY; // Start of the video array
    unsigned int screen_limit = VIDEO_MEMORY_LIM; // Max indexes for the Vidmem
    // Loop through the memory and write the 
    while(i < screen_limit)
    {
	screen[i*2+1] = color; // Set the color
	i = i + 1; // Loop
    }

    return;
}

// Print a string but leave the color the same
void print_string(const char *str, unsigned int len)
{
    unsigned int i = 0;
    char *screen = (char*)VIDEO_MEMORY; // Start of the video array
    // Make sure we arnt over writing the screen array
    if(len > VIDEO_MEMORY_LIM)
    {
	len = VIDEO_MEMORY_LEN;
    }
    // Print the character keeping the color the same
    while(i < len)
    {
	screen[i*2] = str[i];
	i = i + 1;
    }

    return;
}

int read_input(void);

