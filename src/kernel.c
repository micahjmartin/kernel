/*
 * Our simple kernel to print and read input
 * Micah Martin (knif3)
 */


#include "kernel.h"
#include "libme.h"

// Set the screen start
#define VIDEO_MEMORY 0xb8000


void kernel_main(void)
{
    const char *welcome = "Welcome to Micah's kernel";
    clear_screen(WHITE_BLACK);
    print_string(welcome, 25);
    return;
}
