CC=gcc
CXX=g++-4.8
RM=rm -f
CPPFLAGS=-g -Wall -pedantic
CXXFLAGS=-std=c++11 
LDFLAGS=-g
LDLIBS=

SRCS=a.cc b.cc c.cc main.cc
OBJS=$(subst .cc,.o,$(SRCS))

all: exercise_2_4_1

exercise_2_4_1: $(OBJS)
	    $(CXX) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS) 

clean:
	$(RM) $(OBJS)
