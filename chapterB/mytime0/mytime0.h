// mytime0.h -- Time class before operator overloading
#ifndef MYTIME0_H_
#define MYTIME0_H_

class Time
{
  public:
    Time();
    Time(int h, int m = 0);
    
    void add_min(int m);
    void add_hr(int h);
    void reset(int h = 0, int m = 0);
    Time operator+(const Time & t) const;
    Time operator-(const Time & t) const;
    Time operator*(double mult) const;

    friend Time operator*(double m, const Time & t)
      { return t * m; }

    friend std::ostream & operator<<(std::ostream & os, const Time & t);

  private:
    int hours;
    int minutes;
};

#endif