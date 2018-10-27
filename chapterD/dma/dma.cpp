// dma.cpp -- dam class methods

#include <cstring>
#include "dma.h"

// baseDMA methods
BaseDMA::BaseDMA(const char * l, int r)
{
    _label = new char[std::strlen(l) + 1];
    std::strcpy(_label, l);
    _rating = r;
}

BaseDMA::BaseDMA(const BaseDMA & rs)
{
    _label = new char[std::strlen(rs._label) + 1];
    std::strcpy(_label, rs._label);
    _rating = rs._rating;
}

BaseDMA::~BaseDMA()
{
    delete [] _label;
}

BaseDMA & BaseDMA::operator=(const BaseDMA & rs)
{
    if (this == &rs)
        return *this;
    delete [] _label;
    _label = new char[std::strlen(rs._label) + 1];
    std::strcpy(_label, rs._label);
    _rating = rs._rating;
    return *this;
}

std::ostream & operator<<(std::ostream & os, const BaseDMA & rs)
{
    os << "Label: " << rs._label << std::endl;
    os << "Rating: " << rs._rating << std::endl;
    return os;
}

// lacksDMA methods
LacksDMA::LacksDMA(const char * c, const char *l, int r) : BaseDMA(l, r)
{
    std:strncpy(_color, c, 39);
    _color[39] = '\0';
}

LacksDMA::LacksDMA(const char * c, const BaseDMA & rs) : BaseDMA(rs)
{
    std::strncpy(_color, c, _COL_LEN - 1);
    _color[_COL_LEN - 1] = '\0';
}

std::ostream & operator<<(std::ostream & os, const LacksDMA & ls)
{
    os << (const BaseDMA &) ls;
    os << "Color: " << ls._color << std::endl;
    return os;
}

// hasDMA methods
HasDMA::HasDMA(const char * s, const char * l, int r) : BaseDMA(l, r)
{
    _style = new char[std::strlen(s) + 1];
    std::strcpy(_style, s);
}

HasDMA::HasDMA(const char * s, const BaseDMA & rs) : BaseDMA(rs)
{
    _style = new char[std::strlen(s) + 1];
    std::strcpy(_style, s);
}

HasDMA::HasDMA(const HasDMA & hs) : BaseDMA(hs)
{
    _style = new char[std::strlen(hs._style) + 1];
    std::strcpy(_style, hs._style);
}

HasDMA::~HasDMA()
{
    delete [] _style;
}

HasDMA & HasDMA::operator=(const HasDMA & hs)
{
    if (this == &hs)
        return * this;
    BaseDMA::operator=(hs);
    delete [] _style;
    _style = new char[std::strlen(hs._style) + 1];
    std::strcpy(_style, hs._style);
    return *this;
}

std::ostream & operator<<(std::ostream & os, const HasDMA & hs)
{
    os << (const BaseDMA &) hs;
    os << "Style: " << hs._style << std::endl;
    return os;
}