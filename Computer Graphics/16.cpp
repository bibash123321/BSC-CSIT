#include <iostream>
#include <graphics.h>

void windowToViewport(float xw, float yw, 
                    float xwmin, float xwmax, float ywmin, float ywmax,
                    float xvmin, float xvmax, float yvmin, float yvmax,
                      float *xv, float *yv) {
    *xv = ((xw - xwmin) / (xwmax - xwmin)) * (xvmax - xvmin) + xvmin;
    *yv = ((yw - ywmin) / (ywmax - ywmin)) * (yvmax - yvmin) + yvmin;
}

void viewportToWindow(float xv, float yv, 
                    float xvmin, float xvmax, float yvmin, float yvmax,
                    float xwmin, float xwmax, float ywmin, float ywmax,
                      float *xw, float *yw) {
    *xw = ((xv - xvmin) / (xvmax - xvmin)) * (xwmax - xwmin) + xwmin;
    *yw = ((yv - yvmin) / (yvmax - yvmin)) * (ywmax - ywmin) + ywmin;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    float xw_min = 10, xw_max = 100, yw_min = 10, yw_max = 100;
    float xv_min = 200, xv_max = 400, yv_min = 200, yv_max = 400;

    float xw = 20, yw = 30, xv, yv;

    rectangle(xv_min, yv_min, xv_max, yv_max);
    outtextxy(xv_min + 50, yv_min - 15, (char*)"Window");
    
    rectangle(xw_min, yw_min, xw_max, yw_max);
    outtextxy(xw_min + 50, yw_min - 15, (char*)"Viewport");

    windowToViewport(xw, yw, xw_min, xw_max, yw_min, yw_max, xv_min, xv_max, yv_min, yv_max, &xv, &yv);
    line(xv_min, yv_min, xv_max, yv_max);

    viewportToWindow(xv, yv, xv_min, xv_max, yv_min, yv_max, xw_min, xw_max, yw_min, yw_max, &xw, &yw);
    line(xw_min, yw_min, xw_max, yw_max);

    getch();
    closegraph();
    
    return 0;
}
