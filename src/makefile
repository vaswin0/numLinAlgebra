CC =  g++
CFLAGS = -Wall -g


main: main.o Matrix.o matrixUtils.o
	$(CC) $(CFLAGS) -o main main.o Matrix.o matrixUtils.o

main.o: main.cpp Matrix.h  
	$(CC) $(CFLAGS) -c main.cpp 

Matrix.o: Matrix.cpp Matrix.h
	$(CC) $(FLAGS) -c Matrix.cpp

matrixUtils.o: matrixUtils.cpp Matrix.h
	$(CC) $(CFLAGS) -c matrixUtils.cpp


clean:
	rm *.o main
