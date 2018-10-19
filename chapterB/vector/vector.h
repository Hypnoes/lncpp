// vect.h -- Vector class with << , mode state
#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

namespace VECTOR
{
    class Vector
    {
      public:
        enum Mode { RECT, POL };

        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        
        double x_val() const { return x_; }
        double y_val() const { return y_; }
        double mag_val() const { return mag_; }
        double ang_val() const { return ang_; }
        void polar_mode();
        void rect_mode();

        Vector operator+(const Vector & b) const;
        Vector operator-(const Vector & b) const;
        Vector operator-() const;
        Vector operator*(double n) const;

        friend Vector operator*(double n, const Vector & a);
        friend std::ostream &
               operator<<(std::ostream & os, const Vector & v);
    
      private:
        double x_;
        double y_;
        double mag_;
        double ang_;
        Mode mode_;

        void set_mag_();
        void set_ang_();
        void set_x_();
        void set_y_();
    };
}

#endif