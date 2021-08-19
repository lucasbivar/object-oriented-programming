#include <iostream>
using std::cout;
using std::endl;

#include "Complex.h"

int main(){
  Complex n1(10, 2);
  Complex n2(-6, 7);

  cout << "N1: " << n1;
  cout << "N2: " << n2;
  cout << endl;

  Complex n3 = n1 + n2;
  cout << "N1 + N2 = N3 = " << n3;
  Complex n4 = n1 - n2;
  cout << "N1 - N2 = N4 = " << n4;
  cout << endl;

  n3 -= n2;
  cout << "N3 -= N2 ->" << n3;
  n4 += n2;
  cout << "N4 += N2 -> " << n4;
  cout << endl;

  cout << "++N2 = " << ++n2;
  cout << "N2++ = " << n2++;
  cout << endl;

  cout << "--N1 = " << --n1;
  cout << "N1-- = " << n1--;
  cout << endl;

  return 0;
}

// g++ -Wall -std=c++17  U2A3/7/*.cpp -o main && ./main
