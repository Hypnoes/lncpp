// strng.h -- flawed string class definition

#include <iostream>

#ifndef STRNG_H_
#define STRNG_H_

class Strng
{
  public:
    Strng(const char * s);
    Strng();
    ~Strng();

    friend std::ostream & operator<<(std::ostream & os,
                            const Strng & st);
    
  private:
    char * str;
    int len;
    static int num_strings;
};

#endif