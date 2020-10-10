import json

file = open("font.json")

jsonParsed = json.load(file)

a_list = jsonParsed["a"]
print(jsonParsed["a"])


for i in range(1, len(a_list)):
	x1 = a_list[i-1] % 5
	y1 = 7 - a_list[i-1] // 5
	
	x2 = a_list[i] % 5
	y2 = 7 - a_list[i] // 5
	
	print("res += GO_drawLine_len(x+" + str(x1) + "*size, y+" + str(y1) + "*size, x+" + str(x2) + "*size, y+" + str(y2) + "*size, 1, intensity);")

print("")

for i in range(1, len(a_list)):
	x1 = a_list[i-1] % 5
	y1 = 7 - a_list[i-1] // 5
	
	x2 = a_list[i] % 5
	y2 = 7 - a_list[i] // 5
	
	print("GO_drawLine(ptr, x+" + str(x1) + "*size, y+" + str(y1) + "*size, x+" + str(x2) + "*size, y+" + str(y2) + "*size, 1, intensity);")
	print("ptr += GO_drawLine_len(x+" + str(x1) + "*size, y+" + str(y1) + "*size, x+" + str(x2) + "*size, y+" + str(y2) + "*size, 1, intensity);")


