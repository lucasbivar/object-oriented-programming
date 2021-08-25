#include "ImovelVelho.h"

ImovelVelho::ImovelVelho(string address, double price, double discount) : 
Imovel(address, price){
  setDiscount(discount < 0 ? 800 : discount);
}

void ImovelVelho::setDiscount(double value){
  discount =  value < 0 ? 500 : value;
}

double ImovelVelho::getDiscount() const {
  return discount;
}

double ImovelVelho::getPrice() const {
  return price - getDiscount();
}