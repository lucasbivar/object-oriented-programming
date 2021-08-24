#include "Animal.h"
#include "Cachorro.h"
#include "Gato.h"

#include <iostream>
using std::cout;
using std::endl;

int main(){
  Animal animal("Enzo");
  Gato gato("Maya");
  Cachorro cachorro("Scooby");

  cout << animal.caminha() << endl;
  cout << gato.caminha() << endl;
  cout << cachorro.caminha() << endl;
  
  cout << gato.mia() << endl;
  cout << cachorro.late() << endl;

  return 0;
}

// g++ -Wall -std=c++17  U2A4/6/*.cpp -o main && ./main