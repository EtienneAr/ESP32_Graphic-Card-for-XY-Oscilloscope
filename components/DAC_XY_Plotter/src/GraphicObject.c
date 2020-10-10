#include "GraphicItem.h"
#include "GraphicObject.h"

#include <math.h>
#define max(x,y) ((x)>(y) ? (x) : (y))
#define SAFE_WRITE(tab, pos, data) if(tab != NULL) { tab[pos] = data; }
#define SAFE_PTR(start, offset) (start == NULL ? NULL : start+offset)

/*
 * Point
 */

size_t GO_drawPoint(void* start, int x, int y, int intensity) {
	Coord_t* pt_list = start;

    Coord_t runningPoint = {.x = x, .y = y};
	for(int i=0;i<intensity;i++) {
		SAFE_WRITE(pt_list, i, runningPoint);
	}

    return intensity * sizeof(Coord_t);
}


/*
 * Line
 */

size_t GO_drawLine(void* start, int x1, int y1, int x2, int y2, int spacing, int intensity) {
	Coord_t* pt_list = start;

	const float length = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
	const int macroPointsNb = (length/spacing);
	const int subPointsNb = macroPointsNb * intensity;

	Coord_t runningPoint;
	for(int n=0;n<macroPointsNb;n++) {
		runningPoint.x = x2 + n * (x1 - x2) / max(macroPointsNb-1, 1);
		runningPoint.y = y2 + n * (y1 - y2) / max(macroPointsNb-1, 1);
		for(int i=0;i<intensity;i++) {
			SAFE_WRITE(pt_list, n * intensity + i, runningPoint);
		}
	}

    return subPointsNb * sizeof(Coord_t);
}


/*
 * Arc
 */


size_t GO_drawArc(void* start, int x, int y, float r, float a1, float a2, int spacing, int intensity) {
    Coord_t* pt_list = start;

    const float length = abs(a1-a2) * r;
    const int macroPointsNb = length/spacing;
    const int subPointsNb = macroPointsNb * intensity;

    Coord_t runningPoint;
    float runningAngle;
    for(int n=0;n<macroPointsNb;n++) {
        runningAngle = a2 + n * (a1 - a2) / max(macroPointsNb-1, 1);
        runningPoint.x = x + r * cos(runningAngle);
        runningPoint.y = y + r * sin(runningAngle);
        for(int i=0;i<intensity;i++) {
            SAFE_WRITE(pt_list, n * intensity + i, runningPoint);
        }
    }

    return subPointsNb * sizeof(Coord_t);
}


/*
 * Rect
 */

size_t GO_drawRect(void* start, int x1, int y1, int x2, int y2, int spacing, int intensity) {
    size_t size = 0 ;

	size += GO_drawLine( SAFE_PTR(start, size), x1, y1, x1, y2, spacing, intensity);
    size += GO_drawLine( SAFE_PTR(start, size), x1, y2, x2, y2, spacing, intensity);
    size += GO_drawLine( SAFE_PTR(start, size), x2, y2, x2, y1, spacing, intensity);
    size += GO_drawLine( SAFE_PTR(start, size), x2, y1, x1, y1, spacing, intensity);

    return size;
}


/*
 * Letters
 */

size_t GO_drawChar(void* start, char c, int x, int y, float height, int intensity) {
    size_t size = 0;

    float height_factor = height / 7.;

    switch(c) {
        case '[':
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+7*height_factor, x+0*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+2*height_factor, y+3*height_factor, 1, intensity);
break;
case ']':
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+7*height_factor, x+4*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+7*height_factor, x+4*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+3*height_factor, x+2*height_factor, y+3*height_factor, 1, intensity);
break;
case 'Z':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+4*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+7*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+4*height_factor, y+3*height_factor, 1, intensity);
break;
case 'Y':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+2*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+5*height_factor, x+2*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+5*height_factor, x+4*height_factor, y+7*height_factor, 1, intensity);
break;
case 'X':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
break;
case 'W':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+3*height_factor, x+2*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+6*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+4*height_factor, y+7*height_factor, 1, intensity);
break;
case 'V':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+2*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+3*height_factor, x+4*height_factor, y+7*height_factor, 1, intensity);
break;
case 'U':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+0*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+3*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+4*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+4*height_factor, x+4*height_factor, y+7*height_factor, 1, intensity);
break;
case 'T':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+4*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+7*height_factor, x+2*height_factor, y+3*height_factor, 1, intensity);
break;
case 'S':
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+6*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+7*height_factor, x+1*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+7*height_factor, x+0*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+6*height_factor, x+1*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+5*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+5*height_factor, x+4*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+4*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+3*height_factor, x+0*height_factor, y+4*height_factor, 1, intensity);
break;
case 'R':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+0*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+7*height_factor, x+4*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+6*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+5*height_factor, x+0*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+5*height_factor, x+4*height_factor, y+3*height_factor, 1, intensity);
break;
case 'Q':
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+7*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+7*height_factor, x+4*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+6*height_factor, x+4*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+4*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+3*height_factor, x+0*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+0*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+6*height_factor, x+1*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+4*height_factor, x+4*height_factor, y+3*height_factor, 1, intensity);
break;
case 'P':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+0*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+7*height_factor, x+4*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+6*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+5*height_factor, x+0*height_factor, y+5*height_factor, 1, intensity);
break;
case 'O':
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+7*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+7*height_factor, x+4*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+6*height_factor, x+4*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+4*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+3*height_factor, x+0*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+0*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+6*height_factor, x+1*height_factor, y+7*height_factor, 1, intensity);
break;
case 'N':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+0*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
break;
case 'M':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+0*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+2*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+4*height_factor, x+4*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+7*height_factor, x+4*height_factor, y+3*height_factor, 1, intensity);
break;
case 'L':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+4*height_factor, y+-12*height_factor, 1, intensity);
break;
case 'K':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+5*height_factor, x+4*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+3*height_factor, x+4*height_factor, y+-12*height_factor, 1, intensity);
break;
case 'J':
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+7*height_factor, x+3*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+4*height_factor, x+2*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+3*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+3*height_factor, x+0*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+4*height_factor, y+-12*height_factor, 1, intensity);
break;
case 'I':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+2*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+7*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+2*height_factor, y+3*height_factor, 1, intensity);
break;
case 'H':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+7*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
break;
case 'G':
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+6*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+7*height_factor, x+1*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+7*height_factor, x+0*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+6*height_factor, x+0*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+3*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+4*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+4*height_factor, x+4*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+5*height_factor, x+2*height_factor, y+5*height_factor, 1, intensity);
break;
case 'F':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+0*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+2*height_factor, y+5*height_factor, 1, intensity);
break;
case 'E':
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+0*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+2*height_factor, y+5*height_factor, 1, intensity);
break;
case 'D':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+0*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+7*height_factor, x+4*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+6*height_factor, x+4*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+4*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
break;
case 'C':
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+4*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+3*height_factor, x+0*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+0*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+6*height_factor, x+1*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+7*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+7*height_factor, x+4*height_factor, y+6*height_factor, 1, intensity);
break;
case 'B':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+0*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+7*height_factor, x+4*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+6*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+5*height_factor, x+0*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+5*height_factor, x+4*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+4*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
break;
case 'A':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+2*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+7*height_factor, x+4*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+5*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
break;
case '/':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
break;
case '\\':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
break;
case '|':
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+7*height_factor, x+2*height_factor, y+3*height_factor, 1, intensity);
break;
case '?':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+6*height_factor, x+1*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+7*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+7*height_factor, x+4*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+6*height_factor, x+4*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+5*height_factor, x+2*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+4*height_factor, x+2*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+2*height_factor, x+2*height_factor, y+1*height_factor, 1, intensity);
break;
case '!':
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+7*height_factor, x+2*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+2*height_factor, x+2*height_factor, y+1*height_factor, 1, intensity);
break;
case ':':
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+6*height_factor, x+2*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+4*height_factor, x+2*height_factor, y+4*height_factor, 1, intensity);
break;
case '(':
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+7*height_factor, x+0*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+6*height_factor, x+0*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
break;
case ')':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+1*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+6*height_factor, x+1*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+4*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
break;
case ' ':
break;
case '+':
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+7*height_factor, x+2*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+4*height_factor, y+5*height_factor, 1, intensity);
break;
case '-':
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+5*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
break;
case '0':
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+7*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+7*height_factor, x+4*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+6*height_factor, x+4*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+4*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+3*height_factor, x+0*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+0*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+6*height_factor, x+1*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+6*height_factor, x+1*height_factor, y+4*height_factor, 1, intensity);
break;
case '9':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+3*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+4*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+4*height_factor, x+4*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+6*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+7*height_factor, x+1*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+7*height_factor, x+0*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+6*height_factor, x+1*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+5*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+5*height_factor, x+4*height_factor, y+6*height_factor, 1, intensity);
break;
case '8':
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+5*height_factor, x+0*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+6*height_factor, x+1*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+7*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+7*height_factor, x+4*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+6*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+5*height_factor, x+1*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+5*height_factor, x+0*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+3*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+4*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+4*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
break;
case '7':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+4*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+7*height_factor, x+2*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+5*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
break;
case '6':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+1*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+5*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+5*height_factor, x+4*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+4*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+3*height_factor, x+0*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+0*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+6*height_factor, x+1*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+7*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+7*height_factor, x+4*height_factor, y+6*height_factor, 1, intensity);
break;
case '5':
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+7*height_factor, x+0*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+0*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+5*height_factor, x+4*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+4*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+3*height_factor, x+0*height_factor, y+4*height_factor, 1, intensity);
break;
case '4':
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+7*height_factor, x+0*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+4*height_factor, y+4*height_factor, 1, intensity);
break;
case '3':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+4*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+7*height_factor, x+2*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+5*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+5*height_factor, x+4*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+4*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+3*height_factor, x+0*height_factor, y+4*height_factor, 1, intensity);
break;
case '2':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+6*height_factor, x+1*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+7*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+7*height_factor, x+4*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+6*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+4*height_factor, y+3*height_factor, 1, intensity);
break;
case '1':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+6*height_factor, x+1*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+7*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+2*height_factor, y+3*height_factor, 1, intensity);
break;
case ',':
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+3*height_factor, x+0*height_factor, y+2*height_factor, 1, intensity);
break;
case '.':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
break;
case 'z':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+5*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+4*height_factor, y+-12*height_factor, 1, intensity);
break;
case 'y':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+5*height_factor, x+0*height_factor, y+1*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+1*height_factor, x+4*height_factor, y+-12*height_factor, 1, intensity);
break;
case 'x':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
break;
case 'w':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+3*height_factor, x+2*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+5*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+4*height_factor, y+5*height_factor, 1, intensity);
break;
case 'v':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+3*height_factor, x+2*height_factor, y+5*height_factor, 1, intensity);
break;
case 'u':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+0*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+3*height_factor, x+2*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+3*height_factor, x+3*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+4*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+5*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
break;
case 't':
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+6*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+3*height_factor, x+2*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+2*height_factor, y+5*height_factor, 1, intensity);
break;
case 's':
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+5*height_factor, x+0*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+0*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+3*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+4*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
break;
case 'a':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+5*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+0*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+3*height_factor, y+4*height_factor, 1, intensity);
break;
case 'b':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+5*height_factor, x+0*height_factor, y+5*height_factor, 1, intensity);
break;
case 'c':
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+5*height_factor, x+0*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
break;
case 'd':
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+7*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+0*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
break;
case 'e':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+3*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+4*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+5*height_factor, x+0*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
break;
case 'f':
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+3*height_factor, x+1*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+7*height_factor, x+2*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+2*height_factor, y+5*height_factor, 1, intensity);
break;
case 'g':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+2*height_factor, x+3*height_factor, y+2*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+2*height_factor, x+3*height_factor, y+1*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+1*height_factor, x+0*height_factor, y+1*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+1*height_factor, x+0*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+5*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
break;
case 'h':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+2*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+5*height_factor, x+3*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+4*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
break;
case 'i':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+4*height_factor, y+-12*height_factor, 1, intensity);
break;
case 'j':
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+5*height_factor, x+2*height_factor, y+2*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+2*height_factor, x+1*height_factor, y+1*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+1*height_factor, x+0*height_factor, y+1*height_factor, 1, intensity);
break;
case 'k':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+6*height_factor, x+0*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+5*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
break;
case 'l':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
break;
case 'm':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+0*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+1*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+5*height_factor, x+2*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+4*height_factor, x+2*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+3*height_factor, x+2*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+5*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+5*height_factor, x+4*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+4*height_factor, x+4*height_factor, y+3*height_factor, 1, intensity);
break;
case 'n':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+0*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+1*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+5*height_factor, x+2*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+4*height_factor, x+2*height_factor, y+3*height_factor, 1, intensity);
break;
case 'o':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+5*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+0*height_factor, y+5*height_factor, 1, intensity);
break;
case 'p':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+1*height_factor, x+0*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+5*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
break;
case 'q':
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+1*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+5*height_factor, x+0*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
break;
case 'r':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+1*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+5*height_factor, x+2*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+5*height_factor, x+3*height_factor, y+4*height_factor, 1, intensity);
break;
case '\'':
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+7*height_factor, x+2*height_factor, y+6*height_factor, 1, intensity);
break;
case '"':
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+7*height_factor, x+1*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+7*height_factor, x+3*height_factor, y+6*height_factor, 1, intensity);
break;
case '*':
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+6*height_factor, x+2*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+5*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+6*height_factor, x+3*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+4*height_factor, x+3*height_factor, y+6*height_factor, 1, intensity);
break;
case '_':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+2*height_factor, x+4*height_factor, y+2*height_factor, 1, intensity);
break;
case '#':
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+6*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+6*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+4*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+4*height_factor, y+4*height_factor, 1, intensity);
break;
case '$':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+7*height_factor, x+0*height_factor, y+2*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+7*height_factor, x+1*height_factor, y+2*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+2*height_factor, x+4*height_factor, y+2*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+4*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+4*height_factor, y+5*height_factor, 1, intensity);
break;
case '%':
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+7*height_factor, x+0*height_factor, y+2*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+7*height_factor, x+0*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+6*height_factor, x+1*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+5*height_factor, x+2*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+6*height_factor, x+1*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+4*height_factor, x+2*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+3*height_factor, x+3*height_factor, y+2*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+2*height_factor, x+4*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+3*height_factor, x+3*height_factor, y+4*height_factor, 1, intensity);
break;
case '^':
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+6*height_factor, x+2*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+7*height_factor, x+3*height_factor, y+6*height_factor, 1, intensity);
break;
case '&':
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+3*height_factor, x+1*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+6*height_factor, x+1*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+7*height_factor, x+2*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+7*height_factor, x+2*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+6*height_factor, x+0*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+3*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+4*height_factor, y+5*height_factor, 1, intensity);
break;
case '@':
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+4*height_factor, x+3*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+6*height_factor, x+2*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+6*height_factor, x+1*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+5*height_factor, x+1*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+4*height_factor, x+3*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+4*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+5*height_factor, x+4*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+4*height_factor, x+4*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+6*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+7*height_factor, x+1*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+7*height_factor, x+0*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+6*height_factor, x+0*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+3*height_factor, x+4*height_factor, y+3*height_factor, 1, intensity);
break;
case '<':
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+7*height_factor, x+0*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+4*height_factor, y+3*height_factor, 1, intensity);
break;
case '>':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+4*height_factor, y+5*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+5*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
break;
case ';':
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+6*height_factor, x+2*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+4*height_factor, x+2*height_factor, y+4*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+4*height_factor, x+2*height_factor, y+3*height_factor, 1, intensity);
break;
case '~':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+6*height_factor, x+1*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+7*height_factor, x+2*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+6*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+7*height_factor, x+4*height_factor, y+7*height_factor, 1, intensity);
break;
case '=':
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+6*height_factor, x+4*height_factor, y+6*height_factor, 1, intensity);
    size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+4*height_factor, y+4*height_factor, 1, intensity);
break;

    }

    return size;
}