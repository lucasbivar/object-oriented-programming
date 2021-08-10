#ifndef PERSON_H
#define PERSON_H

#include <string>
using std::string;

class Person{
public:
  Person(string, int, double);

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