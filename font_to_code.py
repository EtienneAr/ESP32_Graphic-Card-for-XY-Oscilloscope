import json

in_file = open("font.json")

jsonParsed = json.load(in_file)


for char in jsonParsed:
	if(char != '\'' and char != '\\'):
		print("case '" + char + "':")
	else:
		print("case '\\" + char + "':")

	char_points = jsonParsed[char]

	for i in range(1, len(char_points)):
		if(char_points[i-1] >= 0 and char_points[i] >= 0):
			x1 = char_points[i-1] % 5
			y1 = 7 - char_points[i-1] // 5
			
			x2 = char_points[i] % 5
			y2 = 7 - char_points[i] // 5
			
			print("\tsize += GO_drawLine(SAFE_PTR(start, size), x+" + str(x1) + "*height_factor, y+" + str(y1) + "*height_factor, x+" + str(x2) + "*height_factor, y+" + str(y2) + "*height_factor, 1, intensity);")
		


	print("break;")

in_file.close()