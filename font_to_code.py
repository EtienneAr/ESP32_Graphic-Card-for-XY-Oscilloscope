import json
import os

out_filepath = "components/DAC_XY_Plotter/src/GraphicObject_char.c"

try:
	os.remove(out_filepath)
except:
	pass
finally:
	out_file = open(out_filepath, "x")

in_file = open("font.json")
jsonParsed = json.load(in_file)

def out_writeline(indent, line):
	for _ in range(indent): 
		out_file.write('\t')
	out_file.write(line)
	out_file.write('\n')


out_writeline(0,"#include \"GraphicObject.h\"")
out_writeline(0,"")
out_writeline(0,"size_t GO_drawChar(void* start, char c, int x, int y, float height, int intensity) {")

out_writeline(1,"size_t size = 0;")
out_writeline(1,"float height_factor = height / 7.;")
out_writeline(1,"switch(c) {")

for char in jsonParsed:
	if(char != '\'' and char != '\\'):
		out_writeline(2, "case '" + char + "':")
	else:
		out_writeline(2, "case '\\" + char + "':")

	char_points = jsonParsed[char]

	for i in range(1, len(char_points)):
		if(char_points[i-1] >= 0 and char_points[i] >= 0):
			x1 = char_points[i-1] % 5
			y1 = 7 - char_points[i-1] // 5
			
			x2 = char_points[i] % 5
			y2 = 7 - char_points[i] // 5
			
			out_writeline(3, "size += GO_drawLine(SAFE_PTR(start, size), x+" + str(x1) + "*height_factor, y+" + str(y1) + "*height_factor, x+" + str(x2) + "*height_factor, y+" + str(y2) + "*height_factor, 1, intensity);")	

	out_writeline(2, "break;")

out_writeline(1, "}")
out_writeline(1, "return size;")
out_writeline(0, "}")

in_file.close()
out_file.close()