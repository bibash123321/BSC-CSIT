#include<stdio.h>
#include<graphics.h>
void drawtraingle(int x1, int y1, int x2, int y2, int x3, int y3){
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}
void translate(int *x1,int *y1,int *x2,int *y2,int *x3,int *y3,int tx,int ty){
    *x1 += tx;
    *y1 += ty;
    *x2 += tx;
    *y2 += ty;
    *x3 += tx;
    *y3 += ty;
}
int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int x1 = 100, y1 = 100, x2 = 200, y2 = 100, x3 = 150, y3 = 200;
    drawtraingle(x1, y1, x2, y2, x3, y3);
    translate(&x1, &y1, &x2, &y2, &x3, &y3, 100, 100);
    drawtraingle(x1, y1, x2, y2, x3, y3);
    getch();
    closegraph();
    return 0;
}
