#include "libme.h"
#include "box.h"

#define WINDOW_BORDER 0x4F
#define WINDOW_BG 0xCF


void box_set_cursor_bounds(int width, int height)
{
    // If x or y is -1, assume that we want the box centered
    int start = (SCREEN_WIDTH - width)/2; // Calculate the x start
    set_cursor_col(start);
    set_cursor_wrap(start+width-1);
    int x = start;
    int y = (SCREEN_HEIGHT - height)/2 + 1; // Calculate the x start
    set_cursor(x,y);
}

void draw_window(void)
{
    int width = 50;
    int height = 15;
    draw_box_raw(-1, -1, width, height, WINDOW_BORDER, 1);
    draw_box_raw(-1, -1, width-4, height-2, WINDOW_BG, 0);
    box_set_cursor_bounds(width-6, height-4);
}

void draw_box_raw(int x, int y, int width, int height, unsigned int color, int shadow)
{
    // Setup vars
    init_cur();
    int x_start = x;
    int y_start = y;
    set_color(color);
    // If x or y is -1, assume that we want the box centered
    if(x < 0)
    {
        x_start = (SCREEN_WIDTH - width)/2; // Calculate the x start
        x = x_start;
    }
    if(y < 0)
    {
        y_start = ((SCREEN_HEIGHT - height)/2)-1; // Calculate the y start
        y = y_start;
    }
    set_cursor(x,y);
    // Draw the box
    int i;
    int j;
    // Loop through every 'pixel' in the box and draw the bg color and clear overtop
    for(j=0;j<height;j++)
    {
        for(i=1;i<width;i++)
        {
            put_ch('\0'); // Put nothing there, but this will draw whatever color is set
            x = x + 1; // Increment
        }
        y = y + 1; // After each line, increment the y
        x = x_start; // Move the x back to the start
        set_cursor(x,y); // Set the cursor
    }
    // Draw the shadow if specified
    if(shadow != 0)
    {
        set_color(0x8F);
        y = y_start+1;
        set_cursor(x_start+width-1, y);
        // Draw the vertical line
        for(j=0;j < height;j++)
        {
            put_ch('\0');
            set_cursor(x_start+width-1, y++);
        }
        // Draw the horizontal ine
        x = x_start + 1;
        set_cursor(x,y_start+height);
        for(j=0;j<width;j++)
        {
            put_ch('\0');
            set_cursor(x++,y_start+height);
        }
    }
}


void box_debug(int x, int y, int x_start, int y_start)
{
    
    char str[6] = "\0\0\0\0\0\0";
    unsigned int tmp_color = get_color();
    set_color(0x9F);
    int tmp_x = get_cursor_x();
    int tmp_y = get_cursor_y();
    int tmp_wrap = get_cursor_wrap();
    int tmp_col = get_cursor_col();

    set_cursor_col(0);
    set_cursor_wrap(SCREEN_WIDTH);
    set_cursor(0,0);
    
    print_string("Current X,Y: ",-1);
    itoc(x, str);
    print_string(str,-1);
    
    print_string(", ",1);
    itoc(y, str);
    print_string(str,-1);
    
    print_string("\nSTART X,Y: ",-1);
    itoc(x_start, str);
    print_string(str,-1);
    print_string(", ",-1);
    itoc(y_start, str);
    print_string(str,-1);

    set_color(tmp_color);
    set_cursor_col(tmp_col);
    set_cursor_wrap(tmp_wrap);
    set_cursor(tmp_x, tmp_y);
}
