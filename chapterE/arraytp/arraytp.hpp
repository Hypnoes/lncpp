// arraytp.h -- Array class
#ifndef ARRAYTP_H_
#define ARRAYTP_H_

#include <iostream>
#include <cstdlib>

template<typename T, int n>
class ArrayTP
{
  private:
    T _ar[n];

  public:
    ArrayTP() {};
    explicit ArrayTP(const T & v);
    virtual T & operator[](int i);
    virtual T operator[](int i) const;
};

template<typename T, int n>
ArrayTP<T, n>::ArrayTP(const T & v)
{
    for (int i = 0; i < n; i++)
        _ar[i] = v;
}

template<typename T, int n>
T & ArrayTP<T, n>::operator[](int i)
{
    if (i < 0 || i >= n)
    {
        std::cerr << "Error in array limits: " << i
                  << " is out of range\n";
        std::exit(EXIT_FAILURE);
    }
    return _ar[i];
}

template<typename T, int n>
T ArrayTP<T, n>::operator[](int i) const
{
    if (i < 0 || i >= n)
    {
        std::cerr << "Error in array limits: " << i
                  << " is out of range\n";
        std::exit(EXIT_FAILURE);
    }
    return _ar[i];
}

#endif