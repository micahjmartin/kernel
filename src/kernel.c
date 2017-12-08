/*
 * Our simple kernel to print and read input
 * Micah Martin (knif3)
 */

#include "kernel.h"
#include "libme.h"
#include "string.h"
#include "box.h"

#define C_White_Black 0x0F
#define C_White_Red 0x4F

void kernel_main(void)
{
    unsigned int main_bg = 0x9F;
    set_color(main_bg);
    clear_screen(); 
    draw_box(40, 20, 0x4F, 1);
    draw_box(36, 18, 0xCF, 0);
    set_cursor(40,7);
    //set_color(0x9F);
    set_cursor_col(20);
    set_cursor_wrap(59);
    cur_debug(main_bg); 
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
