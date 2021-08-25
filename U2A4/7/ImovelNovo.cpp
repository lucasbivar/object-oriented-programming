#include "ImovelNovo.h"

ImovelNovo::ImovelNovo(string address, double price, double additionalFee) : 
Imovel(address, price){
  setAdditionalFee(additionalFee < 0 ? 500 : additionalFee);
}

void ImovelNovo::setAdditionalFee(double value){
  additionalFee =  value < 0 ? 500 : value;
}

double ImovelNovo::getAdditionalFee() const {
  return additionalFee;
}

double ImovelNovo::getPrice() const {
 
  return price + getAdditionalFee();
}