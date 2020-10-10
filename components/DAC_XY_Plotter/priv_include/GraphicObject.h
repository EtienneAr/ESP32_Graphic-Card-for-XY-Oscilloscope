#ifndef GRAPHICAL_OBJECT_H
#define GRAPHICAL_OBJECT_H

size_t GO_drawPoint(void* start, int x, int y, int intensity);

size_t GO_drawLine(void* start, int x1, int y1, int x2, int y2, int spacing, int intensity);

size_t GO_drawRect(void* start, int x1, int y1, int x2, int y2, int spacing, int intensity);

size_t GO_drawArc(void* start, int x, int y, float r, float a1, float a2, int spacing, int intensity);

size_t GO_drawLetter_A(void* start, int x, int y, float height, int intensity);
#endif