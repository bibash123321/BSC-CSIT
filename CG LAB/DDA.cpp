#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

void drawLineDDA(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    int steps = max(abs(dx), abs(dy));
    float Xinc = dx / steps;
    float Yinc = dy / steps;
    float x = x1, y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += Xinc;
        y += Yinc;
        delay(10);
    }
}

int main() {
    float x1, y1, x2, y2;
    cout << "Enter the starting point (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter the ending point (x2, y2): ";
    cin >> x2 >> y2;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    drawLineDDA(x1, y1, x2, y2);

    getch();
    closegraph();

    return 0;
}
