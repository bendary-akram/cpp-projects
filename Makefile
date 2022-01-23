
CC = g++
#PROJECT_NAME = $(1)
BIN_DIR = .\bin

 


01_Hello : $(BIN_DIR)\01_Hello.o
	$(CC) -o $(BIN_DIR)\01_Hello $(BIN_DIR)\01_Hello.o
	

$(BIN_DIR)\01_Hello.o: .\01_Hello\hi.cpp
	$(CC) -c .\01_Hello\hi.cpp -o $(BIN_DIR)\01_Hello.o

clean:
	rm -rf *o $(BIN_DIR)\01_Hello.o