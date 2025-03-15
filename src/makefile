# src/makefile

CC = g++
CFLAGS = -Wall -g -O3 -std=c++17 -fPIC
PYBIND11_INCLUDE = $(shell python3.9 -m pybind11 --includes)
MATRIX_MODULE = matrix$(shell python3.9-config --extension-suffix)

all: clean main run


main: main.o Matrix.o matrixdecomp.o matrixUtils.o
	$(CC) $(CFLAGS) -o main main.o Matrix.o matrixdecomp.o matrixUtils.o

wrapper: wrapper.o Matrix.o matrixdecomp.o matrixUtils.o
	$(CC) $(CFLAGS) $(PYBIND11_INCLUDE) -shared -o $(MATRIX_MODULE) wrapper.o Matrix.o matrixdecomp.o matrixUtils.o

# main.o: main.cpp Matrix.h
#	$(CC) $(CFLAGS) -c main.cpp

# Matrix.o: Matrix.cpp Matrix.h
#	$(CC) $(CFLAGS) -c Matrix.cpp

# matrixUtils.o: matrixUtils.cpp Matrix.h
#	$(CC) $(CFLAGS) -c matrixUtils.cpp

# matrixdecomp.o: matrixdecomp.cpp Matrix.h
#	$(CC) $(CFLAGS) -c matrixdecomp.cpp

# wrapper.o: wrapper.cpp Matrix.h
#	$(CC) $(CFLAGS) $(PYBIND11_INCLUDE) -c wrapper.cpp


%.o: %.cpp Matrix.h
	$(CC) $(CFLAGS) -c $<

run:
	./main




clean:
	rm -f *.o main $(MATRIX_MODULE)

