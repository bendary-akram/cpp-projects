
CC = g++
#PROJECT_NAME = $(1)
BIN_DIR = $(PWD)\bin
SQLITE_DIR = $(PWD)\sqlite3
INC_DIR = -I$(SQLITE_DIR)
CFLAGS =-c -Wall -I$(INC_DIR)
#LIB=-lsqlite3


#01_Hello_SRC=.\01_Hello\hi.cpp

#all : 01_Hello 02_bookshop_management_system
 
#01_Hello: TARGET=01_Hello
 
#01_Hello: all

#all: ; @echo $($(TARGET)_SRC)
################################# Hello #############################################
01_Hello : $(BIN_DIR)\01_Hello.o
	$(CC) -o $(BIN_DIR)\01_Hello $(BIN_DIR)\01_Hello.o
	

$(BIN_DIR)\01_Hello.o: .\01_Hello\hi.cpp
	$(CC) -c .\01_Hello\hi.cpp -o $(BIN_DIR)\01_Hello.o
	
##############################################################################

################################# 02_bookshop_management_system #############################################
02_bookshop_management_system : $(BIN_DIR)\sqlite.o $(BIN_DIR)\02_bookshop_management_system.o  $(BIN_DIR)\Books.o 
	$(CC) -o $(BIN_DIR)\02_bookshop_management_system \
	 			$(BIN_DIR)\02_bookshop_management_system.o \
	 			$(BIN_DIR)\Books.o \
	 			$(BIN_DIR)\sqlite.o

$(BIN_DIR)\02_bookshop_management_system.o: .\02_bookshop_management_system\main.cpp
	$(CC) -c .\02_bookshop_management_system\main.cpp -o $(BIN_DIR)\02_bookshop_management_system.o
	
$(BIN_DIR)\Books.o: .\02_bookshop_management_system\Books.cpp
	$(CC) $(INC_DIR) -c .\02_bookshop_management_system\Books.cpp -o $(BIN_DIR)\Books.o
	
$(BIN_DIR)\sqlite.o: $(SQLITE_DIR)\sqlite3.c
	gcc -c $(SQLITE_DIR)\sqlite3.c -o $(BIN_DIR)\sqlite.o

##############################################################################

clean:
	del *.o $(BIN_DIR)\*.o $(BIN_DIR)\*.exe


