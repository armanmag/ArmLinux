#include "complex.h"
#include <iostream>
#include <cmath>

Complex::Complex(double r, double i) : a(r), b(i) {}

Complex Complex::operator+(const Complex& other) const {
    return Complex(a + other.a, b + other.b);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(a - other.a, b - other.b);
}

Complex Complex::operator*(double k) const {
    return Complex(a * k, b * k);
}

double Complex::abs() const {
    return std::sqrt(a * a + b * b);
}

void Complex::print() const {
    std::cout << a << (b >= 0 ? " + " : " - ")
              << std::abs(b) << "i";
}

