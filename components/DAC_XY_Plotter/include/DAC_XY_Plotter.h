#ifndef DAC_XY_PLOTTER
#define DAC_XY_PLOTTER

typedef struct Pen {
	float spacing;
	int intensity;
} Pen_t;

void XYPlotter_init(int rate);

void XYPlotter_drawPoint(int x, int y, Pen_t pen);
void XYPlotter_drawLine(int x1, int y1, int x2, int y2, Pen_t pen);

#endif