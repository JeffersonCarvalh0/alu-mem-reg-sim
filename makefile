CXX = g++
CXXFLAGS = -std=c++11 -Wall -I include
OBJ = alu.o alucomponents.o fullalu.o mainmemory.o registers.o main.o
VPATH = include:src

main : main.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

main.o : main.cpp fullalu.o mainmemory.o registers.o

registers.o : registers.cpp registers.h

mainmemory.o : mainmemory.h mainmemory.cpp defs.h

fullalu.o : fullalu.cpp fullalu.h alu.o

alu.o : alu.cpp alu.h alucomponents.o

alucomponents.o : alucomponents.cpp alucomponents.h defs.h

.PHONY : clean
clean :
	rm main *.o
