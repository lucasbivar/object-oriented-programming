#ifndef PESSOA_JURIDICA_H
#define PESSOA_JURIDICA_H

#include "Pessoa.h"

#include <string>
using std::string;

class PessoaJuridica: public Pessoa {
public:
  PessoaJuridica(string="", string="", string="", 
    unsigned int=NULL, string="", string="", string="");
    
  virtual void exibirPessoa() const;

  virtual string getCpfOrCnpj() const;

private:
  string cnpj, inscricaoEstadual, razaoSocial;
};

#endif 