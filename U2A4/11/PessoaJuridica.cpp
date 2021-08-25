#include "PessoaJuridica.h"

PessoaJuridica::PessoaJuridica(string name, unsigned long long cnpj, string socialReason) :
Pessoa(name){
  setCnpj(cnpj);
  setSocialReason(socialReason);
}

void PessoaJuridica::setCnpj(unsigned long long cnpj){
  this->cnpj = cnpj;
}

unsigned long long PessoaJuridica::getCnpj() const {
  return cnpj;
}

void PessoaJuridica::setSocialReason(string socialReason){
  this->socialReason = socialReason;
}

string PessoaJuridica::getSocialReason() const {
  return socialReason;
}