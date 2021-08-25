#ifndef IMOVEL_H
#define IMOVEL_H

#include <string>
using std::string;

class Imovel {
public:
  Imovel(string = "", double = 0);

  void setAddress(string);
  string getAddress() const;

  void setPrice(double);
  double getPrice() const;

protected:
  string address;
  double price;
};

#endif