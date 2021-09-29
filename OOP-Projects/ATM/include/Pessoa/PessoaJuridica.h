#ifndef PESSOA_JURIDICA_H
#define PESSOA_JURIDICA_H

#include "Pessoa.h"

class PessoaJuridica: public Pessoa {
public:
  PessoaJuridica(const char* ="", const char* ="", const char* ="", 
    const char* ="", const char* ="");

  const char* getCNPJ() const;
  void setCNPJ(const char*);

  const char* getInscricaoEstadual() const;
  void setInscricaoEstadual(const char*);

  const char* getRazaoSocial() const;
  void setRazaoSocial(const char*);

  virtual void exibirPessoa() const;

private:
  char CNPJ[14];
  char inscricaoEstadual[9];
  char razaoSocial[100];
};

#endif 