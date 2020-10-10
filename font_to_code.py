import json

file = open("font.json")

jsonParsed = json.load(file)

a_list = jsonParsed["a"]


for i in range(1, len(a_list)):
	x1 = a_list[i-1] % 5
	y1 = 7 - a_list[i-1] // 5
	
	x2 = a_list[i] % 5
	y2 = 7 - a_list[i] // 5
	
	print("size += GO_drawLine(SAFE_PTR(start, size), x+" + str(x1) + "*height_factor, y+" + str(y1) + "*height_factor, x+" + str(x2) + "*height_factor, y+" + str(y2) + "*height_factor, 1, intensity);")


