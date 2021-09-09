#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
using std::defaultfloat;

int main(){
  double value = 100.453627;
  
  cout << fixed;

  cout.precision(1);
  cout << "(1) -> " << value << endl;

  cout.precision(2);
  cout << "(2) -> " << value << endl;

  cout.precision(3);
  cout << "(3) -> " << value << endl;

  cout.precision(4);
  cout << "(4) -> " << value << endl;

  return 0;
}