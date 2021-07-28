#include <iostream>
using std::cout;
using std::endl;

void swap(int*, int*);

int main(){
  int a = 5, b = 10;

  cout << "A: " << a  << " | B: " << b << endl;

  swap(&a, &b);

  cout << "A: " << a  << " | B: " << b << endl;
  
  return 0;
}

void swap(int* pN1, int* pN2){
  int tmp = *pN1;
  *pN1 = *pN2;
  *pN2 = tmp;
}