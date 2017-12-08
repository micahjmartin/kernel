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
    const char *welcome = "Welcome to Micahs Kernel";
    set_color(0x4F);
    clear_screen();
    print_string(welcome, -1);
    print_string("1\t2\t3\t4\t5\t6\t7\t8\t9\t0\t1", -1);
    return;
}
