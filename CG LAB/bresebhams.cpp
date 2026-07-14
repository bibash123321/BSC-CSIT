#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

void bresenhamLine(int x1, int y1, int x2, int y2) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, nullptr);  // Pass nullptr instead of empty string
    
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x = x1, y = y1;

    int x_inc = (x2 > x1) ? 1 : -1;
    int y_inc = (y2 > y1) ? 1 : -1;

    if(dx >= dy) {
        int p = 2 * dy - dx;
        int twoDy = 2 * dy;
        int twoDyMinusDx = 2 * (dy - dx);

        while(x != x2) {
            putpixel(x, y, WHITE);
            x += x_inc;

            if(p < 0) {
                p += twoDy;
            } else {
                y += y_inc;
                p += twoDyMinusDx;
            }
        }
    }
    else {
        int p = 2 * dx - dy;
        int twoDx = 2 * dx;
        int twoDxMinusDy = 2 * (dx - dy);

        while(y != y2) {
            putpixel(x, y, WHITE);
            y += y_inc;

            if(p < 0) {
                p += twoDx;
            } else {
                x += x_inc;
                p += twoDxMinusDy;
            }
        }
    }
    putpixel(x2, y2, WHITE);

    getch();
    closegraph();
}

int main() {
    int x1, y1, x2, y2;

    cout << "Enter the coordinates (x1, y1) of the line: "; 
    cin >>x1>>y1;
    cout << "Enter the coordinates (x2, y2) of the line: ";
    cin >> x2>> y2;

    bresenhamLine(x1, y1, x2, y2);
    return 0;
}
