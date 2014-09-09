#Folders
SRCDIR = $(shell pwd)/../../src/circuit


#Files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
CHDRS = $(wildcard $(SRCDIR)/*.h)
OBJECTS = $(addsuffix .o, $(notdir $(basename $(SOURCES))))

PCOBJS    = $(addsuffix p,  $(OBJECTS))
DCOBJS    = $(addsuffix d,  $(OBJECTS))
RCOBJS    = $(addsuffix r,  $(OBJECTS))
COPTIMIZE = -O3

#Programs
CPPC = g++ -std=c++0x
DEFINES = -DLINUX
INCLUDES = -I/import/usr/include # -I/usr/local/include/readline
CFLAGS =  -Wall

.PHONY : s p d r build clean depend

s:	CFLAGS+=$(COPTIMIZE) -ggdb -D DEBUG
p:	CFLAGS+=$(COPTIMIZE) -pg -ggdb -D DEBUG
d:	CFLAGS+=-O0 -ggdb -D DEBUG
r:	CFLAGS+=$(COPTIMIZE) -D NDEBUG

s:	circuitlib.a
p:	circuitlib.ap
d:	circuitlib.ad
r:	circuitlib.ar

#rules
.SUFFIXES: .a .o .cpp

circuitlib : circuitlib.a

circuitlib.a : $(OBJECTS)
	ar rv $@ $(OBJECTS)
	ranlib circuitlib.a

circuitlib.ap : $(PCOBJS)
	ar rv $@ $(PCOBJS)
	ranlib circuitlib.ap

circuitlib.ad : $(DCOBJS)
	ar rv $@ $(DCOBJS)
	ranlib circuitlib.ad

circuitlib.ar : $(RCOBJS)
	ar rv $@ $(RCOBJS)
	ranlib circuitlib.ar


%.o %.op %.od %.or: $(SRCDIR)/%.cpp 
	$(CPPC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJECTS) $(PCOBJS) $(DCOBJS) $(RCOBJS) circuitlib.* depend.mak;

## Make dependencies
depend:	depend.mak
depend.mak: $(SOURCES) $(CHDRS)
	@echo Making dependencies ...
	@$(CPPC) -MM $(SOURCES) > depend.mak
	@cp depend.mak /tmp/depend.mak.tmp
	@sed "s/o:/op:/" /tmp/depend.mak.tmp >> depend.mak
	@sed "s/o:/od:/" /tmp/depend.mak.tmp >> depend.mak
	@sed "s/o:/or:/" /tmp/depend.mak.tmp >> depend.mak
	@rm /tmp/depend.mak.tmp

include depend.mak
