COMPONENT_ADD_INCLUDEDIRS := ./include

COMPONENT_PRIV_INCLUDEDIRS +=  ./priv_include


GENERATED_CODE_C_RELATIVE_PATH := src/generated_srcs
GENERATED_CODE_C_ABSOLUTE_PATH := $(COMPONENT_PATH)/$(GENERATED_CODE_C_RELATIVE_PATH)
FONT_CODE_C_FILEPATH := $(GENERATED_CODE_C_ABSOLUTE_PATH)/GraphicObject_char.c

quote:="
FONT_JSON_SRC_FILENAME := $(subst $(quote),,$(CONFIG_FONT_FILE)) 
FONT_JSON_SRC_FILEPATH := $(COMPONENT_PATH)/data/$(FONT_JSON_SRC_FILENAME)


$(COMPONENT_LIBRARY): generate_files

.PHONY: generate_files

GENERATED_FILES := $(FONT_CODE_C_FILEPATH)

generate_files: $(GENERATED_FILES)
	@echo "Auto-Generating code"

$(FONT_CODE_C_FILEPATH): $(FONT_JSON_SRC_FILEPATH)
	@echo "Generating code for font from $<"
	python3 $(COMPONENT_PATH)/font_to_code.py $< > $@


COMPONENT_SRCDIRS += ./src ./$(GENERATED_CODE_C_RELATIVE_PATH)
COMPONENT_EXTRA_CLEAN := $(GENERATED_CODE_C_ABSOLUTE_PATH)/*

COMPONENT_OBJS := $(foreach compsrcdir,$(COMPONENT_SRCDIRS),$(patsubst %.c,%.o,$(wildcard $(COMPONENT_PATH)/$(compsrcdir)/*.c)))
COMPONENT_OBJS += $(foreach file, $(GENERATED_FILES), $(patsubst %.c,%.o,$(file)))

# Make relative by removing COMPONENT_PATH from all found object paths
COMPONENT_OBJS := $(patsubst $(COMPONENT_PATH)/%,%,$(COMPONENT_OBJS))