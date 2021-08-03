#include <iostream>
using std::cout;
using std::endl;

#include "Time.h"

int main() {
  Time t(10), t1(9,45,59), t2;

  cout << "t : ";
  t.printUniversal();

  cout << "t1: ";
  t1.printUniversal();

  cout << "t2: ";
  t2.printUniversal();

  return 0;
}

// g++ -Wall -std=c++17 U2A1/7/*.cpp -o main && ./main