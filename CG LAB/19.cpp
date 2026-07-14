#include <iostream>
#include <graphics.h>
using namespace std;

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

Point computeIntersection(Point s, Point p, int edge, int xmin, int ymin, int xmax, int ymax) {
    switch(edge) {
        case 0: return Point(xmin, s.y + (p.y - s.y) * (xmin - s.x) / (p.x - s.x));
        case 1: return Point(xmax, s.y + (p.y - s.y) * (xmax - s.x) / (p.x - s.x));
        case 2: return Point(s.x + (p.x - s.x) * (ymin - s.y) / (p.y - s.y), ymin);
        case 3: return Point(s.x + (p.x - s.x) * (ymax - s.y) / (p.y - s.y), ymax);
    }
    return Point();
}

void clipAgainstEdge(Point* inPolygon, int inSize, Point* outPolygon, int& outSize, int edge, int xmin, int ymin, int xmax, int ymax) {
    outSize = 0;
    
    for(int i = 0; i < inSize; i++) {
        Point current = inPolygon[i], nextPoint = inPolygon[(i + 1) % inSize];
        bool currentInside = (edge == 0 ? current.x >= xmin : edge == 1 ? current.x <= xmax : edge == 2 ? current.y >= ymin : current.y <= ymax);
        bool nextInside = (edge == 0 ? nextPoint.x >= xmin : edge == 1 ? nextPoint.x <= xmax : edge == 2 ? nextPoint.y >= ymin : nextPoint.y <= ymax);
        
        if(currentInside && nextInside) {
            outPolygon[outSize++] = nextPoint;
        } else if(currentInside) {
            outPolygon[outSize++] = computeIntersection(current, nextPoint, edge, xmin, ymin, xmax, ymax);
        } else if(nextInside) {
            outPolygon[outSize++] = computeIntersection(current, nextPoint, edge, xmin, ymin, xmax, ymax);
            outPolygon[outSize++] = nextPoint;
        }
    }
}

void sutherlandHodgmanClip(Point* inPolygon, int inSize, Point* outPolygon, int& outSize, int xmin, int ymin, int xmax, int ymax) {
    Point tempPolygon[20];
    int tempSize = inSize;
    
    for(int edge = 0; edge < 4; edge++) {
        copy(inPolygon, inPolygon + tempSize, tempPolygon);
        clipAgainstEdge(tempPolygon, tempSize, outPolygon, outSize, edge, xmin, ymin, xmax, ymax);
        copy(outPolygon, outPolygon + outSize, inPolygon);
        tempSize = outSize;
    }
}

void drawPolygon(Point* polygon, int size, int color) {
    setcolor(color);
    for(int i = 0; i < size; i++) {
        line(polygon[i].x, polygon[i].y, polygon[(i + 1) % size].x, polygon[(i + 1) % size].y);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    
    int xmin = 100, ymin = 100, xmax = 200, ymax = 200;
    Point polygon[] = { {75, 125}, {150, 75}, {225, 125}, {225, 175}, {150, 200}, {75, 175} };
    
    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);
    outtextxy(xmin, ymin - 20, (char*)"Before Clipping");
    drawPolygon(polygon, 6, WHITE);
    
    int xoffset = 200;
    setcolor(WHITE);
    rectangle(xmin + xoffset, ymin, xmax + xoffset, ymax);
    outtextxy(xmin + xoffset, ymin - 20, (char*)"After Clipping");

    Point clippedPolygon[20];
    int clippedSize;
    Point offsetPolygon[10];
    for(int i = 0; i < 6; i++) {
        offsetPolygon[i] = { polygon[i].x + xoffset, polygon[i].y };
    }

    sutherlandHodgmanClip(offsetPolygon, 6, clippedPolygon, clippedSize, xmin + xoffset, ymin, xmax + xoffset, ymax);
    drawPolygon(clippedPolygon, clippedSize, WHITE);
    
    getch();
    closegraph();
    return 0;
}
