// main.cpp -- using a class with private inheritance

#include <iostream>
#include "studenti.h"
using std::cin;
using std::cout;
using std::endl;

void set(Student & sa, int n);

const int PUPILS = 3;
const int QUIZES = 5;

int main()
{
    Student ada[PUPILS] =
        {Student(QUIZES), Student(QUIZES), Student(QUIZES)};
    
    for (auto&& item : ada)
        set(item, QUIZES);
    cout << "\nStudent List:\n";
    for (auto&& item : ada)
        cout << item.name() << endl;
    cout << "\nResults:";
    
    for (auto&& item : ada)
    {
        cout << endl << item;
        cout << "average: " << item.average() << endl;
    }

    cout << "Done.\n";
    return 0;
}

void set(Student & sa, int n)
{
    cout << "Please enter the student's name: ";
    getline(cin, sa);
    cout << "Please enter " << n << " quiz scores:\n";
    for (int i = 0; i < n; i++)
        cin >> sa[i];
    while (cin.get() != '\n')
        continue;
}