// string.cpp -- String class methods
#include <cstring>
#include "string.h"

int String::num_strings = 0;

int String::HowMany()
{
    return num_strings;
}

String::String()
{
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const char * s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
}

String::String(const String & s)
{
    num_strings++;
    len = s.len;
    str = new char [len + 1];
    std::strcpy(str, s.str);
}

String::~String()
{
    --num_strings;
    delete [] str;
}

String & String::operator=(const char s[])
{
    delete [] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

String & String::operator=(const String & st)
{
    if (this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

char & String::operator[](int i)
{
    return str[i];
}

const char & String::operator[](int i) const
{
    return str[i];
}

bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
    return st2 < st1;
}

bool operator==(const String &s1, const String &s2)
{
    return (std::strcmp(s1.str, s2.str));
}

ostream & operator<<(ostream & os, const String & st)
{
    os << st.str;
    return os;
}

istream & operator>>(istream & is, const String &ss)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        ss = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}