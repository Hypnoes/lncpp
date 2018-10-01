// ourfunc1.cpp -- repositioning the using directive

#include <iostream>
using namespace std;
void simon(int);

int main(int argc, char const *argv[])
{
    simon(3);
    cout << "Pick an interger: ";
    int count = 0;
    cin >> count;
    simon(count);
    cout << "Done!" << endl;
    return 0;
}

void simon(int n)
{
    cout << "Simon say touch your toes " << n << " times." << endl;
}