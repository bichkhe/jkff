/**
 * @file   VerilogException.h
 * @author Minh D. Nguyen
 * @date   Tue Apr  3 10:49:28 2012
 * 
 * @brief  Exception that will be thrown by Verilog parser functions 
 * 
 * 
 */


#ifndef _VERILOG_EXCEPTION_H__
#define _VERILOG_EXCEPTION_H__

#include <exception>
#include <string>
#include <sstream>

//! \brief This exception is thrown by \a VerilogParser::parse() on an error.
//! It contains the reason (error message), the source (factory, parser or scanner),
//! the line number (in the stream) and the token (keyword) where the error occured.
class VerilogException : public std::exception
{
public:
	enum Type {FACTORY_ERROR, PARSER_ERROR, SCANNER_ERROR};

	VerilogException(const Type type, const std::string& what,
					unsigned line_no,
					const char* token)
			: m_Type(type), m_What(what),
			  m_LineNo(line_no), m_Token(token){}
	~VerilogException() throw() {}
	const char* what() const throw() { return m_What.c_str(); }
	Type type() const throw() { return m_Type; }
	const char* getAllInfo() const throw()
	{
		std::string type;
		if(m_Type == FACTORY_ERROR){
			type = "Factory";
		}else if(m_Type == PARSER_ERROR){
			type = "Parser";
		}else {
			type = "Scanner";
		}
		std::ostringstream itoa; itoa << m_LineNo;
		std::string lineNoStr(itoa.str());

		std::string info =
				type + "-Error '" + std::string(what()) +
				"' in line " + lineNoStr +
				" at '" + std::string(m_Token) + "'";
		return info.c_str();
	}

private:
	const Type			m_Type;
	const std::string	m_What;
	const unsigned		m_LineNo;
	const char*			m_Token;
};

#endif
