#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

int x1, z1, x2, z2, mx, my, depth;

void drawsquare(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy) {
    line(ax, ay, bx, by);
    line(bx, by, cx, cy); 
    line(cx, cy, dx, dy);
    line(dx, dy, ax, ay);
}

void rotateSquare() {
    double angle;
    float t;
    cout << "Enter the angle of rotation: ";
    cin >> angle;
    t = angle * M_PI / 180;
    
    double ax = x1, ay = z1;
    double bx = x2, by = z1;
    double cx = x2, cy = z2;
    double dx = x1, dy = z2;
    
    double new_ax = mx + (ax-mx)*cos(t) - (ay-my)*sin(t);
    double new_ay = my + (ax-mx)*sin(t) + (ay-my)*cos(t);
    double new_bx = mx + (bx-mx)*cos(t) - (by-my)*sin(t);
    double new_by = my + (bx-mx)*sin(t) + (by-my)*cos(t);
    double new_cx = mx + (cx-mx)*cos(t) - (cy-my)*sin(t);
    double new_cy = my + (cx-mx)*sin(t) + (cy-my)*cos(t);
    double new_dx = mx + (dx-mx)*cos(t) - (dy-my)*sin(t);
    double new_dy = my + (dx-mx)*sin(t) + (dy-my)*cos(t);
    
    cleardevice();
    drawsquare(new_ax, new_ay, new_bx, new_by, new_cx, new_cy, new_dx, new_dy);
    outtextxy(new_ax+50, new_ay-15, (char*)"Rotated Image");
    drawsquare(ax, ay, bx, by, cx, cy, dx, dy);
    outtextxy(ax+50, ay-15, (char*)"Original Image");
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    
    cout << "Enter top-left coordinates(x1,z1): ";
    cin >> x1 >> z1;
    cout << "Enter bottom-right coordinates(x2,z2): ";
    cin >> x2 >> z2;
    
    depth = (x2-x1)/4;
    mx = (x1+x2)/2;
    my = (z1+z2)/2;
    
    rotateSquare();
    
    getch();
    closegraph();
    return 0;
}