// convert.cpp -- converts stone to ponds

#include <iostream>

int stonetolb(int); // function prototype

int main(int argc, char const *argv[])
{
    using namespace std;
    int stone = 0;
    cout << "Enter the weight in stone: ";
    cin >> stone;
    int pounds = stonetolb(stone);
    cout << stone << " stone = ";
    cout << pounds << " ponds." << endl;
    return 0;
}

int stonetolb(int sts)
{
    return 14 * sts;
}