#include <iostream>
using std::cout;
using std::endl;

void swap(int &n1, int &n2);

int main(){
  int a = 5, b = 10;

  cout << "A: " << a  << " | B: " << b << endl;

  swap(a, b);

  cout << "A: " << a  << " | B: " << b << endl;
  return 0;
}

void swap(int &n1, int &n2){
  int tmp = n1;
  n1 = n2;
  n2 = tmp;
}