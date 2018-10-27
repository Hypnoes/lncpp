// studentc.h -- defining a Student class using constainment
#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <string>
#include <valarray>

class Student
{
  private:
    typedef std::valarray<double> _ArrayDb;
    std::string _name;
    _ArrayDb _scores;
    std::ostream & _arr_out(std::ostream & os) const;

  public:
    Student() : _name("Null Student"), _scores() {}
    explicit Student(const std::string & s) : _name(s), _scores() {}
    explicit Student(int n) : _name("Nully"), _scores(n) {}
    Student(const std::string & s, int n)
        : _name(s), _scores(n) {}
    Student(const std::string & s, const _ArrayDb & a)
        : _name(s), _scores(a) {}
    Student(const char * str, const double * pd, int n)
        : _name(str), _scores(pd, n) {}
    ~Student() {}

    double average() const;
    const std::string & name() const;
    double & operator[](int i);
    double operator[](int i) const;

    friend std::istream & operator>>(std::istream & is,
                                     Student & stu);
    friend std::istream & getline(std::istream & is,
                                  Student & stu);
    friend std::ostream & operator<<(std::ostream & os,
                                     const Student & stu);
};

#endif