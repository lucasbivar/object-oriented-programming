#include "Funcionario.h"

#include <iostream>
using std::cout;
using std::endl;

int main(){
  Funcionario employee("Pedro José", 12312312312, 23023, 220, 184, 5200);

  cout << employee << endl;

  return 0;
}

// g++ -Wall -std=c++17  U2A4/9/*.cpp -o main && ./main
