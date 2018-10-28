// main.cpp -- multiple inheritance

#include <iostream>
#include <cstring>
#include "workermi.h"
const int SIZE = 5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    Worker * lolas[SIZE];
    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the employee category:\n"
             << "w: waiter\ts: singer\n"
             << "t: singing waiter\tq: quit\n";
        cin >> choice;
        while (strchr("wstq", choice) == NULL)
        {
            cout << "Please enter a w, s, t, or q:\n";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch(choice)
        {
            case 'w': lolas[ct] = new Waiter;
                      break;
            case 's': lolas[ct] = new Singer;
                      break;
            case 't': lolas[ct] = new SingingWaiter;
                      break;
        }
        cin.get();
        lolas[ct]->set();
    }

    cout << "\nHere is your staff:\n";
    for (auto&& item: lolas)
    {
        cout << endl;
        item->show();
    }
    for (auto&& item: lolas)
    {
        delete item;
    }
    cout << "Bye.\n";
    return 0;
}