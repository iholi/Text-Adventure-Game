CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o engine.o player.o world.o location.o list.o item.o

SRCS = main.cpp engine.cpp player.cpp world.cpp location.cpp list.cpp item.cpp

HEADERS = engine.h player.h world.h location.h list.h item.h

SGame: ${OBJS} ${HEADERS}  
	${CXX} ${LDFLAGS} ${OBJS} -o Game

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f *.o
	rm -f Game
