// strng.cpp -- strng class methods
#include <cstring>
#include "strng.h"
using std::cout;

int Strng::num_strings = 0;

Strng::Strng(const char * s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
    cout << num_strings << "; \"" << str
         << "\" object created\n";
}

Strng::Strng()
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");
    num_strings++;
    cout << num_strings << ": \"" << str
         << "\" default object created\n";
}

Strng::~Strng()
{
    cout << "\"" << str << "\" object deleted, ";
    --num_strings;
    cout << num_strings << " left\n";
    delete [] str;
}

std::ostream & operator<<(std::ostream & os, const Strng & st)
{
    os << st.str;
    return os;
}