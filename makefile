CXX = g++
SRCS = board.cpp player.cpp game.cpp connect-four.cpp
OBJS =  board.o player.o game.o connect-four.o
HEADERS = board.h player.h game.h

connect-four: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o connect-four -municode

${OBJS}: ${SRCS}
	${CXX} -c $(@:.o=.cpp)

clean:
	rm ${OBJS}