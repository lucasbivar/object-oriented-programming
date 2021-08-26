#include "Complex.h"

#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

Complex::Complex(double real, double imaginary){
  this->real = real;
  this->imaginary = imaginary;
}

const Complex Complex::operator+(const Complex& otherNumber) const {
  double newRealPart = this->real + otherNumber.real;
  double newImaginaryPart = this->imaginary + otherNumber.imaginary;

  Complex newCplx = Complex(newRealPart, newImaginaryPart);

  return newCplx;
}

const Complex Complex::operator-(const Complex& otherNumber) const {
  double newRealPart = this->real - otherNumber.real;
  double newImaginaryPart = this->imaginary - otherNumber.imaginary;

  Complex newCplx = Complex(newRealPart, newImaginaryPart);

  return newCplx;
}

const Complex& Complex::operator+=(const Complex& other){
  this->real += other.real;
  this->imaginary += other.imaginary;

  return *this;
}

const Complex& Complex::operator-=(const Complex& other){
  this->real -= other.real;
  this->imaginary -= other.imaginary;
  
  return *this;
}

Complex& Complex::operator++(){
  this->real++;
  return (*this);
}

Complex& Complex::operator--(){
  this->real--;
  return (*this);
}

Complex Complex::operator++(int){
  Complex copy = *this;
  this->real++;

  return copy;
}

Complex Complex::operator--(int){
  Complex copy = *this;
  this->real--;

  return copy;
} 

ostream& operator<<(ostream& out, const Complex& number){
  cout << number.real << " + " << number.imaginary << "i" << endl;

  return out;
}