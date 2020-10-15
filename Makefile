#
# This is a project Makefile. It is assumed the directory this Makefile resides in is a
# project subdirectory.
#

PROJECT_NAME := DAC_XY_Plotter

include $(IDF_PATH)/make/project.mk

.DEFAULT_GOAL := font-thin
myAll: font-thin all

font-%: font_%.json
	@echo "Generating code for font $*"
	python3 font_to_code.py $< components/DAC_XY_Plotter/src/GraphicObject_char_$*.c

font-wide: font_wide.json
	python3 font_to_code.py $< components/DAC_XY_Plotter/src/GraphicObject_char_$*.c 5 7
