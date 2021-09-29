#ifndef PESSOA_FISICA_H
#define PESSOA_FISICA_H

#include "Pessoa.h"

class PessoaFisica: public Pessoa {
public:
  PessoaFisica(const char* ="", const char* ="", const char* ="",
   const char* ="", const char* ="");
    
  const char* getCPF() const;
  void setCPF(const char* cpf);

  const char* getDataDeNascimento() const;
  void setDataDeNascimento(const char*);

  const char* getEstadoCivil() const;
  void setEstadoCivil(const char*);

  virtual void exibirPessoa() const;
private:
  char CPF[11];
  char dataDeNascimento[8];
  char estadoCivil[20];
};


#endif 