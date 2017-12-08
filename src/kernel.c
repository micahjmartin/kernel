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
    const char *welcome = " ";
    clear_screen(0x09);
    char t[15];
    //itoc(123456789, (char*)t);
    print_string((const char*)t,4);
    return;
}
