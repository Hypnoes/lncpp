// namesp.cpp -- namespaces
#include <iostream>
#include "namesp.h"

namespace pers
{
    using std::cout;
    using std::cin;

    void get_person(Person & rp)
    {
        cout << "Enter first name: ";
        cin >> rp.fname;
        cout << "Enter last name: ";
        cin >> rp.lname;
    }

    void show_person(const Person & rp)
    {
        cout << rp.lname << ", " << rp.fname;
    }
}


namespace debts
{
    using std::cout;
    using std::cin;

    void get_debt(Debt & rd)
    {
        get_person(rd.name);
        cout << "Enter debt: ";
        cin >> rd.amount;
    }

    void show_debt(const Debt & rd)
    {
        show_person(rd.name);
        cout << ": $" << rd.amount << std::endl;
    }

    double sum_debts(const Debt ar[], int n)
    {
        double total = 0;
        for (int i = 0; i < n; i++)
            total += ar[i].amount;
        return total;
    }
} // debts
