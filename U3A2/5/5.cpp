#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

template<class T>
bool comparar(const T& a, const T&b){
  
  return a == b;
}

int main(){

  cout << "1 == 2: " << (comparar(1, 2) ? "true" : "false") << endl;
  cout << "5 == 5: " << (comparar(5, 5) ? "true" : "false") << endl;

  cout << endl;

  cout << "\"computador\" == \"computador\": " << 
    (comparar("computador", "computador") ? "true" : "false") << endl;
  cout << "\"computador\" == \"celular\": " << 
    (comparar(string("computador"), string("celular")) ? "true" : "false") << endl;

  cout << endl;

  cout << "10.2 == 25.3: " << (comparar(10.2, 25.3) ? "true" : "false") << endl;
  cout << "12.3 == 12.3: " << (comparar(12.3, 12.3) ? "true" : "false") << endl;

  return 0;
}