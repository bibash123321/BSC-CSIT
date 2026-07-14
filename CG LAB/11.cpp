#include <graphics.h>
#include <iostream>

using namespace std;

void drawPolygon(int x[], int y[], int n, int color, const char* label) {
    setcolor(color);
    for (int i = 0; i < n - 1; i++) {
        line(x[i], y[i], x[i + 1], y[i + 1]);
    }
    line(x[n - 1], y[n - 1], x[0], y[0]);
    outtextxy(x[0], y[0] - 10, const_cast<char*>(label));
}

void scale2D(int x[], int y[], int n, float sx, float sy) {
    for (int i = 0; i < n; i++) {
        x[i] = static_cast<int>(x[i] * sx);
        y[i] = static_cast<int>(y[i] * sy);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, nullptr);

    int x[] = {150, 300, 300, 150};
    int y[] = {150, 150, 300, 300};
    int n = 4;
    int x_scaled[4], y_scaled[4];
    float sx, sy;

    cout << "Enter scaling factors (sx sy): ";
    cin >> sx >> sy;

    for (int i = 0; i < n; i++) {
        x_scaled[i] = x[i];
        y_scaled[i] = y[i];
    }

    drawPolygon(x, y, n, WHITE, "Original");
    scale2D(x_scaled, y_scaled, n, sx, sy);
    drawPolygon(x_scaled, y_scaled, n, WHITE, "Scaled");

    getch();
    closegraph();
    return 0;
}
