#include "IntegerSet.h"

#include <iostream>
using std::cout;
using std::endl;

int main(){
  int arr[10] = {0, 2, 15, 24, 45, 62, 74, 82, 88, 99};

  IntegerSet set(arr, 10);

  cout << "Conjunto 1 -> ";
  cout << set;

  cout << "Deletando os elementos 24 e 82..." << endl << endl;
  set >> 24;
  set >> 82;

  cout << "Conjunto 1 -> ";
  cout << set;

  IntegerSet set2;
  set2 << 2;
  set2 << 10;
  set2 << 15;
  set2 << 46;
  set2 << 74;
  set2 << 86;

  cout << "Conjunto 2 -> ";
  cout << set2;

  IntegerSet intersectSet = set & set2;
  
  cout << endl << "Intersecção do Conj. 1 com o Conj. 2 -> ";
  cout << intersectSet;

  
  IntegerSet unionSet = set | set2;

  cout << "União do Conj. 1 com o Conj. 2 -> ";
  cout << unionSet;

  return 0;
}

// g++ -Wall -std=c++17  U2A3/6/*.cpp -o main && ./main