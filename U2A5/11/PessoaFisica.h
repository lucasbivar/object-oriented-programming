#ifndef PESSOA_FISICA_H
#define PESSOA_FISICA_H

#include "Pessoa.h"

#include <string>
using std::string;

class PessoaFisica: public Pessoa {
public:
  PessoaFisica(string="", string="", string="", 
    unsigned int=NULL, string="", string="", string="");
    
  virtual void exibirPessoa() const;

  virtual string getCpfOrCnpj() const;

private:
  string cpf, dataDeNascimento, estadoCivil;
};

#endif 