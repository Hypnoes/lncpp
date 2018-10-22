// vegnews.cpp -- using new and delete with classes

#include <iostream>
#include "strng.h"

using std::cout;

void callme1(Strng &);
void callme2(Strng);

int main()
{
    using std::endl;
    {
        cout << "String an inner block.\n";
        Strng headline1("Celery Stalke at Midnight");
        Strng headline2("Letture Prey");
        Strng sports("Spinach Leave Bowl for Dollars");
        cout << "headline1: " << headline1 << endl;
        cout << "Headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;
        callme1(headline1);
        cout << "Headline1: " << headline1 << endl;
        callme2(headline2);
        cout << "Headline2: " << headline2 << endl;
        
        cout << "Initialize one object to another:\n";
        Strng sailor = sports;
        cout << "sailort: " << sailor << endl;
        cout << "Assign one object to another:\n";
        Strng knot;
        knot = headline1;
        cout << "Knot: " << knot << endl;
        cout << "Exiting the block.\n";
    }
    cout << "End of main()\n";

    return 0;
}

void callme1(Strng & rsb)
{
    cout << "String passed by reference:\n";
    cout << "\t\"" << rsb << "\"\n";
}

void callme2(Strng sb)
{
    cout << "String passed by value:\n";
    cout << "\t\"" << sb << "\"\n";
}