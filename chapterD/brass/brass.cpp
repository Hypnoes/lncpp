// brass.cpp -- bank account class methods
#include <iostream>
#include "brass.h"
using std::cout;
using std::endl;
using std::string;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;

format setFormat();
void restore(format f, precis p);

Brass::Brass(const string & s, long an, double bal)
{
    _fullName = s;
    _acctNum = an;
    _balance = bal;
}

void Brass::deposit(double amt)
{
    if (amt < 0)
        cout << "Negative deposit not allowed; "
             << "deposit is cancelled.\n";
    else
        _balance += amt;
}

void Brass::with_draw(double amt)
{
    format initialState = setFormat();
    precis prec = cout.precision(2);

    if (amt < 0)
        cout << "Withdrawal amount must be positive; "
             << "withdrawal canceled.\n";
    else if (amt <= _balance)
        _balance -= amt;
    else
        cout << "Withdrawal amount of $" << amt
             << " exceeds your balance.\n"
             << "Withdrawal canceled.\n";
        restore(initialState, prec);
}

double Brass::balance() const
{
    return _balance;
}

void Brass::view_acct() const
{
    format initialState = setFormat();
    precis prec = cout.precision(2);
    cout << "Client: " << _fullName << endl;
    cout << "Account: " << _acctNum << endl;
    cout << "Balance: $" << _balance << endl;
    restore(initialState, prec);
}

BrassPlus::BrassPlus(const string & s, long an, double bal,
                     double ml, double r) : Brass(s, an, bal)
{
    _maxLoan = ml;
    _owesBank = 0.0;
    _rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r)
          : Brass(ba)
{
    _maxLoan = ml;
    _owesBank = 0.0;
    _rate = r;
}

void BrassPlus::view_acct() const
{
    format initialState = setFormat();
    precis prec = cout.precision(2);

    Brass::view_acct();
    cout << "Maximum loan: $" << _maxLoan << endl;
    cout << "Owed to bank: $" << _owesBank << endl;
    cout.precision(3);
    cout << "Loan Rate: " << 100 * _rate << "%\n";
    restore(initialState, prec);
}

void BrassPlus::with_draw(double amt)
{
    format initialState = setFormat();
    precis prec = cout.precision(2);

    double bal = balance();
    if (amt <= bal)
        Brass::with_draw(amt);
    else if (amt <= bal + _maxLoan)
    {
        double advance = amt - bal;
        _owesBank += advance * (1.0 + _rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * _rate << endl;
        deposit(advance);
        Brass::with_draw(amt);
    }
    else
        cout << "Credit limit exceeded. Transaction cancelled.\n";
    restore(initialState, prec);
}

format setFormat()
{
    return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}