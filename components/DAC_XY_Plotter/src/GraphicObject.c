#include "GraphicItem.h"
#include "GraphicObject.h"

#include <math.h>
#define max(x,y) ((x)>(y) ? (x) : (y))


#define IS_OUT_SCOPE(x, y) (((x)<0) || ((x)>255) || ((y)<0) || ((y)>255))
#define IS_IN_SCOPE(x, y) (!IS_OUT_SCOPE(x, y))

/*
 * Point
 */

size_t GO_drawPoint(void* start, float x, float y, int intensity) {
	Coord_t* pt_list = start;
    int n_pts = 0;

	for(int i=0;i<intensity;i++) {
        Coord_t runningPoint = {.x = x, .y = y};
		if(IS_IN_SCOPE(x, y)) {
            SAFE_WRITE(pt_list, i, runningPoint);
            n_pts++;
        }
	}

    return n_pts * sizeof(Coord_t);
}


/*
 * Line
 */

size_t GO_drawLine(void* start, float x1, float y1, float x2, float y2, float spacing, int intensity) {
	Coord_t* pt_list = start;
    int n_pts = 0;

	const float length = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
	const int macroPointsNb = (length/spacing);

	for(int n=0;n<macroPointsNb;n++) {
		float running_x = x1 + n * (x2 - x1) / max(macroPointsNb-1, 1);
		float running_y = y1 + n * (y2 - y1) / max(macroPointsNb-1, 1);
		if(IS_IN_SCOPE(running_x, running_y)) {
            Coord_t runningPoint = {.x = running_x, .y = running_y};
            for(int i=0;i<intensity;i++) {
    			SAFE_WRITE(pt_list, n_pts, runningPoint);
                n_pts++;
    		}
        }
	}

    return n_pts * sizeof(Coord_t);
}


/*
 * Arc
 */


size_t GO_drawArc(void* start, float x, float y, float r, float a1, float a2, float spacing, int intensity) {
    Coord_t* pt_list = start;
    int n_pts = 0;

    const float length = abs(a1-a2) * r;
    const int macroPointsNb = length/spacing;

    
    for(int n=0;n<macroPointsNb;n++) {
        float running_angle = a2 + n * (a1 - a2) / max(macroPointsNb-1, 1);
        float running_x = x + r * cos(running_angle);
        float running_y = y + r * sin(running_angle);
        if(IS_IN_SCOPE(running_x, running_y)) {
            Coord_t runningPoint = {.x = running_x, .y = running_y};
            for(int i=0;i<intensity;i++) {
                SAFE_WRITE(pt_list, n_pts, runningPoint);
                n_pts++;
            }
        }
    }

    return n_pts * sizeof(Coord_t);
}


/*
 * Rect
 */

size_t GO_drawRect(void* start, float x1, float y1, float x2, float y2, float spacing, int intensity) {
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

size_t GO_drawString(void* start, const char* str, float x, float y, float height, int intensity) {
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