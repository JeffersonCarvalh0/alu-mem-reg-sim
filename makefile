CXX = g++
CXXFLAGS = -std=c++11 -Wall -I include
OBJ = alu.o alucomponents.o fullalu.o control.o main.o
VPATH = include:src

main : main.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

main.o : main.cpp fullalu.o control.o

control.o: control.cpp

fullalu.o : fullalu.cpp fullalu.h alu.o

alu.o : alu.cpp alu.h alucomponents.o

alucomponents.o : alucomponents.cpp alucomponents.h

.PHONY : clean
clean :
	rm main *.o
