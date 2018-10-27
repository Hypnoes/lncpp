// main.cpp -- using a composite class

#include <iostream>
#include "studentc.h"
using std::cin;
using std::cout;
using std::endl;

void set(Student & sa, int n);
const int PUPILS = 3;
const int QUIZZES = 5;

int main()
{
    Student ada[PUPILS] =
        {Student(QUIZZES), Student(QUIZZES), Student(QUIZZES)};
    
    for(auto&& i : ada)
        set(i, QUIZZES);
    cout << "\nStudent List:\n";
    for(auto&& i : ada)
        cout << i.name() << endl;
    cout << "\nResults: ";
    
    for(auto&& item : ada)
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