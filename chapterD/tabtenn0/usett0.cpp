// usett0.cpp -- using a base class
#include <iostream>
#include "tabtenn0.h"

int main()
{
    using std::cout;
    TableTennisPlayer player1("Chuck", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);

    player1.name();
    if (player1.has_table())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";
    player2.name();
    if (player2.has_table())
        cout << ": has a table";
    else
        cout << ": hasn't a table.\n";
    
    return 0;
}