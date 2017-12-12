/*
 * Our simple kernel to print and read input
 * Micah Martin (knif3)
 */

#include "kernel.h"
#include "libme.h"
#include "string.h"
#include "box.h"

#define BOX_BORDER 0x4F
#define BOX_BG 0xCF

void kernel_main(void)
{
    unsigned int main_bg = 0x9F;
    set_color(main_bg);
    clear_screen();

    draw_window();

    //set_color(0x9F);
    print_string("0123456789", -1);
    print_string("0123456789", -1);
    print_string("0123456789", -1);
    print_string("0123456789", -1);
    print_string("0123456789", -1);
    print_string("0123456789", -1);
    print_string("0123456789", -1);
    print_string("0123456789", -1);
    print_string("0123456789", -1);
    print_string("0123456789", -1);
    print_string("0123456789", -1);
    print_string("0123456789", -1);
    print_string("0123456789", -1);
    print_string("0123456789", -1);
    print_string("Welcome to Micahs Kernel\n", -1);
    print_string("Welcome to Micahs Kernel\n", -1);
    return;
}
