// usebrass1.cpp -- testing bank account classes
#include <iostream>
#include "brass.h"

int main()
{
    using std::cout;
    using std::endl;

    Brass Piggy("Porcelot Pig", 381299, 4000.00);
    BrassPlus Hoggy("horatio Hogg", 382288, 3000.00);
    Piggy.view_acct();
    cout << endl;
    Hoggy.view_acct();
    cout << endl;
    cout << "Depositing $1000 into the Hogg Account:\n";
    Hoggy.deposit(1000.00);
    cout << "New balance: $" << Hoggy.balance() << endl;
    cout << "With drawing $4200 from the Pigg Account:\n";
    Piggy.with_draw(4200.00);
    cout << "Pigg account balance: $" << Piggy.balance() << endl;
    cout << "With drawing $4200 from the Hogg Account:\n";
    Hoggy.with_draw(4200.00);
    Hoggy.view_acct();

    return 0;
}