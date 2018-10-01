//hexoct2.cpp -- display values in hex and oct

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int chest = 42;
    int waist = 42;
    int inseam = 42;

    cout << "Monieur cuts a striking figure!" << endl;
    cout << "chest = " << chest << " (decimal for 42)" << endl;
    cout << hex;    // manipulator for changing number base
    cout << "waist = 0x" << waist << " (hexdecimal for 42)" << endl;
    cout << oct;    // manipulator for changing number base
    cout << "inseam = 0" << inseam << " (octal for 42)" << endl;
    return 0;
}
