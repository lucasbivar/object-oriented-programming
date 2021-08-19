#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include "Array.h"

int main() {
  Array a1(7);  //array de 7 elementos
  Array a2;     //array de 10 elementos

  // preenchendo os arrays
  for(int i = 0; i < a1.getSize(); i++) a1[i] = i;
  for(int i = 0; i < a2.getSize(); i++) a2[i] = i;

  cout << "Array A1 -> " << a1;
  cout << "Array A2 -> " << a2;

  cout << endl;

  Array a3 = a1 + a2;
  cout << "Array A3 = Array A1 + Array A2 -> " << a3;
  cout << endl;

  a3 += a1;
  cout << "Array A3 += Array A1 -> " << a3;
 
  return 0;
}

// g++ -Wall -std=c++17  U2A3/5/*.cpp -o main && ./main