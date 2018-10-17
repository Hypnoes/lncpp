// cubes.cpp -- regular and reference arguments
#include <iostream>
double cube(double);
double refcube(double &);
int main()
{
    using namespace std;
    double x = 3.0;

    cout << cube(x);
    cout << " = cube of " << x << endl;
    cout << refcube(x);
    cout << " = cube of " << x << endl;
    return 0;
}

double cube(double a) { return a * a * a; }
double refcube (double &ra) { return ra * ra * ra; }