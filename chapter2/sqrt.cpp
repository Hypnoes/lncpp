// sqrt.cpp -- using the sqrt() function

#include <iostream>
#include <cmath>

int main(int argc, char const *argv[])
{
    using namespace std;

    double area = 0.0;
    cout << "Enter the floor area, in square feet, of your home: ";
    cin >> area;
    double side = 0.0;
    side = sqrt(area);
    cout << "That's the equivalent of a square " << side
         << " feet to the side." << endl;
    cout << "How fascinating!" << endl;    
    return 0;
}
