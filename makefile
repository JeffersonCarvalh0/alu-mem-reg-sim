CXX = g++
CXXFLAGS = -std=c++11 -Wall -I include -g
OBJ = utils.o alucomponents.o alu.o fullalu.o mainmemory.o registers.o main.o\
datapath.o controlunit.o
VPATH = include:src

main : main.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

main.o : main.cpp fullalu.o mainmemory.o registers.o controlunit.o datapath.o

datapath.o : datapath.cpp datapath.h fullalu.o mainmemory.o registers.o\
 controlunit.o defs.h

controlunit.o : controlunit.cpp controlunit.h defs.h

registers.o : registers.cpp registers.h utils.o

mainmemory.o : mainmemory.cpp mainmemory.h defs.h utils.o

fullalu.o : fullalu.cpp fullalu.h alu.o

alu.o : alu.cpp alu.h alucomponents.o

alucomponents.o : alucomponents.cpp alucomponents.h defs.h

utils.o : utils.cpp utils.h defs.h

.PHONY : clean
clean :
	rm main *.o
