/**
 * @file   VerilogParser.cpp
 * @author Minh D. Nguyen
 * @date   Tue Apr  3 10:46:58 2012
 * 
 * @brief  Implementation of Verilog Parser
 * 
 * 
 */


#include <fstream>
#include <iostream>
#include "VerilogScanner.h"
#include "VerilogParser.h"
#include "VerilogException.h"

using namespace std;

// Global point of Verilog Parser which it will used in .l
VerilogParser* VP;

VerilogParser::VerilogParser(VerilogFactory* factory, string logFilename)
	: mFactory(factory)
{
	mLogStream.open(logFilename.c_str());
	mScanner = new VerilogScanner;
}

VerilogParser::~VerilogParser()
{ delete mScanner; }

int VerilogParser::yylex()
{ return mScanner->yylex();}

bool
VerilogParser::parse(std::istream& inputstream)
{
	mScanner->switch_streams(&inputstream, 0);
	return yyparse() == 0;
}

void
VerilogParser::yyerror(const char* msg) const
{
	throw VerilogException(VerilogException::PARSER_ERROR, msg, mScanner->lineno(), mScanner->YYText());
}
void VerilogParser::YYTRACE(const char* msg) const
{
		std::cout <<  lineNo << " : " << msg << endl;
}

/*
unsigned VerilogParser::TwoPowX(unsigned x) const
{
	unsigned result = 1;
	for(unsigned i = 1; i < x; ++i)
		result *= 2;
	return result;
}

unsigned VerilogParser::toUnsigned(const std::string& value_of_constant) const
{
	if (value_of_constant.size() > 32) {
		throw VerilogFactory::Exception("Constant value out of bound.");
	}
	unsigned res = 0;
	for(unsigned i = 0; i < value_of_constant.size(); ++i)
	{
		if(value_of_constant[i] == '1')
			res += TwoPowX(value_of_constant.size()-i);
		}
	return res;
}
*/
