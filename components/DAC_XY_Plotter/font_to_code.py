from sys import argv
import json

in_filepath = argv[1]

in_file = open(in_filepath, 'r')
jsonParsed = json.load(in_file)

x_width = jsonParsed["grid_size"][0]
y_height = jsonParsed["grid_size"][1]

def out_writeline(indent, line):
	str_out = ""
	for _ in range(indent): 
		str_out += '\t'
	str_out += line
	print(str_out)

def code_c_line(x1, y1, x2, y2):
	return "size += GO_drawLine(SAFE_PTR(start, size), x+" + str(x1) + "*height_factor, y+" + str(y1) + "*height_factor, x+" + str(x2) + "*height_factor, y+" + str(y2) + "*height_factor, 1, intensity);"

def code_c_point(x, y):
	return "size += GO_drawPoint(SAFE_PTR(start, size), x+" + str(x) + "*height_factor, y+" + str(y) + "*height_factor, intensity*2);"


out_writeline(0,"#include \"GraphicObject.h\"")
out_writeline(0,"")
out_writeline(0,"size_t GO_drawChar(void* start, char c, float x, float y, float height, int intensity) {")

out_writeline(1,"size_t size = 0;")
out_writeline(1,"float height_factor = height / 7.;")
out_writeline(1,"switch(c) {")

jsonCharDict = jsonParsed["char"]

for char in jsonCharDict:
	if(char != '\'' and char != '\\'):
		out_writeline(2, "case '" + char + "':")
	else:
		out_writeline(2, "case '\\" + char + "':")

	char_points = jsonCharDict[char]

	for i in range(1, len(char_points)):
		if(char_points[i-1] >= 0 and char_points[i] >= 0):
			x1 = char_points[i-1] % x_width
			y1 = y_height - char_points[i-1] // x_width
			
			x2 = char_points[i] % x_width
			y2 = y_height - char_points[i] // x_width
			
			if(x1 == x2 and y1 == y2):
				out_writeline(3, code_c_point(x1, y1))
			else:
				out_writeline(3, code_c_line(x1, y1, x2, y2))	

	out_writeline(3, "break;")

out_writeline(2, "default:")

out_writeline(3, code_c_line(0, 0, 4, 0))
out_writeline(3, code_c_line(4, 0, 4, 7))
out_writeline(3, code_c_line(4, 7, 0, 7))
out_writeline(3, code_c_line(0, 7, 0, 0))
out_writeline(3, code_c_line(0, 0, 4, 7))
out_writeline(3, code_c_line(0, 7, 4, 0))

out_writeline(3, "break;")

out_writeline(1, "}")
out_writeline(1, "return size;")
out_writeline(0, "}")

in_file.close()