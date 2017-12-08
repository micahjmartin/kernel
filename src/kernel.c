/*
 * Our simple kernel to print and read input
 * Micah Martin (knif3)
 */

#include "kernel.h"
#include "libme.h"
#include "string.h"

// Set the screen start
#define VIDEO_MEMORY 0xb8000


void kernel_main(void)
{
    const char *welcome = "hello worlds!!!";
    color_screen(0x07);
    print_string(welcome,15);
    set_color(0x09);
    print_string("\nwel\tcome to narnia",-1);
    print_string("\nwe\tcome to narnia",-1);
    print_string("\nwedfl\tcome to narnia",-1);
    print_string("\nwdel\tcome to narnia",-1);
    return;
}
