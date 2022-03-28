#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>
#include <cmath>

class Rational {

private:
    int numerator;
    int denominator;

    static int sign(const int);
    static int gcd(int a, int b);

public:
    
    Rational();
    Rational(const int, const int);

    Rational negate() const;
    Rational reciprocal() const;

    Rational add(const Rational& that) const;
    Rational subtract(const Rational& that) const;
    Rational multiply(const Rational& that) const;
    Rational divide(const Rational& that) const;

    void print() const;

};

#endif
