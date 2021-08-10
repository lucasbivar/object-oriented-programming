#include "Person.h"

int main(){
  Person p1("Mark Zuckernerg", 37, 1.71), p2("Sundar Pichai", 49, 1.80), 
  p3("Jeff Bezos", 57, 1.71);

  p1.showPerson();

  p2.showPerson();

  p3.showPerson();

  return 0;
}

// g++ -Wall -std=c++17  U2A2/8/*.cpp -o main && ./main