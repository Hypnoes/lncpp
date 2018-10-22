// string.h -- fixed and augmented string class definition
#ifndef STRING_H_
#define STRING_H_
#include <iostream>
using std::ostream;
using std::istream;

class String
{
  private:
    char * str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;

  public:
    String();
    String(const char *s);
    String(const String &);
    ~String();
    int length() const { return len; }

    String & operator=(const char []);
    String & operator=(const String &);
    char & operator[](int i);
    const char & operator[](int i) const;

    friend bool operator<(const String &st1, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st1, const String &st2);
    friend ostream & operator<<(ostream & os, const String & st);
    friend istream & operator>>(istream & is, const String & st);

    static int HowMany();
};
#endif