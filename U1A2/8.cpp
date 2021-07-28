#include <iostream>
using std::cout;
using std::endl;

int main(){
  cout << "Padrao A:" << endl << endl;
  
  for(int i = 1; i <= 5; i++){
    for(int j = 0; j < i; j++){
      cout << '*';
    }
    cout << endl;
  }

  cout << endl << "Padrao B:" << endl << endl;

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < i; j++){
      cout << ' ';
    }
    for(int j = i; j < 5; j++){
      cout << '*';
    }
    cout << endl;
  }

  return 0;
}