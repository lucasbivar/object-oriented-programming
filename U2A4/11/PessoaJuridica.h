#ifndef PESSOA_JURIDICA_H
#define PESSOA_JURIDICA_H

#include "Pessoa.h"

class PessoaJuridica : public Pessoa {
  
public:
  PessoaJuridica(string="", unsigned long long=0, string="");

  void setCnpj(unsigned long long);
  unsigned long long getCnpj() const;

  void setSocialReason(string);
  string getSocialReason() const;

private:
  unsigned long long cnpj;
  string socialReason;
};

#endif