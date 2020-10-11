#ifndef GRAPHICAL_OBJECT_H
#define GRAPHICAL_OBJECT_H

#include <string.h>
#include <stdio.h>

#include <stdlib.h>
#define SAFE_WRITE(tab, pos, data) if(tab != NULL) { tab[pos] = data; }
#define SAFE_PTR(start, offset) (start == NULL ? NULL : start+offset)

size_t GO_drawPoint(void* start, float x, float y, int intensity);

size_t GO_drawLine(void* start, float x1, float y1, float x2, float y2, float spacing, int intensity);

size_t GO_drawRect(void* start, float x1, float y1, float x2, float y2, float spacing, int intensity);

size_t GO_drawArc(void* start, float x, float y, float r, float a1, float a2, float spacing, int intensity);

size_t GO_drawChar(void* start, char c, float x, float y, float height, int intensity);

size_t GO_drawString(void* start, const char* str, float x, float y, float height, int intensity);
#endif