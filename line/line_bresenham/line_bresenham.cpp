#include<graphics.h>
#include<conio.h>
int main()
{
	int gd=0,gm;
	initgraph(&gd,&gm,"");
	int x1=10,y1=15,x2=200,y2=150;
	int dy=y2-y1;
	int dx=x2-x1;
	int p=2*dy-dx;
	int x=x1;
	int y=y1;
	int consts1=2*dy;
	int consts2= 2*dy-2*dx;
	putpixel(x1,y1,4);// ve diem dau 
	while(x<=x2)
	{
		if(p<0)
		{
			p=p+2*dy;//p=p+consts1;
		}
		else //p>=0
		{
			p=p+2*dy-2*dx;//p=p+consts2;
			y=y+1;
		}
		x=x+1;
		putpixel(x,y,4);
	}
	getch();
	return 0;
}

