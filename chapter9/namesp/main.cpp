// main.cpp -- using namespace
#include <iostream>
#include "namesp.h"

void other();
void another();

int main()
{
    using debts::Debt;
    using debts::show_debt;

    Debt golf = { {"Benny", "Goatsniff"}, 120.0 };
    show_debt(golf);
    other();
    another();
    return 0;
}

void other()
{
    using std::cout;
    using std::endl;

    using namespace debts;
    Person dg = {"Doodles", "Glister"};
    show_person(dg);
    cout << endl;
    Debt zippy[3] {};
    int i {};
    for (i = 0; i < 3; i++)
        get_debt(zippy[i]);
    for (i = 0; i < 3; i++)
        show_debt(zippy[i]);
    cout << "Total debt: $" << sum_debts(zippy, 3) << endl;
    return;
}

void another()
{
    using pers::Person;
    Person collector = { "Milo", "Rightshift" };
    pers::show_person(collector);
    std::cout << std::endl;
}