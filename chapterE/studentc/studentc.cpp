// studentc.cpp -- Student class using containment
#include "studentc.h"

using std::ostream;
using std::endl;
using std::istream;
using std::string;

double Student::average() const
{
    if (_scores.size() > 0)
        return _scores.sum() / _scores.size();
    else
        return 0;
}

const string & Student::name() const
{
    return _name;
}

double & Student::operator[](int i)
{
    return _scores[i];
}

double Student::operator[](int i) const
{
    return _scores[i];
}

ostream & Student::_arr_out(ostream & os) const
{
    int i;
    int lim = _scores.size();
    if (lim > 0)
    {
        for (i = 0; i < lim; i++)
        {
            os << _scores[i] << "\t";
            if (i % 5 == 4)
                os << endl;
        }
        if (i % 5 != 0)
            os << endl;
    }
    else
        os << " empty array";
    return os;
}

istream & operator>>(istream & is, Student & stu)
{
    is >> stu._name;
    return is;
}

istream & getline(istream & is, Student & stu)
{
    getline(is, stu._name);
    return is;
}

ostream & operator<<(ostream & os, const Student & stu)
{
    os << "Scores for " << stu._name << ":\n";
    stu._arr_out(os);
    return os;
}