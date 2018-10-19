// stock10.h -- Stock class interface

#ifndef STOCK10_H_
#define STOCK10_H_

#include <string>

class Stock
{
    private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    
    void set_tot() { total_val = shares * share_val; }

    public:
    Stock();
    Stock(const std::string &, long n = 0, double pr = 0.0);
    ~Stock();

    void buy(long, double);
    void sell(long, double);
    void update(double);
    void show();
};

#endif