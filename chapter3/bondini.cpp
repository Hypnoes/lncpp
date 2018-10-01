// bondini.cpp -- using escape sequences

#include <iostream>
int main(int argc, char const *argv[])
{
    using namespace std;
    cout << "\aOperator \"HyperHype\" is now activated!\n";
    cout << "Enter your agent code: ________\b\b\b\b\b\b\b\b";
    long code;
    cin >> code;
    cout << "\aYou entered " << code << "...\n";
    cout << "\aCode Verified! Proceed with Plan Z3!\n";
    return 0;
}
