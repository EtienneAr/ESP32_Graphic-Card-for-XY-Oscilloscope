#ifndef DAC_XY_PLOTTER
#define DAC_XY_PLOTTER

typedef struct Pen {
	int spacing;
	int intensity;
} Pen_t;

void XYPlotter_init(int rate);

void XYPlotter_drawPoint(int x, int y, Pen_t pen);

#endif