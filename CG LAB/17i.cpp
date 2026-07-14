#include <iostream>
#include <graphics.h>
using namespace std;

const int INSIDE = 0, LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;

int computeCode(double x, double y, double xmin, double ymin, double xmax, double ymax) {
    int code = INSIDE;
    if (x < xmin) code |= LEFT;
    else if (x > xmax) code |= RIGHT;
    if (y < ymin) code |= BOTTOM;
    else if (y > ymax) code |= TOP;
    return code;
}

void cohenSutherlandClip(double x1, double y1, double x2, double y2, double xmin, double ymin, double xmax, double ymax) {
    int code1 = computeCode(x1, y1, xmin, ymin, xmax, ymax), code2 = computeCode(x2, y2, xmin, ymin, xmax, ymax);
    bool accept = false;

    while (true) {
        if (code1 == 0 && code2 == 0) { accept = true; break; }
        else if (code1 & code2) break;

        double x, y;
        int codeOut = code1 ? code1 : code2;

        if (codeOut & TOP) { x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1); y = ymax; }
        else if (codeOut & BOTTOM) { x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1); y = ymin; }
        else if (codeOut & RIGHT) { y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1); x = xmax; }
        else { y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1); x = xmin; }

        if (codeOut == code1) { x1 = x; y1 = y; code1 = computeCode(x1, y1, xmin, ymin, xmax, ymax); }
        else { x2 = x; y2 = y; code2 = computeCode(x2, y2, xmin, ymin, xmax, ymax); }
    }

    if (accept) {
        setcolor(WHITE);
        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    double xmin = 100, ymin = 100, xmax = 250, ymax = 250;
    int xoffset = 50;  

    setcolor(WHITE);
    rectangle(xmin + xoffset, ymin, xmax + xoffset, ymax);
    outtextxy(xmin + xoffset, ymin - 20, (char*)"Before Clipping");
    line(50 + xoffset, 50, 200 + xoffset, 200);

    xoffset = 300;  
    setcolor(WHITE);
    rectangle(xmin + xoffset, ymin, xmax + xoffset, ymax);
    outtextxy(xmin + xoffset, ymin - 20, (char*)"After Clipping");
    cohenSutherlandClip(50 + xoffset, 50, 200 + xoffset, 200, xmin + xoffset, ymin, xmax + xoffset, ymax);

    getch();
    closegraph();
    return 0;
}
