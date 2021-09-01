#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using std::string;

class Pessoa{
public:
  Pessoa(string="", string="", string="", unsigned int=NULL);

  string getNome() const;
  
  virtual string getCpfOrCnpj() const = 0;

  virtual void exibirPessoa() const = 0;

protected:
  string nome, endereco, email;
  unsigned int telefone;
};


#endif