#
# This is a project Makefile. It is assumed the directory this Makefile resides in is a
# project subdirectory.
#

PROJECT_NAME := DAC_XY_Plotter

include $(IDF_PATH)/make/project.mk

.DEFAULT_GOAL := myAll

myAll: generate-font all

FONT_CODE_C_FILENAME_PREFIX := components/DAC_XY_Plotter/src/GraphicObject_char

generate-font: $(FONT_CODE_C_FILENAME_PREFIX)_thin.c $(FONT_CODE_C_FILENAME_PREFIX)_wide.c

$(FONT_CODE_C_FILENAME_PREFIX)_%.c: font_%.json
	@echo "Generating code for font $*"
	python3 font_to_code.py $< > components/DAC_XY_Plotter/src/GraphicObject_char_$*.c