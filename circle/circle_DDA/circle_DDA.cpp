#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
void drawcircle(int x0, int y0, int radius)
{
    int x = radius;
    int y = 0;
    int err = 0;
 
    while (x >= y)
    {
	putpixel(x0 + x, y0 + y, 4);
	putpixel(x0 + y, y0 + x, 4);
	putpixel(x0 - y, y0 + x, 4);
	putpixel(x0 - x, y0 + y, 4);
	putpixel(x0 - x, y0 - y, 4);
	putpixel(x0 - y, y0 - x, 4);
	putpixel(x0 + y, y0 - x, 4);
	putpixel(x0 + x, y0 - y, 4);
 
	if (err <= 0)
	{
	    y += 1;
	    err += 2*y + 1;
	}
 
	if (err > 0)
	{
	    x -= 1;
	    err -= 2*x + 1;
	}
    }
}
 
int main()
{
	int gdriver=DETECT, gmode, error, x, y, r;
	initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
 
	cout<<"nhap ban kinh hinh tron: ";
	cin>>r;
 
	cout<<"nhap toa do(x va y): ";
	cin>>x>>y;
	drawcircle(x, y, r);
    getch();
	return 0;
}

