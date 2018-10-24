// tabtenn1.cpp -- simple base-class methods
#include "tabtenn1.h"
#include <iostream>

TableTennisPlayer::TableTennisPlayer(const string & fn,
    const string & ln, bool ht) : _firstname(fn),
        _lastname(ln), _hasTable(ht) {}

void TableTennisPlayer::name() const
{
    std::cout << _lastname << ", " << _firstname;
}

RatedPlayer::RatedPlayer(unsigned int r, const string & fn,
    const string & ln, bool ht) : TableTennisPlayer(fn, ln, ht)
{
    _rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp)
    : TableTennisPlayer(tp), _rating(r) {}