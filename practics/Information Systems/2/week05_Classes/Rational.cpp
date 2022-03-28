#include "Rational.hpp"

int Rational::gcd(int a, int b) {

    if (b == 0) return a;

    else {
        return gcd(b, a % b);
    }
}

int Rational::sign(const int num) {

    if (num < 0) return -1;
    else { return 1; }
}

Rational::Rational() {}

Rational::Rational(const int numer, const int denom) {

    int div = gcd(numer, denom);

    this->numerator = numer / div * sign(denom);
    
    if (denom != 0) this->denominator = abs(denom) / div;
    else {
        throw "Tried to create a number with denominator zero!";
    }
}

Rational Rational::negate() const {
    return Rational(numerator * -1, denominator);
}

Rational Rational::reciprocal() const {
    return Rational(denominator, numerator);
}

Rational Rational::add(const Rational& that) const {

    int numer = this->numerator * that.denominator + that.numerator * this->denominator;
    int denom = this->denominator * that.denominator;

    return Rational(numer, denom);
}

Rational Rational::subtract(const Rational& that) const {

    return this->add(that.negate());
}

Rational Rational::multiply(const Rational& that) const {
    return Rational(this->numerator * that.numerator, this->denominator * that.denominator);
}

Rational Rational::divide(const Rational& that) const {
    return multiply(that.reciprocal());
}

void Rational::print() const {
    std::cout << this->numerator << '/' << this->denominator;
}