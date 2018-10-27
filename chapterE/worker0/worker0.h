// worker0.h -- working classes
#ifndef WORKER0_H_
#define WORKER0_H_

#include <string>

class Worker
{
  private:
    std::string _full_name;
    long _id;

  public:
    Worker() : _full_name("no one"), _id(0L) {};
    Worker(const std::string & s, long n)
        : _full_name(s), _id(n) {}
    
    virtual ~Worker() = 0;
    virtual void set();
    virtual void show() const;
};

class Waiter : public Worker
{
  private:
    int _panache;

  public:
    Waiter() : Worker(), _panache(0) {}
    Waiter(const std::string & s, long n, int p = 0)
        : Worker(s, n), _panache(p) {}
    Waiter(const Worker & wk, int p = 0)
        : Worker(wk), _panache(p) {}
    
    void set();
    void show() const;
};

class Singer : public Worker
{
  protected:
    enum {other, alto, contralto, soprano, bass, baritone, tenor};
    enum {Vtypes = 7};

  private:
    static char * _pv[Vtypes];
    int _voice;

  public:
    Singer() : Worker(), _voice(other) {}
    Singer(const std::string & s, long n, int v = other)
      : Worker(s, n), _voice(v) {}
    Singer(const Worker & wk, int v = other)
      : Worker(wk), _voice(v) {}
    
    void set();
    void show() const;
};

#endif