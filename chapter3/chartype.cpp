// chartype.cpp -- the char type

#include <iostream>

int main(int argc, char const *argv[])
{
    using namespace std;
    char ch;

    cout << "Enter a character " << endl;
    cin >> ch;
    cout <<  "Hola! " 
         << "Thank you for the " << ch 
         << " character." << endl;
    return 0;
}
