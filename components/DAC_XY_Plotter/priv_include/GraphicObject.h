#ifndef GRAPHICAL_OBJECT_H
#define GRAPHICAL_OBJECT_H

void GO_drawPoint(void* start, int x, int y, int intensisty);
int  GO_drawPoint_len        ( int x, int y, int intensisty);

void GO_drawLine(void* start, int x1, int y1, int x2, int y2, int spacing, int intensisty);
int  GO_drawLine_len        ( int x1, int y1, int x2, int y2, int spacing, int intensisty);

/*
void GO_drawRect(void* start, int x1, int y1, int x2, int y2, Pen_t pen);
int  GO_drawRect_len        ( int x1, int y1, int x2, int y2, Pen_t pen);

void GO_drawArc(void* start, int x, int y, float r, float a1, float a2, Pen_t pen);
int  GO_drawArc_len        ( int x, int y, float r, float a1, float a2, Pen_t pen);
*/
#endif