PROGNAME = JKPROJECT

CC = gcc
CPPC = g++ -std=gnu++0x
DEFINES = -DLINUX
INCLUDES = -I/import/usr/include # -I/usr/local/include/readline
OPT = -g -DDEBUG  

CFLAGS = -Wall -ffloat-store

LINK = g++ -std=gnu++0x
CFLAGS    = -Wall -ffloat-store
COPTIMIZE = -O3

CSRCS     = main.cpp

OBJFILES = main.o 
PCOBJS    = $(addsuffix p,  $(OBJFILES))
DCOBJS    = $(addsuffix d,  $(OBJFILES))
RCOBJS    = $(addsuffix r,  $(OBJFILES))

LIBLOC =  $(wildcard ../../libs/circuit/circuitlib.a) \
          #$(wildcard ../../libs/verilogparser/libverilogparser.a)



PCLIBLOC = $(addsuffix p,  $(LIBLOC))

DCLIBLOC = $(addsuffix d,  $(LIBLOC))

RCLIBLOC = $(addsuffix r,  $(LIBLOC)) 

.PHONY : s p d r build clean depend

s:	WAY=standard
p:	WAY=profile
d:	WAY=debug
r:	WAY=release
rs:	WAY=release static

s:	CFLAGS+=$(COPTIMIZE) -ggdb -D DEBUG
p:	CFLAGS+=$(COPTIMIZE) -pg -ggdb -D DEBUG
d:	CFLAGS+=-O0 -ggdb -D DEBUG
r:	CFLAGS+=$(COPTIMIZE) -D NDEBUG
rs:	CFLAGS+=$(COPTIMIZE) -D NDEBUG

s:	build $(PROGNAME)_exe
p:	build $(PROGNAME)_profile
d:	build $(PROGNAME)_debug
r:	build $(PROGNAME)_release
rs:	build $(PROGNAME)_static

build:
	@echo Building $(EXEC) "("$(WAY)")"

$(PROGNAME)_exe: main.o circuitmake #verilogparsermake
	$(LINK) -o $(PROGNAME) $(OBJFILES) $(LIBLOC) -lz -ggdb -Wall

%.o  %.op %.od %.or: %.cpp 
	$(CPPC) $(CFLAGS) -o $@ -c $<

#Circuit FCK
circuitmake:
	cd ../../libs/circuit; make

#verilogparsermake:
#	cd ../../libs/verilogparser; make


clean:
	rm -f $(PROGNAME) $(PROGNAME)_debug $(PROGNAME)_release $(PROGNAME)_profile  $(OBJFILES) $(PCOBJS) $(DCOBJS) $(RCOBJS) depend.mak
	cd ../../libs/circuit; make clean
#	cd ../../libs/verilogparser; make clean

## Make dependencies
#depend:	depend.mak
#depend.mak: $(CSRCS) $(CHDRS)
#	@echo Making dependencies ...
#	@$(CPPC) -MM $(CSRCS) > depend.mak
#	@cp depend.mak /tmp/depend.mak.tmp
#	@sed "s/o:/op:/" /tmp/depend.mak.tmp >> depend.mak
#	@sed "s/o:/od:/" /tmp/depend.mak.tmp >> depend.mak
#	@sed "s/o:/or:/" /tmp/depend.mak.tmp >> depend.mak
#	@rm /tmp/depend.mak.tmp

#include depend.mak
