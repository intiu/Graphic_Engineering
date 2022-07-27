#include<graphics.h>
#include<conio.h>
int Round(float y)
{
	return y+0.5;
}
int main()
{
	int grapdriver=0,gmode;
	initgraph(&grapdriver,&gmode,"");
	int x1=0,x2=100,y1=0,y2=150;
	float m=(float)(y2-y1)/(x2-x1);
	float y=y1;
	int x=x1;
	while(x<=x2)
	{
		y=y+m;
		putpixel(x,Round(y),4);
		x++; 
	}
	getch();
	closegraph();
}

