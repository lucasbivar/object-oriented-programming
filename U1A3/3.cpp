#include <iostream>
using std::cout;
using std::endl;

unsigned int plusOne(void);

int main(){

  cout << plusOne() << endl;
  cout << plusOne() << endl;
  cout << plusOne() << endl;
  cout << plusOne() << endl;

  return 0;
}

unsigned int plusOne(){
  static unsigned int num = 0;
  return num++;
}