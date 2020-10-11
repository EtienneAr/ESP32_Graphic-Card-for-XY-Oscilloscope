#include "GraphicObject.h"

size_t GO_drawChar(void* start, char c, int x, int y, float height, int intensity) {
	size_t size = 0;
	float height_factor = height / 7.;
	switch(c) {
		case '{':
			size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+7*height_factor, x+1*height_factor, y+6*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+6*height_factor, x+1*height_factor, y+5*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+5*height_factor, x+0*height_factor, y+4*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+3*height_factor, x+1*height_factor, y+2*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+2*height_factor, x+2*height_factor, y+1*height_factor, 1, intensity);
			break;
		case '}':
			size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+7*height_factor, x+3*height_factor, y+6*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+6*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+5*height_factor, x+4*height_factor, y+4*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+4*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+3*height_factor, y+2*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+2*height_factor, x+2*height_factor, y+1*height_factor, 1, intensity);
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
			size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+3*height_factor, x+2*height_factor, y+7*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+4*height_factor, y+7*height_factor, 1, intensity);
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
			size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+3*height_factor, x+0*height_factor, y+4*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+0*height_factor, y+6*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+6*height_factor, x+1*height_factor, y+7*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+7*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+7*height_factor, x+4*height_factor, y+6*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+6*height_factor, x+4*height_factor, y+4*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+4*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+3*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
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
			break;
		case 'K':
			size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+0*height_factor, y+7*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+3*height_factor, y+7*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+5*height_factor, x+4*height_factor, y+3*height_factor, 1, intensity);
			break;
		case 'J':
			size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+7*height_factor, x+3*height_factor, y+4*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+4*height_factor, x+2*height_factor, y+3*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+3*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+3*height_factor, x+0*height_factor, y+4*height_factor, 1, intensity);
			break;
		case 'I':
			size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+2*height_factor, y+7*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+7*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+2*height_factor, y+3*height_factor, 1, intensity);
			break;
		case 'H':
			size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+0*height_factor, y+7*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+7*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
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
			size += GO_drawPoint(SAFE_PTR(start, size), x+2*height_factor, y+2*height_factor, intensity*2);
			break;
		case '!':
			size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+7*height_factor, x+2*height_factor, y+3*height_factor, 1, intensity);
			size += GO_drawPoint(SAFE_PTR(start, size), x+2*height_factor, y+2*height_factor, intensity*2);
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
		case 'z':
			size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+3*height_factor, y+5*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+5*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+3*height_factor, y+3*height_factor, 1, intensity);
			break;
		case 'y':
			size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+5*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+5*height_factor, x+0*height_factor, y+1*height_factor, 1, intensity);
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
			size += GO_drawPoint(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, intensity*2);
			break;
		case 'j':
			size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+1*height_factor, x+1*height_factor, y+1*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+1*height_factor, x+2*height_factor, y+2*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+2*height_factor, x+2*height_factor, y+5*height_factor, 1, intensity);
			size += GO_drawPoint(SAFE_PTR(start, size), x+2*height_factor, y+7*height_factor, intensity*2);
			break;
		case 'k':
			size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+0*height_factor, y+7*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+4*height_factor, x+2*height_factor, y+6*height_factor, 1, intensity);
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
		case ',':
			size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+2*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
			break;
		case '.':
			size += GO_drawPoint(SAFE_PTR(start, size), x+1*height_factor, y+3*height_factor, intensity*2);
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
			size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+2*height_factor, x+4*height_factor, y+7*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+7*height_factor, x+0*height_factor, y+6*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+6*height_factor, x+1*height_factor, y+5*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+1*height_factor, y+5*height_factor, x+2*height_factor, y+6*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+6*height_factor, x+1*height_factor, y+7*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+3*height_factor, x+3*height_factor, y+4*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+4*height_factor, x+2*height_factor, y+3*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+3*height_factor, x+3*height_factor, y+2*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+3*height_factor, y+2*height_factor, x+4*height_factor, y+3*height_factor, 1, intensity);
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
		case ']':
			size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+7*height_factor, x+4*height_factor, y+7*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+7*height_factor, x+4*height_factor, y+3*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+3*height_factor, x+2*height_factor, y+3*height_factor, 1, intensity);
			break;
		case '[':
			size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+7*height_factor, x+0*height_factor, y+7*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+0*height_factor, y+3*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+3*height_factor, x+2*height_factor, y+3*height_factor, 1, intensity);
			break;
		case ':':
			size += GO_drawPoint(SAFE_PTR(start, size), x+2*height_factor, y+4*height_factor, intensity*2);
			size += GO_drawPoint(SAFE_PTR(start, size), x+2*height_factor, y+6*height_factor, intensity*2);
			break;
		case ';':
			size += GO_drawLine(SAFE_PTR(start, size), x+2*height_factor, y+4*height_factor, x+1*height_factor, y+3*height_factor, 1, intensity);
			size += GO_drawPoint(SAFE_PTR(start, size), x+2*height_factor, y+6*height_factor, intensity*2);
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
		default:
			size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+0*height_factor, x+4*height_factor, y+0*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+0*height_factor, x+4*height_factor, y+7*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+4*height_factor, y+7*height_factor, x+0*height_factor, y+7*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+0*height_factor, y+0*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+0*height_factor, x+4*height_factor, y+7*height_factor, 1, intensity);
			size += GO_drawLine(SAFE_PTR(start, size), x+0*height_factor, y+7*height_factor, x+4*height_factor, y+0*height_factor, 1, intensity);
			break;
	}
	return size;
}
