// acctabc.h -- bank acount classes
#ifndef ACCTABC_H_
#define ACCTABC_H_
#include <iostream>
#include <string>

// Abstract Base Class
class AcctABC
{
  private:
    std::string _fullName;
    long _acctNum;
    double _balance;

  protected:
    struct Formatting
    {
        std::ios_base::fmtflags flag;
        std::streamsize pr;
    };
    const std::string & _full_name() const { return _fullName; }
    long _acct_num() const { return _acctNum; }
    Formatting _set_format() const;
    void _restore(Formatting & f) const;

  public:
    AcctABC(const std::string & s = "Nullbody", long an = -1,
            double bal = 0.0);
    
    double balance() const { return _balance; }
    void deposit(double amt);

    virtual ~AcctABC() {}
    virtual void with_draw(double amt) = 0;
    virtual void view_acct() const = 0;
};

// Brass Account Class
class Brass : public AcctABC
{
  public:
    Brass(const std::string & s = "Nullbody", long an = -1,
          double bal = 0.0, double ml = 500,
          double r = 0.10);
    
    virtual void view_acct() const;
    virtual void with_draw(double amt);
    virtual ~Brass() {}
};

// Brass Plus Account Class
class BrassPlus : public AcctABC
{
  private:
    double _maxLoan;
    double _rate;
    double _owesBank;

  public:
    BrassPlus(const std::string & s = "Nullbody", long an = -1,
              double bal = 0.0, double ml = 500,
              double r = 0.10);
    BrassPlus(const Brass & ba, double ml = 500, double r = 0.1);

    virtual void view_acct() const;
    virtual void with_draw(double amt);

    void reset_max(double m) { _maxLoan = m; }
    void reset_rate(double r) { _rate = r; }
    void reset_owes() { _owesBank = 0; }
};

#endif