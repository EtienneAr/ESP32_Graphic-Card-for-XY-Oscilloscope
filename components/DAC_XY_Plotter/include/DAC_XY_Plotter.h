#ifndef DAC_XY_PLOTTER
#define DAC_XY_PLOTTER

#include <stdbool.h>

typedef struct Pen {
	float spacing;
	int intensity;
} Pen_t;

typedef void* GI_uid_t;

void XYPlotter_init(int rate);

void XYPlotter_move(GI_uid_t, int dx, int dy);
void XYPlotter_setVisibility(GI_uid_t uid, bool isVisible);
void XYPlotter_delete(GI_uid_t uid);

void XYPlotter_clearScreen();

GI_uid_t XYPlotter_drawPoint(float x, float y, Pen_t pen);
GI_uid_t XYPlotter_drawLine(float x1, float y1, float x2, float y2, Pen_t pen);
GI_uid_t XYPlotter_drawRect(float x1, float y1, float x2, float y2, Pen_t pen);
GI_uid_t XYPlotter_drawArc(float x, float y, float r, float a1, float a2, Pen_t pen);
GI_uid_t XYPlotter_drawChar(char c, float x, float y, float height, Pen_t pen);
GI_uid_t XYPlotter_drawString(const char* str, float x, float y, float height, Pen_t pen);


#endif