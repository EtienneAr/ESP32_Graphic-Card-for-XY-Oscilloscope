#include "GraphicItem.h"
#include "GraphicObject.h"

#include <math.h>
#define max(x,y) ((x)>(y) ? (x) : (y))


/*
 * Point
 */

size_t GO_drawPoint_len(int x, int y, int intensity) {
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

size_t GO_drawLine_len( int x1, int y1, int x2, int y2, int spacing, int intensity) {
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


/*
 * Rect
 */

size_t GO_drawRect_len(int x1, int y1, int x2, int y2, int spacing, int intensity) {
	size_t res = 0;

	res += GO_drawLine_len(x1, y1, x1, y2, spacing, intensity);
	res += GO_drawLine_len(x1, y2, x2, y2, spacing, intensity);
	res += GO_drawLine_len(x2, y2, x2, y1, spacing, intensity);
	res += GO_drawLine_len(x2, y1, x1, y1, spacing, intensity);

	return res;
}


void GO_drawRect(void* start, int x1, int y1, int x2, int y2, int spacing, int intensity) {
	void* ptr = start;

	       GO_drawLine(ptr, x1, y1, x1, y2, spacing, intensity);
	ptr += GO_drawLine_len( x1, y1, x1, y2, spacing, intensity);

           GO_drawLine(ptr, x1, y2, x2, y2, spacing, intensity);
    ptr += GO_drawLine_len( x1, y2, x2, y2, spacing, intensity);

           GO_drawLine(ptr, x2, y2, x2, y1, spacing, intensity);
    ptr += GO_drawLine_len( x2, y2, x2, y1, spacing, intensity);

           GO_drawLine(ptr, x2, y1, x1, y1, spacing, intensity);
    ptr += GO_drawLine_len( x2, y1, x1, y1, spacing, intensity);
}

/*
 * Arc
 */

size_t GO_drawArc_len(int x, int y, float r, float a1, float a2, int spacing, int intensity) {
    const float length = abs(a1-a2) * r;
    const int macroPointsNb = length/spacing;
    const int subPointsNb = macroPointsNb * intensity;

    return subPointsNb * sizeof(Coord_t);
}


void GO_drawArc(void* start, int x, int y, float r, float a1, float a2, int spacing, int intensity) {
    Coord_t* pt_list = start;

    const float length = abs(a1-a2) * r;
    const int macroPointsNb = length/spacing;
    //const int subPointsNb = macroPointsNb * intensity;

    Coord_t runningPoint;
    float runningAngle;
    for(int n=0;n<macroPointsNb;n++) {
        runningAngle = a2 + n * (a1 - a2) / max(macroPointsNb-1, 1);
        runningPoint.x = x + r * cos(runningAngle);
        runningPoint.y = y + r * sin(runningAngle);
        for(int i=0;i<intensity;i++) {
            pt_list[n * intensity + i ] = runningPoint;
        }
    }
}


/*
 * Letters
 */

size_t GO_drawLetter_A_len(int x, int y, float size, int intensity) {
    size_t res = 0;

    res += GO_drawLine_len(x+0*size, y+5*size, x+3*size, y+5*size, 1, intensity);
    res += GO_drawLine_len(x+3*size, y+5*size, x+3*size, y+3*size, 1, intensity);
    res += GO_drawLine_len(x+3*size, y+3*size, x+0*size, y+3*size, 1, intensity);
    res += GO_drawLine_len(x+0*size, y+3*size, x+0*size, y+4*size, 1, intensity);
    res += GO_drawLine_len(x+0*size, y+4*size, x+3*size, y+4*size, 1, intensity);

    return res;
}

void GO_drawLetter_A(void* start, int x, int y, float size, int intensity) {
    void* ptr = start;

    GO_drawLine(ptr, x+0*size, y+5*size, x+3*size, y+5*size, 1, intensity);
    ptr += GO_drawLine_len(x+0*size, y+5*size, x+3*size, y+5*size, 1, intensity);
    GO_drawLine(ptr, x+3*size, y+5*size, x+3*size, y+3*size, 1, intensity);
    ptr += GO_drawLine_len(x+3*size, y+5*size, x+3*size, y+3*size, 1, intensity);
    GO_drawLine(ptr, x+3*size, y+3*size, x+0*size, y+3*size, 1, intensity);
    ptr += GO_drawLine_len(x+3*size, y+3*size, x+0*size, y+3*size, 1, intensity);
    GO_drawLine(ptr, x+0*size, y+3*size, x+0*size, y+4*size, 1, intensity);
    ptr += GO_drawLine_len(x+0*size, y+3*size, x+0*size, y+4*size, 1, intensity);
    GO_drawLine(ptr, x+0*size, y+4*size, x+3*size, y+4*size, 1, intensity);
    ptr += GO_drawLine_len(x+0*size, y+4*size, x+3*size, y+4*size, 1, intensity);

}