#include <iostream>
#include <graphics.h>
using namespace std;

int main() {
    int gd = DETECT, gm;
    float shy;
    
    initgraph(&gd, &gm, NULL); // Ensure the correct BGI path if needed
    
    cout << "Enter the shear factor (shy) along the y-axis: ";
    cin >> shy;
    
    // Original rectangle coordinates
    int x1 = 100, y1 = 10;
    int x2 = 200, y2 = 10;
    int x3 = 200, y3 = 200;
    int x4 = 100, y4 = 200;

    // Draw original rectangle
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x1, y1);

    // Apply Y-shear transformation
    setcolor(WHITE); // Change color for better visibility
    line(x1, y1 + shy * x1, x2, y2 + shy * x2);
    line(x2, y2 + shy * x2, x3, y3 + shy * x3);
    line(x3, y3 + shy * x3, x4, y4 + shy * x4);
    line(x4, y4 + shy * x4, x1, y1 + shy * x1);

    getch();
    closegraph();
    return 0;
}
