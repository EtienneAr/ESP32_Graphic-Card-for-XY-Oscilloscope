#
# This is a project Makefile. It is assumed the directory this Makefile resides in is a
# project subdirectory.
#

PROJECT_NAME := DAC_XY_Plotter

include $(IDF_PATH)/make/project.mk

font: font.json
	python3 font_to_code.py font.json components/DAC_XY_Plotter/src/GraphicObject_char.c