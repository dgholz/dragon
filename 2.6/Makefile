CC=gcc
CXX=g++-4.8
RM=rm -f
CPPFLAGS=-g -Wall -pedantic
CXXFLAGS=-std=c++11
LDFLAGS=-g
LDLIBS=

SRCS=Parser.cc main.cc
OBJS=$(subst .cc,.o,$(SRCS))

all: parser

parser: $(OBJS)
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
