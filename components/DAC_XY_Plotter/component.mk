COMPONENT_ADD_INCLUDEDIRS := ./include

COMPONENT_PRIV_INCLUDEDIRS +=  ./priv_include

COMPONENT_SRCDIRS += ./src


FONT_CODE_C_FILENAME_PREFIX := $(COMPONENT_PATH)/src/GraphicObject_char

COMPONENT_EXTRA_CLEAN := $(FONT_CODE_C_FILENAME_PREFIX)*

$(COMPONENT_LIBRARY): generate_files

.PHONY: generate_files

generate_files: $(FONT_CODE_C_FILENAME_PREFIX)_thin.c $(FONT_CODE_C_FILENAME_PREFIX)_wide.c

$(FONT_CODE_C_FILENAME_PREFIX)_%.c: $(COMPONENT_PATH)/data/font_%.json
	@echo "Generating code for font $*"
	python3 $(COMPONENT_PATH)/font_to_code.py $< > $@
