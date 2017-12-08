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
    set_color(0x9F);
    clear_screen();
    print_string("Welcome to Micahs Kernel\n", -1);
    draw_box(40, 19, 0x4F, 1);
    draw_box(36, 17, 0xCF, 0);
    return;
}
