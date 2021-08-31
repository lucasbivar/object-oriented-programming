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
    return (base*altura)/2.;
  }

  virtual double calcularPerimetro(){
    return base + 2*(sqrt(pow(altura, 2.) + pow(base/2., 2)));
  }
private:
  double base, altura;
};

#endif