#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using std::string;

#include <iostream>
using std::ostream;

class Pessoa {
  friend ostream& operator<<(ostream&, const Pessoa&);
public:
  Pessoa(string="");
  
  void setName(string);
  string getName() const;
protected:
  string name;
};

#endif