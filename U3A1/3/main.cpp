#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string.h>

int main(){
  char str[100];

  cout << "Digite sua string:" << endl;
  cin.getline(str, sizeof(str));

  unsigned int strSize = strlen(str);

  cout.width(strSize*2);
  cout << str << endl;
  
  return 0;
}