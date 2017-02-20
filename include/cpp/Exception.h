#pragma once

#include <exception>
#include <sstream>

#ifdef EXCEPTION_BOOST_FORMAT
#include <boost/format.hpp>
#endif

class Exception : public std::exception
{
public:

    ~Exception () throw () {}

    Exception (const char* what) throw ();

    Exception (const std::string& what) throw ();

    Exception (const std::ostringstream& what) throw ();

#ifdef EXCEPTION_BOOST_FORMAT
    Exception (const boost::format&) throw ();
#endif

    Exception (const char* file, int line, const char* what) throw ();

    Exception (const char* file, int line, const std::string& what) throw ();

    Exception (const char* file, int line, const std::ostringstream& what) throw ();

#ifdef EXCEPTION_BOOST_FORMAT
    Exception (const char* file, int line, const boost::format&) throw ();
#endif

    const char* what () const throw ();
};

#define EXCEPTION(what) Exception(__FILE__, __LINE__, what)
