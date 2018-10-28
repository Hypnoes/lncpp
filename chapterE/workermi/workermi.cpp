// workermi.cpp -- working class methods with MI
#include "workermi.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// worker methods
Worker::~Worker() {}

void Worker::data() const
{
    cout << "Name: " << _full_name << endl;
    cout << "Employee ID: " << _id << endl;
}

void Worker::get()
{
    std::getline(cin, _full_name);
    cout << "Enter worker's ID: ";
    cin >> _id;
    while (cin.get() != '\n')
        continue;
}

// Waiter methods
void Waiter::set()
{
    cout << "Enter waiter's name: ";
    Worker::get();
    get();
}

void Waiter::show() const
{
    cout << "Category: waiter\n";
    Worker::data();
    data();
}

void Waiter::data() const
{
    cout << "Panache rating: " << _panache << endl;
}

void Waiter::get() 
{
    cout << "Enter waiter's panache rating: ";
    cin >> _panache;
    while (cin.get() != '\n')
        continue;
}

// Singer methods

char * Singer::_pv[Singer::Vtypes] = {"other", "alto",
    "contralto", "soprano", "bass", "baritone", "tenor"};

void Singer::set()
{
    cout << "Enter singer's name: ";
    Worker::get();
    get();
}

void Singer::show() const
{
    cout << "Category: singer\n";
    Worker::data();
    data();
}

void Singer::data() const
{
    cout << "Vocal range: " << _pv[_voice] << endl;
}

void Singer::get()
{
    cout << "Enter number for singer's vocal range: \n";
    int i;
    for (i = 0; i < Vtypes; i++)
    {
        cout << i << ": " << _pv[i] << "\t";
        if (i % 4 == 3)
            cout << endl;
    }
    if (i % 4 != 0)
        cout << '\n';
    cin >> _voice;
    while (cin.get() != '\n')
        continue;
}

// SingingWaiter methods
void SingingWaiter::data() const
{
    Singer::data();
    Waiter::data();
}

void SingingWaiter::get()
{
    Waiter::get();
    Singer::get();
}

void SingingWaiter::set()
{
    cout << "Enter singing waiter's name: ";
    Worker::get();
    get();
}

void SingingWaiter::show() const
{
    cout << "Category: singing waiter\n";
    Worker::data();
    data();
}