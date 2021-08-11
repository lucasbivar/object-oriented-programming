#include "IntegerSet.h"

#include <iostream>
using std::cout;
using std::endl;

int main(){
  int arr[10] = {0, 2, 15, 24, 45, 62, 74, 82, 88, 99};

  IntegerSet set(arr, 10);

  cout << "Conjunto 1 -> ";
  set.print();

  cout << "Deletando os elementos 24 e 82..." << endl << endl;
  set.deleteElement(24);
  set.deleteElement(82);

  cout << "Conjunto 1 -> ";
  set.print();

  IntegerSet set2;
  set2.insertElement(2);
  set2.insertElement(10);
  set2.insertElement(15);
  set2.insertElement(46);
  set2.insertElement(74);
  set2.insertElement(86);

  cout << "Conjunto 2 -> ";
  set2.print();

  IntegerSet intersectSet = intersectionOfSets(set, set2);
  
  cout << endl << "Intersecção do Conj. 1 com o Conj. 2 -> ";
  intersectSet.print();

  
  IntegerSet unionSet = unionOfSets(set, set2);

  cout << "União do Conj. 1 com o Conj. 2 -> ";
  unionSet.print();

  return 0;
}

// g++ -Wall -std=c++17  U2A2/11/*.cpp -o main && ./main