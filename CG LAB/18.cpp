#include <iostream>
#include <graphics.h>
using namespace std;

void liangBarskyClip(double x1, double y1, double x2, double y2,
                    double xmin, double ymin, double xmax, double ymax) {
    double dx = x2 - x1, dy = y2 - y1;
    double p[4] = {-dx, dx, -dy, dy};
    double q[4] = {x1 - xmin, xmax - x1, y1 - ymin, ymax - y1};
    double t1 = 0.0, t2 = 1.0;

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0) {
            if (q[i] < 0) return; // Line parallel and outside
        } else {
            double t = q[i] / p[i];
            if (p[i] < 0) t1 = max(t1, t);
            else t2 = min(t2, t);
        }
    }

    if (t1 > t2) return; // Line completely outside

    // Calculate clipped points
    double nx1 = x1 + t1 * dx, ny1 = y1 + t1 * dy;
    double nx2 = x1 + t2 * dx, ny2 = y1 + t2 * dy;

    // Draw clipped line
    setcolor(WHITE);
    line(nx1, ny1, nx2, ny2);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    
    double xmin = 100, ymin = 100, xmax = 250, ymax = 250;
    int xoffset = 50;

    // Draw first clipping window and original line
    setcolor(WHITE);
    rectangle(xmin + xoffset, ymin, xmax + xoffset, ymax);
    outtextxy(xmin + xoffset, ymin - 20, (char*)"Before Clipping");
    line(75 + xoffset, 200, 300 + xoffset, 75);  // Original line

    // Second viewport - Clipped line
    xoffset = 300;
    rectangle(xmin + xoffset, ymin, xmax + xoffset, ymax);
    outtextxy(xmin + xoffset, ymin - 20, (char*)"After Clipping");
    liangBarskyClip(75 + xoffset, 200, 300 + xoffset, 75, xmin + xoffset, ymin, xmax + xoffset, ymax);

    getch();
    closegraph();
    return 0;
}
