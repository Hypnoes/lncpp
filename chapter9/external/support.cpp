// support.cpp -- use external variable
// compile with external.cpp
#include <iostream>
extern double warming;

// function prototypes
void update(double);
void local();

using std::cout;
void update(double dt)
{
    extern double warming;
    warming += dt;
    cout << "Updateing global warming to " << warming;
    cout << " degrees.\n";
}

void local()
{
    double warming = 0.8;

    cout << "Local warming = " << warming << " degrees.\n";

    cout << "But global warming = " << ::warming;
    cout << " degrees.\n";
}
