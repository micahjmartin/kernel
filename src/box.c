#include "libme.h"

void draw_box(int width, int height, unsigned int color, int shadow)
{
    init_cur();
    int x_start = (SCREEN_WIDTH - width)/2; // Calculate the x start
    int y_start = (SCREEN_HEIGHT - height)/2;
    int x = x_start;
    int y = y_start;
    int i;
    int j;
    // Draw the box
    set_cursor(x,y);
    set_color(color);
    for(j=0;j < height;j++)
    {
	for(i=1;i<width;i++)
	{
	    put_ch('\0');
	    x = x + 1;
	}
	y = y + 1;
	x = x_start;
	set_cursor(x,y);
    }
    // Draw the shadow
    if(shadow != 0)
    {
	set_color(0x8F);
	y = y_start+1;
	set_cursor(x_start+width-1, y);
	for(j=0;j < height;j++)
	{
	    put_ch('\0');
	    set_cursor(x_start+width-1, y++);
	}
	for(j=width-1;j>0;j--)
	{
	    put_ch('\0');
	    set_cursor(j+x_start,y_start+height);
	}
    }
}
