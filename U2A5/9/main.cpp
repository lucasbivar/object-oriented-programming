#include <iostream>
using std::cout;
using std::endl;


#include "Quadrado.h"
#include "Circulo.h"
#include "Triangulo.h"

int main() {

  FormaBidimensional *formas[] = {new Quadrado(3), new Circulo(4), new Triangulo(3, 4)};

  for (int i = 0 ; i < 3 ; i++)
  {
    formas[i]->desenhar();
    cout << "Area: " << formas[i]->calcularArea() << endl;
    cout << "Perimetro: " << formas[i]->calcularPerimetro() << endl;
    delete formas[i];
  }

  return 0;
}