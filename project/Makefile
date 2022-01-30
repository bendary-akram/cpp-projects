
# It is likely that default C compiler is already gcc, but explicitly
# set, just to be sure
CXX = g++
CC = gcc

# The CXXFLAGS variable sets compile flags for gcc:
#  -g        	compile with debug information
#  -Wall     	give verbose compiler warnings
#  -O0       	do not optimize generated code
#  -std=c++11  use the c++11 standard language definition
#	-c			Compiler source(s) to object-code (input to linker).
CXXFLAGS = -c -g -Wall -O0 -std=c++14

# The CXXFLAGS variable sets compile flags for gcc:
#  -g        	compile with debug information
#  -Wall     	give verbose compiler warnings
#  -O0       	do not optimize generated code
#  -std=c99  use the c99 standard language definition
#	-c			Compiler source(s) to object-code (input to linker).
CFLAGS = -c -g -O0 -std=c99

# The LDFLAGS variable sets flags for linker
#  -lm   says to link in libm (the math library)
LDFLAGS =

# In this section, you list the files that are part of the project.
# If you add/change names of source files, here is where you
# edit the Makefile.
#01_Hello: TARGET=01_Hello
#02_bookshop_management_system: TARGET=02_bookshop_management_system

#SOURCES = $(SQLITE_DIR)\sqlite3.c .\02_bookshop_management_system\Books.cpp .\02_bookshop_management_system\main.cpp
02_bookshop_management_system_SRC = $(SQLITE_DIR)\sqlite3.c .\02_bookshop_management_system\Books.cpp .\02_bookshop_management_system\main.cpp

# https://www.gnu.org/software/make/manual/html_node/Text-Functions.html
#OBJECTS = $(SOURCES:.c=.o)
#OBJECTS = $($(TARGET)_SRC:.c=.o)
#OBJECTS = $($(TARGET)_SRC:.cpp=.o)
OBJECTS_CPP=$(filter %.cpp,$($(TARGET)_SRC))
OBJECTS_C=$(filter %.c,$($(TARGET)_SRC))
OBJECTS=$(OBJECTS_CPP:.cpp=.o) $(OBJECTS_C:.c=.o)

#OBJECTS=$(filter %$(FILTERS),$($(TARGET)_SRC)):.cpp=.o

#PROJECT_NAME = $(1)
BIN_DIR = $(PWD)\bin
SQLITE_DIR = $(PWD)\sqlite3
INC_DIR = -I$(SQLITE_DIR)
#CXXFLAGS =-c -Wall -I$(INC_DIR)
#LIB=-lsqlite3

# The first target defined in the makefile is the one
# used when make is invoked with no argument. Given the definitions
# above, this Makefile file will build the one named TARGET and
# assume that it depends on all the named OBJECTS files.

#$(TARGET) : $(OBJECTS)
#	@echo $(OBJECTS)
#	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

#01_Hello_SRC=.\01_Hello\hi.cpp


 
 
#02_bookshop_management_system: all

#.PHONY: all
#all: $(OBJECTS) 
#	@echo $($(TARGET)_SRC) 
#	@echo $(OBJECTS)

#$(filter %.o,$(OBJECTS)): %.o: %.cpp
#	echo "target: $@ prereq: $<"
	
#%.cpp:
	#$(CXX) $(CXXFLAGS) -o $(OBJECTS) $($(TARGET)_SRC) $(LDFLAGS)
#	@echo Hiiii
#	$(CXX) -c $(CXXFLAGS)  $< -o $@
#$(OBJECTS): $($(TARGET)_SRC)
	#$(CXX) $(CXXFLAGS) -o $(OBJECTS) $($(TARGET)_SRC) $(LDFLAGS)
#	@echo Hiiii
#	$(CXX) -c $(CXXFLAGS)  $< -o $@


all : 01_Hello 02_bookshop_management_system
################################# Hello #############################################
01_Hello : $(BIN_DIR)\01_Hello.o
	$(CXX) -o $(BIN_DIR)\01_Hello $(BIN_DIR)\01_Hello.o
	

$(BIN_DIR)\01_Hello.o: .\01_Hello\hi.cpp
	$(CXX) $(CXXFLAGS) .\01_Hello\hi.cpp -o $(BIN_DIR)\01_Hello.o
	
##############################################################################

################################# 02_bookshop_management_system ##############################################
02_bookshop_management_system : $(BIN_DIR)\sqlite.o $(BIN_DIR)\02_bookshop_management_system.o  \
								$(BIN_DIR)\Bookshop.o $(BIN_DIR)\Books.o $(BIN_DIR)\Suppliers.o \
								$(BIN_DIR)\Purchases.o 
								
	$(CXX) -o $(BIN_DIR)\02_bookshop_management_system \
	 			$(BIN_DIR)\02_bookshop_management_system.o \
	 			$(BIN_DIR)\Bookshop.o \
	 			$(BIN_DIR)\Books.o \
	 			$(BIN_DIR)\Suppliers.o \
	 			$(BIN_DIR)\Purchases.o \
	 			$(BIN_DIR)\sqlite.o

$(BIN_DIR)\02_bookshop_management_system.o: .\02_bookshop_management_system\main.cpp
	$(CXX) $(CXXFLAGS) .\02_bookshop_management_system\main.cpp -o $(BIN_DIR)\02_bookshop_management_system.o
	
$(BIN_DIR)\Books.o: .\02_bookshop_management_system\Books.cpp
	$(CXX) $(INC_DIR) $(CXXFLAGS) .\02_bookshop_management_system\Books.cpp -o $(BIN_DIR)\Books.o
	
$(BIN_DIR)\Bookshop.o: .\02_bookshop_management_system\Bookshop.cpp
	$(CXX) $(INC_DIR) $(CXXFLAGS) .\02_bookshop_management_system\Bookshop.cpp -o $(BIN_DIR)\Bookshop.o

$(BIN_DIR)\Suppliers.o: .\02_bookshop_management_system\Suppliers.cpp
	$(CXX) $(INC_DIR) $(CXXFLAGS) .\02_bookshop_management_system\Suppliers.cpp -o $(BIN_DIR)\Suppliers.o

$(BIN_DIR)\Purchases.o: .\02_bookshop_management_system\Purchases.cpp
	$(CXX) $(INC_DIR) $(CXXFLAGS) .\02_bookshop_management_system\Purchases.cpp -o $(BIN_DIR)\Purchases.o
		
$(BIN_DIR)\sqlite.o: $(SQLITE_DIR)\sqlite3.c
	$(CC) $(CFLAGS) $(SQLITE_DIR)\sqlite3.c -o $(BIN_DIR)\sqlite.o

##############################################################################
.PHONY: clean

clean:
	del *.o $(BIN_DIR)\*.o $(BIN_DIR)\*.exe


