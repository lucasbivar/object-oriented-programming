#include "Data.h"

#include <iostream>
using std::cout;
using std::endl;

int main(){
  Data dt(10, 10, 2002);

  cout << "Data:" << endl;
  dt.mostrarData();

  cout << endl << "Tentando alterar o mes para 15..." << endl << endl;
  dt.setMes(15);

  cout << "Nova Data:" << endl;
  dt.mostrarData();

  return 0;
}

// g++ -Wall -std=c++17 U1A4/19/*.cpp -o main && ./main