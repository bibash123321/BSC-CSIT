#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color, const char* label) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1, y1 - 10, const_cast<char*>(label));
}

void rotatePoint(int& x, int& y, float theta) {
    float rad = theta * (M_PI / 180.0);
    
    int newX = x * cos(rad) - y * sin(rad);
    int newY = x * sin(rad) + y * cos(rad);
    
    x = newX;
    y = newY;
}

int main() {
    int gd = DETECT, gm;
    
    int x1 = 200, y1 = 100;
    int x2 = 150, y2 = 200;
    int x3 = 250, y3 = 200;
    
    float theta;

    cout << "Enter the angle of rotation (in degrees): ";
    cin >> theta;

    initgraph(&gd, &gm, nullptr);
    cleardevice();

    drawTriangle(x1, y1, x2, y2, x3, y3, WHITE, "Original");

    rotatePoint(x1, y1, theta);
    rotatePoint(x2, y2, theta);
    rotatePoint(x3, y3, theta);

    drawTriangle(x1, y1, x2, y2, x3, y3, WHITE, "Rotated");

    getch();
    closegraph();

    return 0;
}
