#include <iostream>
using std::cout;
using std::endl;

#include "HugeInteger.h"

int main(){
  HugeInteger n1, n2;

  n1.input("23459");
  cout << "N1: ";
  n1.output();
  
  n2.input("94489");
  cout << "N2: ";
  n2.output();

  cout << endl;

  n1.add(n2);
  cout << "N1 += N2" << endl;

  cout << endl;

  cout << "N1: ";
  n1.output();
  
  cout << "N2: ";
  n2.output();

  cout << endl;

  cout << (n1.isEqualTo(n2) ? "True" : "False") << endl;
  cout << (n1.isNotEqualTo(n2) ? "True" : "False") << endl;
  cout << (n1.isGreaterThan(n2) ? "True" : "False") << endl;
  cout << (n1.isGreaterThanOriqual(n2) ? "True" : "False") << endl;
  cout << (n1.isLessThan(n2) ? "True" : "False") << endl;
  cout << (n1.isLessThanOriqual(n2) ? "True" : "False") << endl;

  return 0;
}

// g++ -Wall -std=c++17 U2A1/9/*.cpp -o main && ./main