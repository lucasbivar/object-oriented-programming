#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;

#include "Array.h"

int main() {
  Array<int> a1(7);  //array de 7 elementos
  Array<int> a2(7);     //array de 10 elementos

  for(int i = 0; i < 7; i++){
    a1[i] = i;
    a2[i] = i;
  }

  cout << a1; 
  cout << a2;   

  cout << endl;

  if (a1 == a2)
    cout << "a1 e a2 são iguais" << endl << endl;

  Array<int> a3(a1);

  a3[5] = 100; //invoca T &operator[](int)

  cout << "a3[5] == " << a3[5] << endl;  //T operator[](int) const

  a2 = a3;

  cout << "a2[5] == " << a3[5] << endl;


  Array<string> arr_str(3);
  arr_str[0] = "Engenharia";
  arr_str[1] = "De";
  arr_str[2] = "Computacao";

  cout << arr_str;

  return 0;
}