CC=gcc
CXX=g++-4.8
RM=rm -f
CPPFLAGS=-g -Wall -pedantic
CXXFLAGS=-std=c++11
LDFLAGS=-g
LDLIBS=

SRCS=grammar.cc main.cc icharstream.cc
OBJS=$(subst .cc,.o,$(SRCS))

all: section_2_5

section_2_5: $(OBJS)
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
