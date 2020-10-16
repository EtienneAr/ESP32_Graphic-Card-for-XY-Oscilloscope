$(COMPONENT_LIBRARY): generate_files

.PHONY: generate_files

GENERATED_FILES := $(FONT_CODE_C_FILEPATH)

generate_files: $(GENERATED_FILES)
	@echo "Auto-Generating code"

$(FONT_CODE_C_FILEPATH): $(FONT_JSON_SRC_FILEPATH)
	@echo "Generating code for font from $<"
	python3 $(COMPONENT_PATH)/font_to_code.py $< > $@