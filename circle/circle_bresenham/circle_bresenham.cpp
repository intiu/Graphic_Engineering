#include<graphics.h>
#include<conio.h>
#include<iostream>
using namespace std;
void ve8diem(int x, int y, int xc, int yc, int mauve)
{
	putpixel(x+xc,y+yc,mauve);
	putpixel(y+xc,x+yc,mauve);
	putpixel(y+xc,-x+yc,mauve);
	putpixel(x+xc,-y+yc,mauve);
	putpixel(-x+xc,-y+yc,mauve);
	putpixel(-y+xc,-x+yc,mauve);
	putpixel(-y+xc,x+yc,mauve);
	putpixel(-x+xc,y+yc,mauve);
}
void veduongtron(int x, int y, int r)
{
	int p=3-2*r;
	while(x<=y)
	{
		ve8diem(x,y,100,80,4);
		x++;
		if(p<0)
		{
			p=p+4*x+6;
		}
		else
		{
			y--;
			p=p+4*(x-y)+10;
		}
	}
}
int main()
{
	initwindow(500,500);
	int x=0,y=20,r=20;
	veduongtron(x,y,r);
	getch();
	return 0;
}

