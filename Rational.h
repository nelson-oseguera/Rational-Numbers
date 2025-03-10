#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

using namespace std;

class Rational
{
private:
    // data members
    int numerator;
    int denominator;

    // helper function to reduce the Rational number to simplest form
    void normalize();

    // overloaded input and output operators
    friend ostream& operator<<(ostream& out, const Rational& r);
    friend istream& operator>>(istream& in, Rational& r);

public:
    // constructors
    Rational();
    Rational(int n);
    Rational(int n, int d);

    // overloaded operators
    bool operator>=(const Rational& r) const;
    Rational operator+(const Rational& r) const;
    Rational operator-(const Rational& r) const;
    Rational operator*(const Rational& r) const;
    Rational operator/(const Rational& r) const;
};

#endif // RATIONAL_H
