#ifndef QUADRADO_H
#define QUADRADO_H

#include "FormaBidimensional.h"

#include <iostream>
using std::cout;
using std::endl;

class Quadrado : public FormaBidimensional {
public:
  Quadrado(double lado = 0) : FormaBidimensional(4) {
    this->lado = lado;
  }

  virtual void desenhar() {
    cout << "-----" << endl;
    cout << "|   |" << endl;
    cout << "-----" << endl;
  }

  virtual double calcularArea(){
    return lado*lado;
  }

  virtual double calcularPerimetro(){
    return 4*lado;
  }

private:
  double lado;
};

#endif