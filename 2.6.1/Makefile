CC=gcc
CXX=g++-4.8
RM=rm -f
CPPFLAGS=-ggdb3 -Wall -pedantic -O0
CXXFLAGS=-std=c++11
LDFLAGS=-g
LDLIBS=-lboost_regex

SRCS=main.cc Tokenizer.cc
OBJS=$(subst .cc,.o,$(SRCS))

all: exercise_2_6_1

exercise_2_6_1: $(OBJS)
	    g++ $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

depend: .depend

.depend: $(SRCS)
	    rm -f ./.depend
		    $(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

dist-clean: clean
	    $(RM) *~ .dependtool

export PATH := $(PATH):.

test: all
	find t -perm /a+x -a -type f | sort | while read test; do eval $${test}; done
