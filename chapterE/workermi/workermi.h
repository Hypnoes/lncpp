// workermi.h -- workking classes with MI
#ifndef WORKERMI_H_
#define WORKERMI_H_

#include <string>

class Worker
{
  private:
    std::string _full_name;
    long _id;

  protected:
    virtual void data() const;
    virtual void get();

  public:
    Worker() : _full_name("no one"), _id(0L) {}
    Worker(const std::string & s, long n)
        : _full_name(s), _id(n) {}
    
    virtual ~Worker() = 0;
    virtual void set() = 0;
    virtual void show() const = 0;
};

class Waiter : virtual public Worker
{
  private:
    int _panache;

  protected:
    void data() const;
    void get();

  public:
    Waiter() : Worker(), _panache(0) {};
    Waiter(const std::string & s, long n, int p = 0)
        : Worker(s, n), _panache(p) {}
    Waiter(const Worker & wk, int p = 0)
        : Worker(wk), _panache(p) {}

    void set();
    void show() const;
};

class Singer : virtual public Worker
{
  protected:
    enum {other, alto, contralto, soprano, bass, baritone, tenor};
    enum {Vtypes = 7};
    void data() const;
    void get();

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

class SingingWaiter : public Singer, public Waiter
{
  protected:
    void data() const;
    void get();

  public:
    SingingWaiter() {}
    SingingWaiter(const std::string & s, long n, int p = 0, int v = other)
        : Worker(s, n), Waiter(s, n, p), Singer(s, v, v) {}
    SingingWaiter(const Worker & wk, int p = 0, int v = other)
        : Worker(wk), Waiter(wk, p), Singer(wk, v) {}
    SingingWaiter(const Waiter & wt, int v = other)
        : Worker(wt), Waiter(wt), Singer(wt, v) {}
    SingingWaiter(const Singer & ws, int p = 0)
        : Worker(ws), Waiter(ws, p), Singer(ws) {}
    
    void set();
    void show() const;
};

#endif