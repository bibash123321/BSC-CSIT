#include <iostream>
#include <graphics.h>

using namespace std;

void drawCircle(int xc, int yc, int r) {
    int gd = DETECT, gm;
    char driver[] = "";  
    initgraph(&gd, &gm, driver);
    
    int x = 0;
    int y = r;
    int p = 1 - r;  // Initial decision parameter
    
    // Plot initial points in all octants
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc - y, yc - x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    
    while (x < y) {
        x++;
        
        if (p < 0)
            p += 2 * x + 1;
        else {
            y--;
            p += 2 * (x - y) + 1;
        }
        
        // Plot points in all octants
        putpixel(xc + x, yc + y, WHITE);  // Octant 1
        putpixel(xc + y, yc + x, WHITE);  // Octant 2
        putpixel(xc - y, yc + x, WHITE);  // Octant 3
        putpixel(xc - x, yc + y, WHITE);  // Octant 4
        putpixel(xc - x, yc - y, WHITE);  // Octant 5
        putpixel(xc - y, yc - x, WHITE);  // Octant 6
        putpixel(xc + y, yc - x, WHITE);  // Octant 7
        putpixel(xc + x, yc - y, WHITE);  // Octant 8
    }
    
    getch();
    closegraph();
}

int main() {
    int xc, yc, r;
    
    cout << "Enter the center coordinates (xc, yc) and radius (r) of the circle:\n";
    cout << "xc: ";
    cin >> xc;
    cout << "yc: ";
    cin >> yc;
    cout << "Radius (r): ";
    cin >> r;
    
    drawCircle(xc, yc, r);
    return 0;
}
