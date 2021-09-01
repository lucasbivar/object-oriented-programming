#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "FormaBidimensional.h"

#include <iostream>
using std::cout;
using std::endl;

#include <math.h>

class Triangulo : public FormaBidimensional {
public:
  Triangulo(double base = 0, double altura = 0) : FormaBidimensional(3) {
    this->base = base;
    this->altura = altura;
  }

  virtual void desenhar() {
    cout << "  .   " << endl;
    cout << " / \\ " << endl;
    cout << "/   \\" << endl;
    cout << " ---  " << endl;
  }

  virtual double calcularArea(){
    return (sqrt(3.)/4.)*pow(base, 2);
  }

  virtual double calcularPerimetro(){
    return 3*base;
  }
private:
  double base, altura;
};

#endif