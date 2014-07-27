#name of the executable to be created
  BIN_NAME := coffee
# # Compiler used
  CXX ?= g++
  

    
# # Extension of source files used in the project
  SRC_EXT = cpp
# # Path to the source directory, relative to the makefile
  SRC_PATH = ./src
  
##Variable Path to Build hierarchical directories
  VPATH = ./src
# # General compiler flags
  COMPILE_FLAGS =  -Wall -Wextra -g 
#
##Include Files 
  INCLUDES = -I $(VPATH)

#  Combine compiler and linker flags
  export CXXFLAGS := $(CXXFLAGS) $(COMPILE_FLAGS) $(RCOMPILE_FLAGS)
  export LDFLAGS := $(LDFLAGS) $(LINK_FLAGS) $(RLINK_FLAGS)
#
#


# Build and output paths

  export BUILD_PATH := ./build
  export BIN_PATH := ./bin

  CMD_PREFIX := 

# Shell used in this makefile
# # bash is used for 'echo -en'
  SHELL = /bin/bash
#
# Find all source files in the source directory, sorted by most
#  recently modified
  SOURCES = $(shell find $(VPATH)/ -name '*.$(SRC_EXT)' -printf '%T@\t%p\n' \
             | sort -k 1nr | cut -f2-)
#fallback in case the above fails
  rwildcard = $(foreach d, $(wildcard $1*), $(call rwildcard,$d/,$2) \
	# $(filter $(subst *,%,$2), $d))

ifeq ($(SOURCES),)
  SOURCES := $(call rwildcard, $(VPATH)/, *.$(SRC_EXT))
endif

#Get the object file names, with the source directory stripped
#from the path, and the build path prepended in its place
  OBJECTS = $(SOURCES:$(VPATH)/%.$(SRC_EXT)=$(BUILD_PATH)/%.o)
  
# # Set the dependency files that will be used to add header dependencies
  DEPS = $(OBJECTS:.o=.d)

### rule to rebuild  
 rebuild: clean dirs all lib

### alias to build coffee = build all
 coffee: all  
  
# # Main rule, checks the executable and symlinks to the output
 all: $(BIN_PATH)/$(BIN_NAME)

# Link the executable

    $(BIN_PATH)/$(BIN_NAME): $(OBJECTS)
						     $(CMD_PREFIX)$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

# Add dependency files, if they exist, this is an important directive it replaces many other (.d) files or Makefiles..
 -include $(DEPS)
  
#
# Source file rules
# After the first compilation they will be joined with the rules from the
# # dependency files to provide header dependencies

## this build command will get appended with each dependency file...
	
$(BUILD_PATH)/%.o: $(VPATH)/%.$(SRC_EXT)

	               $(CMD_PREFIX)$(CXX) $(CXXFLAGS) $(INCLUDES) -MP -MMD -c $< -o $@


# Create the directories used in the build
.PHONY: dirs
dirs:
#	@echo "Objects  : $(OBJECTS)"
#	@echo "Sources  : $(SOURCES)" 
	@echo "Creating directories"
	@mkdir -p $(dir $(OBJECTS))
	@mkdir -p $(BIN_PATH)



# Removes all build files
.PHONY: clean
clean:
	@echo "Deleting $(BIN_NAME) symlink"
	@$(RM) $(BIN_NAME)
	@echo "Deleting directories"
	@$(RM) -r build
	@$(RM) -r bin


##########################LIBRARY#####################################
# # ARCHIVE 
  AR ?= ar
  
  LIB_PATH := $(BIN_PATH)
  LIB_NAME := libcoffee.a
  MAIN_OBJ := $(shell find $(BUILD_PATH) -name '*Main.o')
  
## Library is crearted by archiving all .o files and the removing main.o 

lib:
	@echo "Creating Library $(LIB_PATH)/$(LIB_NAME)"
	$(AR) rvs $(LIB_PATH)/$(LIB_NAME) $(OBJECTS)
	$(AR) d  $(LIB_PATH)/$(LIB_NAME) $(MAIN_OBJ)
	
#########################################################################

