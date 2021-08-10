#include "Person.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

Person::Person(string name, int age, double height){
  setName(name);
  setAge(age);
  setHeight(height);
}

string Person::getName() const {
  return name;
}

void Person::setName(string name){
  this->name = name;
}

int Person::getAge() const{
  return age;
}

void Person::setAge(int age){
  this->age = age;
}

double Person::getHeight() const{
  return height;
}

void Person::setHeight(double height){
  this->height = height;
}

void Person::showPerson() const{
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cout << "Name: " << getName() << endl;
  cout << "Age: " << getAge() << endl;
  cout << "Height: " << getHeight() << endl;
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
}