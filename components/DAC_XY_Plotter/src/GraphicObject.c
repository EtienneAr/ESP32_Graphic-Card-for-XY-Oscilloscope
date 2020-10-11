#include "GraphicItem.h"
#include "GraphicObject.h"

#include <math.h>
#define max(x,y) ((x)>(y) ? (x) : (y))

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
		runningPoint.x = x1 + n * (x2 - x1) / max(macroPointsNb-1, 1);
		runningPoint.y = y1 + n * (y2 - y1) / max(macroPointsNb-1, 1);
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
 * String
 */

size_t GO_drawString(void* start, const char* str, int x, int y, float height, int intensity) {
    size_t size = 0 ;

    float y_off = y;
    float x_off = x;
    float x_step = 5 * height / 7;
    const float y_step = -height;

    for(int i=0;i < strlen(str);i++) {
        if(x_off > 250 - x_step) {
            if(y_off < 5 -y_step) {
                break;
            }
            y_off += y_step;
            x_off = x;
        }

        size += GO_drawChar(SAFE_PTR(start, size), str[i], x_off, y_off, height, intensity);
        
        x_off += x_step;
    }

    return size;
}