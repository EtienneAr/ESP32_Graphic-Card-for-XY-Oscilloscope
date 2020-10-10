#
# This is a project Makefile. It is assumed the directory this Makefile resides in is a
# project subdirectory.
#

PROJECT_NAME := DAC_XY_Plotter

include $(IDF_PATH)/make/project.mk

font-wide: font_wide.json
	python3 font_to_code.py font_wide.json components/DAC_XY_Plotter/src/GraphicObject_char.c 5 7

font-thin: font_thin.json
	python3 font_to_code.py font_thin.json components/DAC_XY_Plotter/src/GraphicObject_char.c 3 7