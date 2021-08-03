#include <iostream>
using std::cout;
using std::endl;

#include "Retangulo.h"

int main(){
  Retangulo r, r1(10), r2(23, 14), r3(12, 3);
  
  cout << "Retangulo 0 - Altura: " << r.getAltura() << " - Largura: " << r.getLargura() << endl;
  cout << "Perimetro: " << r.perimetro() << " - Area: " << r.area() << endl << endl; 

  cout << "Retangulo 1 - Altura: " << r1.getAltura() << " - Largura: " << r1.getLargura() << endl;
  cout << "Perimetro: " << r1.perimetro() << " - Area: " << r1.area() << endl << endl;

  cout << "Retangulo 2 - Altura: " << r2.getAltura() << " - Largura: " << r2.getLargura() << endl;
  cout << "Perimetro: " << r2.perimetro() << " - Area: " << r2.area() << endl << endl;

  cout << "Retangulo 3 - Altura: " << r3.getAltura() << " - Largura: " << r3.getLargura() << endl;
  cout << "Perimetro: " << r3.perimetro() << " - Area: " << r3.area() << endl << endl;
}