// worker0.cpp -- working class methods
#include "worker0.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Worker::~Worker() {}

void Worker::set()
{
    cout << "Enter worker's name: ";
    getline(cin, _full_name);
    cout << "Enter worker's ID: ";
    cin >> _id;
    while (cin.get() != '\n')
        continue;
}

void Worker::show() const
{
    cout << "Name: " << _full_name << "\n";
    cout << "Employee ID: " << _id << "\n";
}

void Waiter::set()
{
    Worker::set();
    cout << "Enter witer's panache rating: ";
    cin >> _panache;
    while (cin.get() != '\n')
        continue;
}

void Waiter::show() const
{
    cout << "Category: waiter\n";
    Worker::show();
    cout << "Panache rating: " << _panache << "\n";
}

char * Singer::_pv[] = {"Other", "alto", "contralto",
    "soprano", "bass", "baritone", "tenor"};

void Singer::set()
{
    Worker::set();
    cout << "Enter number for singer's vocal range: \n";
    int i;
    for (i = 0; i < Vtypes; i++)
    {
        cout << i << ": " << _pv[i] << "   ";
        if (i % 4 == 3)
            cout << endl;
    }
    if (i % 4 != 0)
        cout << endl;
    while (cin >> _voice && (_voice < 0 || _voice >= Vtypes))
        cout << "Please enter a value >= 0 and < " << Vtypes << endl;
    
    while (cin.get() != '\n')
        continue;
}

void Singer::show() const
{
    cout << "Category: Singer\n";
    Worker::show();
    cout << "Vocal range: " << _pv[_voice] << endl;
}