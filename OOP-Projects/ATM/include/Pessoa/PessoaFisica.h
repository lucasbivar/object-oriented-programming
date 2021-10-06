#ifndef PESSOA_FISICA_H
#define PESSOA_FISICA_H

#include "Pessoa.h"

class PessoaFisica: public Pessoa {
public:
  PessoaFisica(string ="", string ="", string ="",
   string ="", string ="");

  string getCPF() const;
  void setCPF(string cpf);

  string getDataDeNascimento() const;
  void setDataDeNascimento(string);

  string getEstadoCivil() const;
  void setEstadoCivil(string);

  virtual void exibirPessoa() const;
private:
  string CPF;
  string dataDeNascimento;
  string estadoCivil;
};


#endif 