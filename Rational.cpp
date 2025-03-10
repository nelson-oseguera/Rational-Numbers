// Rational.cpp : C++ implementation file for the Rational class

#include "Rational.h"
#include <cmath>

// Helper function to reduce the numerator and denominator to simplest form
void Rational::normalize()
{
    int x = abs(numerator);
    int y = abs(denominator);

    if (x > 0 && y > 0)
    {
        int r = x % y;

        while (r != 0)
        {
            x = y;
            y = r;
            r = x % y;
        }

        numerator /= y;
        denominator /= y;
    }

    if (denominator < 0)
    {
        numerator = -numerator;
        denominator = -denominator;
    }
}

// Overloaded output operator to output the rational number as numerator/denominator
ostream& operator<<(ostream& out, const Rational& r)
{
    out << r.numerator << "/" << r.denominator;
    return out;
}

// Overloaded input operator to read the numerator and denominator from the stream
istream& operator>>(istream& in, Rational& r)
{
    char slash;
    in >> r.numerator >> slash >> r.denominator;
    if (slash != '/')
    {
        in.setstate(ios::failbit);
    }
    else
    {
        r.normalize();
    }
    return in;
}

// Default constructor to initialize Rational object to 0/1
Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}

// 1-argument constructor to initialize Rational object to n/1
Rational::Rational(int n)
{
    numerator = n;
    denominator = 1;
}

// 2-argument constructor to initialize Rational object to n/d
Rational::Rational(int n, int d)
{
    if (d != 0)
    {
        numerator = n;
        denominator = d;
        normalize();
    }
    else
    {
        numerator = 0;
        denominator = 1;
    }
}

// Overloaded operator>= to compare Rational objects
bool Rational::operator>=(const Rational& r) const
{
    return (numerator * r.denominator >= r.numerator * denominator);
}

// Overloaded operator+ to perform addition of Rational objects
Rational Rational::operator+(const Rational& r) const
{
    return Rational(numerator * r.denominator + r.numerator * denominator, denominator * r.denominator);
}

// Overloaded operator- to perform subtraction of Rational objects
Rational Rational::operator-(const Rational& r) const
{
    return Rational(numerator * r.denominator - r.numerator * denominator, denominator * r.denominator);
}

// Overloaded operator* to perform multiplication of Rational objects
Rational Rational::operator*(const Rational& r) const
{
    return Rational(numerator * r.numerator, denominator * r.denominator);
}

// Overloaded operator/ to perform division of Rational objects
Rational Rational::operator/(const Rational& r) const
{
    return Rational(numerator * r.denominator, denominator * r.numerator);
}
