#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using std::ostream;

class Complex {
  friend ostream& operator<<(ostream&, const Complex&);
public:
  Complex(double = 0, double = 0);

  const Complex& operator+(const Complex&) const;
  const Complex& operator-(const Complex&) const;

  const Complex& operator+=(const Complex&);
  const Complex& operator-=(const Complex&);

  // prefix
  Complex& operator++();
  Complex& operator--();

  //postfix
  Complex operator++(int); 
  Complex operator--(int); 

private:
  double real;
  double imaginary;
};

#endif 