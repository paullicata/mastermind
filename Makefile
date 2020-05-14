CXX=g++
RM=rm -f
CPPFLAGS=-g
LDFLAGS=-g
LDLIBS=

SRCS=mastermind.cpp board.cpp code.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: mastermind

mastermind: $(OBJS)
	$(CXX) $(LDFLAGS) -o mastermind $(OBJS) $(LDLIBS)

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) *~ .depend

include .depend
