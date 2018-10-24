// usett1.cpp -- using base class and derived class
#include <iostream>
#include "tabtenn1.h"

int main()
{
    using std::cout;
    using std::endl;
    TableTennisPlayer player1("Tara", "Boomdea", false);
    RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
    rplayer1.name();
    if(rplayer1.has_table())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";
    player1.name();
    if (player1.has_table())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";
    cout << "Name: ";
    rplayer1.name();
    cout << ": Rating: " << rplayer1.rating() << endl;
    RatedPlayer rplayer2(1212, player1);
    cout << "Name: ";
    rplayer2.name();
    cout << "; Rating: " << rplayer2.rating() << endl;

    return 0;
}