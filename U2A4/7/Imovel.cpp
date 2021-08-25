#include "Imovel.h"

Imovel::Imovel(string address, double price) {
  setAddress(address);
  setPrice(price < 0 ? 0 : price);
}

void Imovel::setAddress(string address){
  this->address = address;
}

string Imovel::getAddress() const {
  return address;
}

void Imovel::setPrice(double price){
  this->price = price;
}

double Imovel::getPrice() const {
  return price;
}