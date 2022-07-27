#include<iostream>
#include<winbgim.h>
#include<math.h>
using namespace std;
 
void midpoint(int x1,int y1,int x2, int y2,int color){
    //Truong hop 0<m<1 && x1<x2 && y1<y2
    int a,b,pi,x,y,p;
    a=y2-y1;
    b=-(x2-x1);
    y=y1;
    x=x1;
    putpixel(x,y,color);    //Ve diem pixel dau tien
    p=2*a+b;        //tinh vi tri tuong doi cua diem Midpoint so voi duong thang
    while(x < x2){
        if(p < 0){   
            p+=2*a; // ta chon chon diem yi
        }else{      
            y++;
            p+=2*(a+b);//ta chon diem yi +1
        }
        x++;
        cout<<"Pixel (x,y) midpoint = ("<<x<<", "<<y<<")\n";
        putpixel(x,y,color);
        delay(10);
    }
}
 
 
int main(){
    initwindow(800,600);
    //khoi tao window có chieu rong x=400 và chieu cao y = 500
    setwindowtitle("Thuat toan Line Midpoint");  
      //thiet   lap tieu    de  cho windows
    midpoint(10,10,400,400,15);
    getch();
}

