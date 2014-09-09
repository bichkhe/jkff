# Author: Raik Brinkmann, Patrick Pastoor
# Copyright: Infineon Technologies AG, 2005
SRCDIR = $(shell pwd)/../../src/verilogparser

RM := rm -rf

OBJS = VerilogParser.o VerilogParserFunction.o VerilogScanner.o VerilogScannerFunction.o

d:libverilogparser.a
	cp libverilogparser.a libverilogparser.ad

r:libverilogparser.a
	cp libverilogparser.a libverilogparser.ar

p:libverilogparser.a
	cp libverilogparser.a libverilogparser.ap

s:libverilogparser.a
	cp libverilogparser.a libverilogparser.ar


libverilogparser.a: $(OBJS)
	ar rs $@ $(OBJS)

VerilogScannerFunction.o: $(SRCDIR)/VerilogScannerFunction.cpp

$(SRCDIR)/VerilogScannerFunction.cpp: $(SRCDIR)/Verilog.l $(SRCDIR)/FlexLexer.h
	(echo "#define FlexLexer FCK_VerilogFlexLexer" ; flex -L -8 -f -t -i $(SRCDIR)/Verilog.l) > $(SRCDIR)/VerilogScannerFunction.cpp

VerilogParserFunction.o: $(SRCDIR)/VerilogParserFunction.cpp

$(SRCDIR)/VerilogParserFunction.cpp: $(SRCDIR)/Verilog.y
	bison  -l -d -v -o $(SRCDIR)/VerilogParserFunction.c $(SRCDIR)/Verilog.y
	sed -e "s/int yyparse (void \*);/\/\/@/" \
	-e "s/int yyparse (void);/\/\/@/" \
	-e "s/^YYPARSE_RETURN_TYPE yyparse/\/\/&/" \
	-e "s/^yyparse (void);/thisisadirtytrickVERILOG;/" \
	-e "s/^yyparse (void \*);/thisisadirtytrickVERILOG;/" \
	-e "s/__attribute__ ((__unused__))/\/\/&/" \
		< $(SRCDIR)/VerilogParserFunction.c > $(SRCDIR)/VerilogParserFunction.cn
	rm -f $(SRCDIR)/VerilogParserFunction.c
	mv $(SRCDIR)/VerilogParserFunction.cn $(SRCDIR)/VerilogParserFunction.cpp \
		|| ( rm $(SRCDIR)/VerilogParserFunction.cpp && exit 1 )


clean:
	$(RM) $(OBJS) libverilogparser.a $(SRCDIR)/VerilogParserFunction.cpp $(SRCDIR)/VerilogScannerFunction.cpp $(SRCDIR)/VerilogParserFunction.h $(SRCDIR)/VerilogParserFunction.output $(SRCDIR)/VerilogParserFunction.c
	$(RM) -rf doc

%.o: $(SRCDIR)/%.cpp
	g++ -std=gnu++0x -g -c -o $@ $?
doxy:
	doxygen
