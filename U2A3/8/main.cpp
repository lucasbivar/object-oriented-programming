#include <iostream>
using std::cout;
using std::endl;

#include "HugeInteger.h"

int main(){
  HugeInteger n1, n2, n3;

  n1 = "23459";
  cout << "N1: " << n1;
  
  n2 = "94489";
  cout << "N2: " << n2;

  cout << endl;

  n3 = n1 + n2;
  cout << "N1 + N2 = N3 = " << n3 << endl;

  cout << endl;

  
  cout << "N1: " << n1;
  
  cout << "N2: " << n2;

  cout << endl;

  n3 += n1;
  cout << "N3 += N1 -> " << n3 << endl;

  cout << "N1 == N2 -> " << (n1 == n2 ? "True" : "False") << endl;
  cout << "N1 != N2 -> " << (n1 != n2 ? "True" : "False") << endl;
  cout << "N1 > N2 -> " << (n1 > n2 ? "True" : "False") << endl;
  cout << "N1 >= N2 -> " << (n1 >= n2 ? "True" : "False") << endl;
  cout << "N1 < N2 -> " << (n1 < n2 ? "True" : "False") << endl;
  cout << "N1 <= N2 -> " << (n1 <= n2 ? "True" : "False") << endl;

  return 0;
}

// g++ -Wall -std=c++17 U2A3/8/*.cpp -o main && ./main