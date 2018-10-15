// strctptr.cpp -- functions with pointer to structure arguments
#include <iostream>
#include <cmath>

// structure declarations
struct polar
{
    double distance;
    double angle;
};
struct rect
{
    double x;
    double y;
};

// prototypes
void rect_to_polar(const rect *, polar *);
void show_polar(const polar *);

int main()
{
    using namespace std;
    rect rplace;
    polar pplace;

    cout << "Enter the x and y values: ";
    while (cin >> rplace.x >> rplace.y)
    {
        rect_to_polar(&rplace, &pplace);
        show_polar(&pplace);
        cout << "Next two numbers (q to quit): ";
    }
    cout << "Done.\n";
    return 0;
}

// show polar coordinates, converting angle to degrees
void show_polar(const polar * pda)
{
    using namespace std;
    const double Reg_to_deg = 57.29577951;

    wcout << L"distance = " << pda -> distance;
    wcout << L", angle = " << pda -> angle * Reg_to_deg;
    wcout << L"°\n";
}

// convert rectangular to polar coordinates
void rect_to_polar(const rect * pxy, polar * pda)
{
    using namespace std;
    pda -> distance = 
        sqrt(pxy -> x * pxy -> y + pxy -> y * pxy -> y);
    pda -> angle = atan2(pxy -> y, pxy -> x);
}