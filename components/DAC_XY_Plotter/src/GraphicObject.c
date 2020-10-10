#include "GraphicItem.h"
#include "GraphicObject.h"

#include <math.h>
#define max(x,y) ((x)>(y) ? (x) : (y))

/*
 * Point
 */

int GO_drawPoint_len(int x, int y, int intensity) {
	return intensity * sizeof(Coord_t);
}

void GO_drawPoint(void* start, int x, int y, int intensity) {
	Coord_t* pt_list = start;

	for(int i=0;i<intensity;i++) {
		pt_list[i] = (Coord_t) {.x = x, .y = y};
	}
}

/*
 * Line
 */

int  GO_drawLine_len( int x1, int y1, int x2, int y2, int spacing, int intensity) {
	const float length = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
	const int macroPointsNb = (length/spacing);
	const int subPointsNb = macroPointsNb * intensity;
	
	return subPointsNb * sizeof(Coord_t);
}


void GO_drawLine(void* start, int x1, int y1, int x2, int y2, int spacing, int intensity) {
	Coord_t* pt_list = start;

	const float length = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
	const int macroPointsNb = (length/spacing);
	//const int subPointsNb = macroPointsNb * intensity;

	Coord_t runningPoint;
	for(int n=0;n<macroPointsNb;n++) {
		runningPoint.x = x2 + n * (x1 - x2) / max(macroPointsNb-1, 1);
		runningPoint.y = y2 + n * (y1 - y2) / max(macroPointsNb-1, 1);
		for(int i=0;i<intensity;i++) {
			pt_list[n * intensity + i ] = runningPoint;
		}
	}
}