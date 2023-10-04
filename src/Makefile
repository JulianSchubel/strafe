CC=g++
OPTIONS=-Wall
BINARY=main
VENDOR_LINKAGE=-l sfml-graphics -l sfml-window -l sfml-system
LINKAGE=./include/game_state/game_state.cpp
EXECUTABLE_NAME=my_game

all: ${BINARY}

% : %.cpp
	# symbols are request first and then linked in from a library that has them. That is, need to specify modules first the libraries
	${CC} ${OPTIONS} -o ${EXECUTABLE_NAME} $<	${LINKAGE} ${VENDOR_LINKAGE}

