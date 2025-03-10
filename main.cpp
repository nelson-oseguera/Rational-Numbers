#include "Rational.h"
#include <iostream>

using namespace std;

int main()
{
    // create objects of Rational class using default constructor
    Rational r1, r2;

    // input the value of r1 using overloaded operator>>
    cout << "Enter the numerator and denominator for r1 (in the form numerator/denominator): ";
    cin >> r1;

    // input the value of r2 using overloaded operator>>
    cout << "Enter the numerator and denominator for r2 (in the form numerator/denominator): ";
    cin >> r2;

    // display the 2 objects using overloaded operator<<
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;

    // test the operator >=
    cout << endl;
    cout << boolalpha;
    cout << r1 << " >= " << r2 << ": " << (r1 >= r2) << endl;
    cout << r2 << " >= " << r1 << ": " << (r2 >= r1) << endl;

    // test the operators +, -, * and /
    cout << endl;
    Rational result = r1 + r2;
    cout << r1 << " + " << r2 << ": " << result << endl;
    result = r1 - r2;
    cout << r1 << " - " << r2 << ": " << result << endl;
    result = r1 * r2;
    cout << r1 << " * " << r2 << ": " << result << endl;
    result = r1 / r2;
    cout << r1 << " / " << r2 << ": " << result << endl;

    return 0;
}
