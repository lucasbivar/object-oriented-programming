#ifndef CLIENTE_H
#define CLIENTE_H

#include "PessoaFisica.h"

#include <string>
using std::string;

#include <iostream>
using std::ostream;

class Cliente : public PessoaFisica {
  friend ostream& operator<<(ostream&, const Cliente&);
public:
  Cliente(string="", unsigned long long=0, string="", unsigned int=0);

  void setAddress(string address);
  string getAddress() const;

  void setPhone(unsigned int phone);
  unsigned int getPhone() const;

private:
  string address;
  unsigned int phone;
};

#endif