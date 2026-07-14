#include <graphics.h>
#include <iostream>

void floodFill8(int x, int y, int fillColor, int boundaryColor) {
    int currentColor = getpixel(x, y);
    if (currentColor != boundaryColor && currentColor != fillColor) {
        putpixel(x, y, fillColor);
        floodFill8(x + 1, y, fillColor, boundaryColor);  // right
        floodFill8(x - 1, y, fillColor, boundaryColor);  // left
        floodFill8(x, y + 1, fillColor, boundaryColor);  // down
        floodFill8(x, y - 1, fillColor, boundaryColor);  // up
        floodFill8(x + 1, y + 1, fillColor, boundaryColor);  // diagonal right-down
        floodFill8(x - 1, y - 1, fillColor, boundaryColor);  // diagonal left-up
        floodFill8(x - 1, y + 1, fillColor, boundaryColor);  // diagonal left-down
        floodFill8(x + 1, y - 1, fillColor, boundaryColor);  // diagonal right-up
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, nullptr);

    // Define hexagon vertices
    int x1 = 150, yl = 100;
    int x2 = 200, y2 = 100;
    int x3 = 225, y3 = 150;
    int x4 = 200, y4 = 200;
    int x5 = 150, y5 = 200;
    int x6 = 125, y6 = 150;

    // Draw hexagon
    line(x1, yl, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x5, y5);
    line(x5, y5, x6, y6);
    line(x6, y6, x1, yl);

    int fillColor = RED;       // Fill color
    int boundaryColor = WHITE; // Boundary color

    // Start filling from the centroid of the hexagon
    int fillX = (x1 + x2 + x3 + x4 + x5 + x6) / 6;
    int fillY = (yl + y2 + y3 + y4 + y5 + y6) / 6;
    floodFill8(fillX, fillY, fillColor, boundaryColor);

    getch();
    closegraph();
    return 0;
}
