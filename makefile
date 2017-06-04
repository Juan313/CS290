CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors 
CXXFLAGS += -g
LDFLAGS = -lboost_date_time


OBJS = input.o  main.o

SRCS = input.cpp  main.cpp

HEADERS = input.hpp 

prog: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o prog

${OBJS}:${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
clean:
	rm *o prog
