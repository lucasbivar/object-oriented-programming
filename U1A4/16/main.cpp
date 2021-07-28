#include "Carro.h"

int main() {
  
  Carro carroTeste1("", 2020);

  carroTeste1.displayMessage();

  Carro carroTeste2("Uma marca bem grande", 2010);
  carroTeste2.displayMessage();

  return 0;
}

// g++ -Wall -std=c++17 U1A4/16/*.cpp -o main && ./main