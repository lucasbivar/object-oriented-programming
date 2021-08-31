#ifndef CIRCULO_H
#define CIRCULO_H

#include "FormaBidimensional.h"

#include <iostream>
using std::cout;
using std::endl;

class Circulo : public FormaBidimensional {
public:
  Circulo(double raio=0) : FormaBidimensional(99999) { 
    this->raio = raio;
  }

  virtual void desenhar() {
    cout << "  ~ " << endl;
    cout << "/   \\" << endl;
    cout << "\\   /" << endl;
    cout << "  ~ " << endl;
  }

  virtual double calcularArea(){
    return 3.14*raio*raio;
  }

  virtual double calcularPerimetro(){
    return 2*3.14*raio; 
  }
  
private:
  double raio;
};

#endif