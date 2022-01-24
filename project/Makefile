
CC = g++
#PROJECT_NAME = $(1)
BIN_DIR = $(PWD)\bin

all : 01_Hello
 

################################# Hello #############################################
01_Hello : $(BIN_DIR)\01_Hello.o
	$(CC) -o $(BIN_DIR)\01_Hello $(BIN_DIR)\01_Hello.o
	

$(BIN_DIR)\01_Hello.o: .\01_Hello\hi.cpp
	$(CC) -c .\01_Hello\hi.cpp -o $(BIN_DIR)\01_Hello.o
	
##############################################################################

clean:
	del *.o $(BIN_DIR)\*.o $(BIN_DIR)\*.exe


