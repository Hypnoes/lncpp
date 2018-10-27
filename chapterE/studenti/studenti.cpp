// studenti.cpp -- Student class using private inheritance
#include "studenti.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;

double Student::average() const
{
    if (_ArrayDb::size() > 0)
        return _ArrayDb::sum() / _ArrayDb::size();
    else
        return 0;
}

const string & Student::name() const
{ return (const string &) * this; }

double & Student::operator[](int i)
{ return _ArrayDb::operator[](i); }

double Student::operator[](int i) const
{ return _ArrayDb::operator[](i); }

ostream & Student::arr_out(ostream & os) const
{
    int i;
    int lim = _ArrayDb::size();
    
    if (lim > 0)
    {
        for (i = 0; i < lim; i++)
        {
            os << _ArrayDb::operator[](i) << "\t";
            if (i % 5 == 4)
                os << endl;
        }
        if (i % 5 == 0)
            os << endl;
    }
    else
        os << " empty array ";
    return os;
}

istream & operator>>(istream & is, Student & stu)
{
    is >> (string &)stu;
    return is;
}

istream & getline(istream & is, Student & stu)
{
    getline(is, (string &)stu);
    return is;
}

ostream & operator<<(ostream & os, const Student & stu)
{
    os << "Scores for " << (const string &) stu << ":\n";
    stu.arr_out(os);
    return os;
}