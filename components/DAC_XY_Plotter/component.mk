# Setup component
COMPONENT_ADD_INCLUDEDIRS := ./include
COMPONENT_PRIV_INCLUDEDIRS +=  ./priv_include

# Setup variable for source code generation
GENERATED_CODE_C_RELATIVE_PATH := src/generated_srcs
GENERATED_CODE_C_ABSOLUTE_PATH := $(COMPONENT_PATH)/$(GENERATED_CODE_C_RELATIVE_PATH)

include $(COMPONENT_PATH)/generate_files.mk

COMPONENT_SRCDIRS += ./src ./$(GENERATED_CODE_C_RELATIVE_PATH)
COMPONENT_EXTRA_CLEAN := $(GENERATED_CODE_C_ABSOLUTE_PATH)/*


#
#	Make component objs
#
src2obj = $(patsubst %.c,%.o,$(1))

#Auto find obj by iterating on src dir
COMPONENT_OBJS := $(foreach compsrcdir,$(COMPONENT_SRCDIRS),$(call src2obj, $(wildcard $(COMPONENT_PATH)/$(compsrcdir)/*.c)))
#Add generated file
COMPONENT_OBJS += $(foreach file, $(GENERATED_FILES), $(call src2obj, $(file)))
# Make relative by removing COMPONENT_PATH from all found object paths
COMPONENT_OBJS := $(patsubst $(COMPONENT_PATH)/%,%,$(COMPONENT_OBJS))