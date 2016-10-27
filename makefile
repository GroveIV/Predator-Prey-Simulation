CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS = -Wall
CXXFLAGS = -pedantic-errors
CXXFLAGS = -g

SRC1 = ant.cpp doodleBug.cpp gameboard.cpp main.cpp

HEADER = ant.hpp critter.hpp doodlebug.hpp gameboard.hpp

Assignment1: ${SRC1}  ${Header}
	${CXX} ${CXXFLAGS} ${SRC1}  -o main 

clean:
	 rm -f main
