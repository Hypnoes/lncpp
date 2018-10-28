// tempmemb.cpp -- template members
#include <iostream>

using std::cout;
using std::endl;

template<typename T>
class beta
{
  private:
    template<typename V>
    class _hold
    {
      private:
        V _val;
    
      public:
        _hold(V v = 0) : _val(v) {}
        
        void show() const { cout << _val << endl; }
        V value() const { return _val; }
    };
    _hold<T> _q;
    _hold<int> _n;

  public:
    beta(T t, int i) : _q(t), _n(i) {}
    template<typename U>
    U blab(U u, T t) { return (_n.value() + _q.value()) * u / t; }
    void show() const { _q.show(); _n.show(); }
};

int main()
{
    beta<double> guy(3.5, 3);
    cout << "T was set to double\n";
    guy.show();
    cout << "V was set to T, which is double, then V was set to int\n";
    cout << guy.blab(10, 2.3) << endl;
    cout << "U was set to int\n";
    cout << guy.blab(10.0, 2.3) << endl;
    cout << "U was set to double\n";
    cout << "Done.\n";
    return 0;
}