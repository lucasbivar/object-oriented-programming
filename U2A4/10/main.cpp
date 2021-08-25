#include "Cliente.h"

#include <iostream>
using std::cout;
using std::endl;

int main(){
  Cliente client("Lucas Bivar", 12312312312, "Rua Joao da Silva Cabral", 988360000);

  cout << client << endl;

  return 0;
}

// g++ -Wall -std=c++17  U2A4/10/*.cpp -o main && ./main