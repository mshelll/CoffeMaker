###################################################################   UNIT TEST  #####################


############  COMMON VARIABLES  #################

# Shell used in this makefile
# # bash is used for 'echo -en'
  SHELL = /bin/bash


# # Compiler used
  CXX ?= g++
  
# # General compiler flags
  COMPILE_FLAGS =  -Wall -Wextra -g 
  
  LINK_FLAGS :=  -L
  

#
  CMD_PREFIX := 
  
# # Extension of source files used in the project
  SRC_EXT = cpp

############  COMMON VARIABLES  #################  
  

 TEST_SRC_PATH := ./src 
 
 VPATH  := ./src
 
 COFFEE_HOME := ..

 GMOCK_INCLUDE_PATH := /opt/gmock-1.7.0/include/
   
 GTEST_INCLUDE_PATH := /opt/gmock-1.7.0/gtest/include/
 
 SOURCE_INCLUDE_PATH := $(COFFEE_HOME)/src
 
 TEST_INCLUDE_PATH := ./src

 INCLUDES :=  -I $(GMOCK_INCLUDE_PATH) -I $(SOURCE_INCLUDE_PATH) -I $(TEST_INCLUDE_PATH)
 
 GTEST_LIB := -lgtest -lgtest_main
 
 GMOCK_LIB := -lgmock -lgmock_main 
 
 PTHREAD_LIB := -lpthread
 
 COFFEE_LIB := -lcoffee
 
 COFFEE_LIB_PATH := $(COFFEE_HOME)/bin/
 
 TEST_BIN_NAME := coffee_test
 
 # Build and output paths

  export TEST_BUILD_PATH := ./build
  export TEST_BIN_PATH := ./bin
  
#  Combine compiler and linker flags
   CXXFLAGS := $(CXXFLAGS) $(COMPILE_FLAGS) $(RCOMPILE_FLAGS)
   LDFLAGS := $(LDFLAGS) $(LINK_FLAGS) $(COFFEE_LIB_PATH) $(RLINK_FLAGS) $(GMOCK_LIB) $(GTEST_LIB) $(PTHREAD_LIB) $(COFFEE_LIB)
  
# Find all source files in the source directory, sorted by most
#  recently modified
  TEST_SOURCES = $(shell find $(VPATH)/ -name '*.$(SRC_EXT)' -printf '%T@\t%p\n' \
             | sort -k 1nr | cut -f2-)
#fallback in case the above fails
  rwildcard = $(foreach d, $(wildcard $1*), $(call rwildcard,$d/,$2) \
	# $(filter $(subst *,%,$2), $d))

ifeq ($(TEST_SOURCES),)
  TEST_SOURCES := $(call rwildcard, $(VPATH)/, *.$(SRC_EXT))
endif

#Get the object file names, with the source directory stripped
#from the path, and the build path prepended in its place
  TEST_OBJECTS = $(TEST_SOURCES:$(VPATH)/%.$(SRC_EXT)=$(TEST_BUILD_PATH)/%.o)
  
# # Set the dependency files that will be used to add header dependencies
  TEST_DEPS = $(TEST_OBJECTS:.o=.d)
  
   
 # # Main rule, checks the executable and symlinks to the output
 all: $(TEST_BIN_PATH)/$(TEST_BIN_NAME)

# Link the executable

    $(TEST_BIN_PATH)/$(TEST_BIN_NAME): $(TEST_OBJECTS)
						   			   $(CMD_PREFIX)$(CXX) $(TEST_OBJECTS) $(LDFLAGS) -o $@

# Add dependency files, if they exist, this is an important directive it replaces many other (.d) files or Makefiles..
 -include $(TEST_DEPS)
  
#
# Source file rules
# After the first compilation they will be joined with the rules from the
# # dependency files to provide header dependencies

## this build command will get appended with each dependency file...
	
$(TEST_BUILD_PATH)/%.o: $(VPATH)/%.$(SRC_EXT)

	               		$(CMD_PREFIX)$(CXX) $(CXXFLAGS) $(INCLUDES)  -MP -MMD -c $< -o $@  

# Create the directories used in the build
.PHONY: dirs
dirs:
#	@echo "Objects  : $(TEST_OBJECTS)"
#	@echo "Sources  : $(TEST_SOURCES)"
	@echo "Creating directories"
	@mkdir -p $(dir $(TEST_OBJECTS))
	@mkdir -p $(TEST_BIN_PATH)
						 
						    		   

# Removes all build files
.PHONY: clean
clean:
	@echo "Deleting $(TEST_BIN_NAME) symlink"
	@$(RM) $(TEST_BIN_NAME)
	@echo "Deleting directories"
	@$(RM) -r build
	@$(RM) -r bin
	
	
### rule to rebuild  

 rebuild: clean dirs lib all 		
 
 
 ##########################LIBRARY#####################################
# # ARCHIVE 
  AR ?= ar
  
  LIB_PATH := $(BIN_PATH)
  LIB_NAME := libcoffee.a
  MAIN_OBJ := $(shell find $(BUILD_PATH) -name '*Main.o')
  
## Library is crearted by archiving all .o files and the removing main.o 

lib:
	@echo "Building Library $(LIB_PATH)/$(LIB_NAME)"
	make -C $(COFFEE_HOME) rebuild
	$(AR) rvs $(LIB_PATH)/$(LIB_NAME) $(OBJECTS)
	$(AR) d  $(LIB_PATH)/$(LIB_NAME) $(MAIN_OBJ)
	
#########################################################################					    		   					    		   
						    		   