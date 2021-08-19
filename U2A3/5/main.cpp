#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "Array.h"

int main() {
  Array a1(7);  //array de 7 elementos
  Array a2;     //array de 10 elementos
  for(int i = 0; i < a1.getSize(); i++) a1[i] = i;
  for(int i = 0; i < a2.getSize(); i++) a2[i] = i;

  cout << a1;
  cout << a2;
  Array a3 = a1 + a2;
  cout << a3;
  cout << a1;
  cout << a2;

  a3 += a1;
  cout << a3;
  cout << a1;
  cout << a2;
 
  return 0;
}

// g++ -Wall -std=c++17  U2A3/5/*.cpp -o main && ./main