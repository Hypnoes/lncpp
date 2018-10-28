// tmp2tmp.cpp -- template friends to a template class
#include <iostream>

using std::cout;
using std::endl;

template<typename T> void counts();
template<typename T> void reports(T &);

template<typename T>
class HasFriendT
{
  private:
    T _item;
    static int _ct;

  public:
    HasFriendT(const T & i) : _item(i) { _ct++; }
    ~HasFriendT() { _ct--; }
    friend void counts<T>();
    friend void reports<>(HasFriendT<T> &);
};

template<typename T>
int HasFriendT<T>::_ct = 0;

template<typename T>
void counts()
{
    cout << "Template size: " << sizeof(HasFriendT<T>) << "; ";
    cout << "Template counts(): " << HasFriendT<T>::_ct << endl;
}

template<typename T>
void reports(T & hf)
{
    cout << hf._item << endl;
}


int main()
{
    counts<int>();
    HasFriendT<int> hfi1(10);
    HasFriendT<int> hfi2(20);
    HasFriendT<double> hfdb(10.5);
    reports(hfi1);
    reports(hfi2);
    reports(hfdb);
    cout << "counts<int>() output:\n";
    counts<int>();
    cout << "counts<double>() output:\n";
    counts<double>();

    return 0;
}