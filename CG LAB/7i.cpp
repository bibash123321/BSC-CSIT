#include <graphics.h>
#include <iostream>

void floodFill4(int x, int y, int fillColor, int boundaryColor) {
    int currentColor = getpixel(x, y);
    if (currentColor != boundaryColor && currentColor != fillColor) {
        putpixel(x, y, fillColor);
        floodFill4(x + 1, y, fillColor, boundaryColor); // right
        floodFill4(x - 1, y, fillColor, boundaryColor); // left
        floodFill4(x, y + 1, fillColor, boundaryColor); // down
        floodFill4(x, y - 1, fillColor, boundaryColor); // up
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, nullptr);

    // Define hexagon vertices
    int xl = 100, yl = 150;
    int x2 = 180, y2 = 120;
    int x3 = 260, y3 = 150;
    int x4 = 260, y4 = 230;
    int x5 = 180, y5 = 260;
    int x6 = 100, y6 = 230;

    // Draw hexagon
    line(xl, yl, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x5, y5);
    line(x5, y5, x6, y6);
    line(x6, y6, xl, yl);

    int fillColor = RED;      // Fill color
    int boundaryColor = WHITE;  // Boundary color (lines should be drawn in white)

    // Start filling from the centroid of the hexagon
    int fillX = (xl + x2 + x3 + x4 + x5 + x6) / 6;
    int fillY = (yl + y2 + y3 + y4 + y5 + y6) / 6;
    floodFill4(fillX, fillY, fillColor, boundaryColor);

    getch();
    closegraph();

    return 0;
}
