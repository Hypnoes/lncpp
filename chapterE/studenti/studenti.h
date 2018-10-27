// studenti.h -- defining a Student class using private inheritance
#ifndef STUDENTI_H_
#define STUDENTI_H_

#include <iostream>
#include <string>
#include <valarray>
class Student : private std::string, private std::valarray<double>
{
  private:
    typedef std::valarray<double> _ArrayDb;

  public:
    Student() : std::string("Null Student"), _ArrayDb() {}
    explicit Student(const std::string & s) : std::string(s), _ArrayDb() {}
    explicit Student(int n) : std::string("Nully"), _ArrayDb(n) {}
    Student(const std::string & s, int n)
        : std::string(s), _ArrayDb(n) {}
    Student(const std::string & s, const _ArrayDb & a)
        : std::string(s), _ArrayDb(a) {}
    Student(const char * str, const double * pd, int n)
        : std::string(str), _ArrayDb(pd, n) {}
    ~Student() {}

    double average() const;
    double & operator[](int i);
    double operator[](int i) const;
    const std::string & name() const;
    std::ostream & arr_out(std::ostream & os) const;

    friend std::istream & operator>>(std::istream & is, Student & stu);
    friend std::istream & getline(std::istream & is, Student & stu);
    friend std::ostream & operator<<(std::ostream & os, Student & stu);
};
#endif