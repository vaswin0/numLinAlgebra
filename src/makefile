CC =  g++
CFLAGS = -Wall -g


main: main.o Matrix.o
		$(CC) $(CFLAGS) -o main main.o Matrix.o

main.o: main.cpp Matrix.h  
		$(CC) $(CFLAGS) -c main.cpp 

Matrix.o: Matrix.h


clean:
	rm *.o main
