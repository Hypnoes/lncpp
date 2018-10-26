// acctabc.cpp -- bank account class methods
#include <iostream>
#include "acctabc.h"

using std::cout;
using std::ios_base;
using std::endl;
using std::string;

// Abstract Base Class
AcctABC::AcctABC(const string & s, long an, double bal)
{
    _fullName = s;
    _acctNum = an;
    _balance = bal;
}

void AcctABC::deposit(double amt)
{
    if (amt < 0)
        cout << "Negative deposit not allowed; "
             << "deposit is cancelled.\n";
    else
        _balance += amt;
}

void AcctABC::with_draw(double amt)
{
    _balance -= amt;
}

AcctABC::Formatting AcctABC::_set_format() const
{
    Formatting f;
    f.flag = 
        cout .setf(ios_base::fixed, ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}

void AcctABC::_restore(Formatting & f) const
{
    cout.setf(f.flag, ios_base::floatfield);
    cout.precision(f.pr);
}

// Brass methods
void Brass::with_draw(double amt)
{
    if (amt < 0)
        cout << "With draw amount must be positive; "
             << "with draw canceled.\n";
    else if (amt <= balance())
        AcctABC::with_draw(amt);
    else
        cout << "Withdrawal amount of $" << amt
             << " exceeds your balance.\n"
             << "Withdrawal canceled.\n";
}

void Brass::view_acct() const
{
    Formatting f = _set_format();
    cout << "Brass Client: " << _full_name() << endl;
    cout << "Account Number: " << _acct_num() << endl;
    cout << "Balance: $" << balance() << endl;
    _restore(f);
}

// BrassPlus Methods
BrassPlus::BrassPlus(const string & s, long an, double bal,
                     double ml, double r) : AcctABC(s, an, bal)
{
    _maxLoan = ml;
    _owesBank = 0.0;
    _rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double m1, double r)
          : AcctABC(ba)
{
    _maxLoan = ml;
    _owesBank = 0.0;
    _rate = r;
}

void BrassPlus::view_acct() const
{
    Formatting f = _set_format();

    cout << "BrassPlus Client: " << _full_name() << endl;
    cout << "Account Number: " << _acct_num() << endl;
    cout << "Balance: $" << balance() << endl;
    cout << "Maximum loan: $" << _maxLoan << endl;
    cout << "Owed to bank: $" << _owesBank << endl;
    cout.precision(3);
    cout << "Loan rate: " << 100 * _rate << "%\n";
    _restore(f);
}

void BrassPlus::with_draw(double amt)
{
    Formatting f = _set_format();

    double bal = balance();
    if (amt <= bal)
        AcctABC::with_draw(amt);
    else if (amt <= bal + _maxLoan - _owesBank)
    {
        double advance = amt - bal;
        _owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finace charge: $" << advance * rate << endl;
        deposit(advance);
        AcctABC::with_draw(amt);
    }
    else
        cout << "Credit limit exceeded. Transaction cancelled.\n";
}