// brass.h -- bank account classes
#ifndef BRASS_H_
#define BRASS_H_
#include <string>
using std::string;

class Brass
{
  private:
    string _fullName;
    long _acctNum;
    double _balance;

  public:
    Brass(const string & s = "Nullbody", long an = -1, double bal = 0.0);
    virtual ~Brass() {}

    void deposit(double amt);
    double balance() const;
    
    virtual void with_draw(double amt);
    virtual void view_acct() const;
};

class BrassPlus : public Brass
{
  private:
    double _maxLoan;
    double _rate;
    double _owesBank;

  public:
    BrassPlus(const string & s = "Nullbody", long an = -1,
              double bal = 0.0, double ml = 500,
              double r = 0.11125);
    BrassPlus(const Brass & ba, double ml = 500,
              double r = 0.11125);
    
    virtual void with_draw(double amt);
    virtual void view_acct() const;

    void reset_max(double m) { _maxLoan = m; }
    void reset_rate(double r) { _rate = r; }
    void reset_owes() { _owesBank = 0; }
};

#endif