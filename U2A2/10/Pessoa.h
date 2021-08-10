#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using std::string;

class Pessoa{
public:
  Pessoa(string="", int=0, double=0);

  string getName() const;
  void setName(string);

  int getAge() const;
  void setAge(int);

  double getHeight() const;
  void setHeight(double);

  void showPerson() const;
private:
  string name;
  int age;
  double height;
};

#endif