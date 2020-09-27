#ifndef DAC_XY_PLOTTER
#define DAC_XY_PLOTTER

typedef struct Pen {
	float spacing;
	int intensity;
} Pen_t;

typedef void* GI_uid_t;

void XYPlotter_init(int rate);

void XYPlotter_delete(GI_uid_t uid);

GI_uid_t XYPlotter_drawPoint(int x, int y, Pen_t pen);
GI_uid_t XYPlotter_drawLine(int x1, int y1, int x2, int y2, Pen_t pen);

#endif