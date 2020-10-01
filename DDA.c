#include <graphics.h>
#include <stdio.h>

void midptellipse(int rx, int ry, int xc, int yc)
{

    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;

    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    while (dx < dy)
    {
        putpixel(x + xc, y + yc, RED);
        putpixel(-x + xc, y + yc, RED);
        putpixel(x + xc, -y + yc, RED);
        putpixel(-x + xc, -y + yc, RED);

        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }

    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);

    while (y >= 0)
    {

        // printing points based on 4-way symmetry
        putpixel(x + xc, y + yc, RED);
        putpixel(-x + xc, y + yc, RED);
        putpixel(x + xc, -y + yc, RED);
        putpixel(-x + xc, -y + yc, RED);

        // Checking and updating parameter
        // value based on algorithm
        if (d2 > 0)
        {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
}

void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    midptellipse(10, 15, 50, 50);
    delay(5000);
    closegraph();
}
