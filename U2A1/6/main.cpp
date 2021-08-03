#include <iostream>
using std::cout;
using std::endl;

#include "Time.h"

int main() {
  Time t(23,59,55);
  t.printUniversal();
  
  for(int i = 0; i < 70; i++){
    t.tick();
    t.printUniversal();
  }

  return 0;
}

// g++ -Wall -std=c++17 U2A1/6/*.cpp -o main && ./main