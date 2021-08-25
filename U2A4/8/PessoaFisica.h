#ifndef PESSOA_FISICA_H
#define PESSOA_FISICA_H

#include "Pessoa.h"

class PessoaFisica : public Pessoa {
public:
  PessoaFisica(string="", unsigned long long=0);

  void setCpf(unsigned long long);
  unsigned long long getCpf() const;

private:
  unsigned long long cpf;
};

#endif