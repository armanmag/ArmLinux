#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
private:
    double a; 
    double b; 

public:
    Complex(double r = 0.0, double i = 0.0);

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(double k) const;

    double abs() const;
    void print() const;
};

#endif

