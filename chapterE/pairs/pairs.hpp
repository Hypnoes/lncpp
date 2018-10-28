// pairs.hpp -- defining a Pair class
#ifndef PAIRS_H_
#define PAIRS_H_

template<typename T1, typename T2>
class Pair
{
  private:
    T1 _a;
    T2 _b;

  public:
    T1 & first();
    T2 & second();
    T1 first() const { return _a; }
    T2 second() const { return _b; }

    Pair(const T1 & a_val, const T2 & b_val)
        : _a(a_val), _b(b_val) {}
    Pair() {}
};

template<typename T1, typename T2>
T1 & Pair<T1, T2>::first()
{
    return _a;
}

template<typename T1, typename T2>
T2 & Pair<T1, T2>::second()
{
    return _b;
}

#endif