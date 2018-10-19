// vect.cpp -- methods for the Vector class
#include <cmath>
#include "vector.h"

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
    const double Rad_to_deg = 45.0 / atan(1.0);

    void Vector::set_mag_()
    {
        mag_ = sqrt(x_ * x_ + y_ * y_);
    }

    void Vector::set_ang_()
    {
        if (x_ == 0.0 & y_ == 0.0)
            ang_ = 0.0;
        else
            ang_ = atan2(y_, x_);
    }

    void Vector::set_x_()
    {
        x_ = mag_ * cos(ang_);
    }

    void Vector::set_y_()
    {
        y_ = mag_ * sin(ang_);
    }

    Vector::Vector()
    {
        x_ = y_ = mag_ = ang_ = 0.0;
        mode_ = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form)
    {
        mode_ = form;
        if (form == RECT)
        {
            x_ = n1;
            y_ = n2;
            set_mag_();
            set_ang_();
        }
        else if (form == POL)
        {
            mag_ = n1;
            ang_ = n2 / Rad_to_deg;
            set_x_();
            set_y_();
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector -- ";
            cout << "vector set to 0\n";
            x_ = y_ = mag_ = ang_ = 0.0;
            mode_ = RECT;
        }
    }

    void Vector::reset(double n1, double n2, Mode form)
    {
        mode_ = form;
        if (form == RECT)
        {
            x_ = n1;
            y_ = n2;
            set_mag_();
            set_ang_();
        }
        else if (form == POL)
        {
            mag_ = n1;
            ang_ = n2 / Rad_to_deg;
            set_x_();
            set_y_();
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector -- ";
            cout << "vector set to 0\n";
            x_ = y_ = mag_ = ang_ = 0.0;
            mode_ = RECT;
        }
    }

    Vector::~Vector() { }

    void Vector::polar_mode()
    {
        mode_ = POL;
    }

    void Vector::rect_mode()
    {
        mode_ = RECT;
    }

    Vector Vector::operator+(const Vector & b) const
    {
        return Vector(x_ + b.x_, y_ + b.y_);
    }

    Vector Vector::operator-(const Vector & b) const
    {
        return Vector(x_ - b.x_, y_ - b.y_);
    }

    Vector Vector::operator-() const
    {
        return Vector(-x_, -y_);
    }

    Vector Vector::operator*(double n) const
    {
        return Vector(n * x_, n * y_);
    }
    
    Vector operator*(double n, const Vector & a)
    {
        return a * n;
    }

    std::ostream & operator<<(std::ostream & os, const Vector & v)
    {
        if (v.mode_ == Vector::RECT)
            os << "(x, y) = (" << v.x_ << ", " << v.y_ << ")";
        else if (v.mode_ == Vector::POL)
        {
            os << "(m, a) = (" << v.mag_ << ", " << v.ang_ * Rad_to_deg << ")";
        }
        else
            os << "Vector object mode is invalid";
        return os;
    }
}