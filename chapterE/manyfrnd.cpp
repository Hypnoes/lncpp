// manyfrnd.cpp -- unbound template friend to a template class
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class ManyFriend
{
  private:
    T _item;

  public:
    ManyFriend(const T & i) : _item(i) {}
    template<typename C, typename D> friend void show(C &, D &);
};

template<typename C, typename D>
void show(C & c, D & d)
{
    cout << c._item << ", " << d._item << endl;
}

int main()
{
    ManyFriend<int> hfi1(10);
    ManyFriend<int> hfi2(20);
    ManyFriend<double> hfdb(10.5);
    cout << "hfi1, hfi2: ";
    show(hfi1, hfi2);
    cout << "hfdb, hfi2: ";
    show(hfdb, hfi2);

    return 0;
}