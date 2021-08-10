#include "Pessoa.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

Pessoa::Pessoa(string name, int age, double height){
  setName(name);
  setAge(age);
  setHeight(height);
}

string Pessoa::getName() const {
  return name;
}

void Pessoa::setName(string name){
  this->name = name;
}

int Pessoa::getAge() const {
  return age;
}

void Pessoa::setAge(int age){
  this->age = age;
}

double Pessoa::getHeight() const {
  return height;
}

void Pessoa::setHeight(double height){
  this->height = height;
}

void Pessoa::showPerson() const {
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cout << "Name: " << getName() << endl;
  cout << "Age: " << getAge() << endl;
  cout << "Height: " << getHeight() << endl;
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
}