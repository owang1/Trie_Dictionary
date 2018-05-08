CXX=		g++
CXXFLAGS=	-g -gdwarf-2 -Wall -std=gnu++11
LD=		g++
LDFLAGS=
AR=		ar
ARFLAGS=	rcs
SHELL=		bash

LIBRARY=	libmap.a
LIB_SRC=    trie.cpp
LIB_OBJ=	$(LIB_SRC:.cpp=.o)

PROGRAMS=	frequencies map_bench

all:		$(LIBRARY) $(PROGRAMS)

%.o:		%.cpp map.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(LIBRARY):	$(LIB_OBJ)
	$(AR) $(ARFLAGS) $@ $(LIB_OBJ)

#map_test:	map_test.o map.h $(LIBRARY)
#	$(LD) $(LDFLAGS) -o $@ $< $(LIBRARY)

map_bench:	map_bench.o map.h $(LIBRARY)
	$(LD) $(LDFLAGS) -o $@ $< $(LIBRARY)

frequencies:	frequencies.o map.h $(LIBRARY)
	$(LD) $(LDFLAGS) -o $@ $< $(LIBRARY)

clean:
	rm -f $(LIBRARY) $(PROGRAMS) *.o

