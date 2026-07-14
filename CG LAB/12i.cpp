#include <graphics.h>
#include <iostream>

using namespace std;

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color, const char* label) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1 - 50, y1 - 10, const_cast<char*>(label));
}

int main() {
    int gd = DETECT, gm;
    int x1 = 200, y1 = 100;
    int x2 = 150, y2 = 200;
    int x3 = 250, y3 = 200;

    initgraph(&gd, &gm, nullptr);
    cleardevice();

    // Draw coordinate axes
    line(320, 0, 320, 480);  // Y axis
    line(0, 240, 640, 240);  // X axis

    // Draw original triangle
    drawTriangle(x1 + 320, 240 - y1, x2 + 320, 240 - y2, x3 + 320, 240 - y3, WHITE, "Original");

    // Reflect across X axis
    y1 = -y1;
    y2 = -y2;
    y3 = -y3;

    // Draw reflected triangle
    drawTriangle(x1 + 320, 240 - y1, x2 + 320, 240 - y2, x3 + 320, 240 - y3, WHITE, "Reflected");

    getch();
    closegraph();

    return 0;
}
