// frnd2tmp.cpp -- template class with non-template friends
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class HasFriend
{
  private:
    T _item;
    static int _ct;

  public:
    HasFriend(const T & i) : _item(i) { _ct++; }
    ~HasFriend() { _ct--; }
    friend void counts();
    friend void reports(HasFriend<T> &);
};

template<typename T>
int HasFriend<T>::_ct = 0;

void counts()
{
    cout << "int count: " << HasFriend<int>::_ct << "; ";
    cout << "double count: " << HasFriend<double>::_ct << endl;
}

void reports(HasFriend<int> & hf)
{
    cout << "HasFriend<int>: " << hf._item << endl;
}

void reports(HasFriend<double> & hf)
{
    cout << "HasFriend<double>: " << hf._item << endl;
}

int main()
{
    cout << "No objects declared: ";
    counts();
    HasFriend<int> hfi1(10);
    cout << "After hfi1 declared: ";
    counts();
    HasFriend<int> hfi2(20);
    cout << "After hfi2 declared: ";
    counts();
    HasFriend<double> hfdb(10.5);
    cout << "Afterhfdb declared: ";
    counts();
    reports(hfi1);
    reports(hfi2);
    reports(hfdb);

    return 0;
}