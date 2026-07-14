#include <iostream>
#include <graphics.h>
using namespace std;

int main() {
    int gd = DETECT, gm;
    float shx;
    
    initgraph(&gd, &gm,NULL); // Ensure the correct BGI path if needed
    
    cout << "Enter the shear factor (shx) along the x-axis: ";
    cin >> shx;
    
    // Original rectangle coordinates
    int x1 = 100, y1 = 0;
    int x2 = 200, y2 = 0;
    int x3 = 200, y3 = 200;
    int x4 = 100, y4 = 200;

    // Draw original rectangle
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x1, y1);

    // Apply X-shear transformation
    setcolor(WHITE); // Change color for better visibility
    line(x1 + shx * y1, y1, x2 + shx * y2, y2);
    line(x2 + shx * y2, y2, x3 + shx * y3, y3);
    line(x3 + shx * y3, y3, x4 + shx * y4, y4);
    line(x4 + shx * y4, y4, x1 + shx * y1, y1);

    getch();
    closegraph();
    return 0;
}
