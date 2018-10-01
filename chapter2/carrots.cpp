// carrots.cpp -- food processing program
// uses and displays a variable

#include <iostream>

int main(int argc, char const *argv[])
{
    using namespace std;

    int carrots = 25;
    cout << "I have " << carrots << " carrots." << endl;
    carrots = carrots - 1;
    cout << "Crunch, crunch. Now I have " << carrots << " carrots." << endl;
    return 0;
}
