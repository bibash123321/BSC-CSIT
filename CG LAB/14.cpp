#include <iostream>
#include <graphics.h>
using namespace std;

int x1,x2,y1,y2,mx,my,depth;

void draw(){
    bar3d(x1,y1,x2,y2,depth,0);
    outtextxy(x1+50,y1-15,(char*)"Object");
}

void trans(){
    int a1,a2,b1,b2,dep;
    int tx,ty;
    cout << "Enter the translation distance(tx,ty): ";
    cin >> tx >> ty;
    a1=x1+tx;
    a2=x2+tx;
    b1=y1+ty;
    b2=y2+ty;
    dep = (a2-a1)/4;
    bar3d(a1,b1,a2,b2,dep,1);
    outtextxy(a1+50,b1-15,(char*)"Image");
    draw();
}

int main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    cout << "Enter top-left coordinates(x1,y1): ";
    cin >> x1 >> y1;
    cout << "Enter bottom-right coordinates(x2,y2): ";
    cin >> x2 >> y2;
    depth = (x2-x1)/4;
    mx = (x1+x2)/2;
    my = (y1+y2)/2;
    trans();
    getch();
    closegraph();
    return 0;
}