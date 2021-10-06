#ifndef PESSOA_JURIDICA_H
#define PESSOA_JURIDICA_H

#include "Pessoa.h"

#include <string>
using std::string;

class PessoaJuridica: public Pessoa {
public:
  PessoaJuridica(string ="", string ="", string ="", 
    string ="", string ="");
  

  string getCNPJ() const;
  void setCNPJ(string);

  string getInscricaoEstadual() const;
  void setInscricaoEstadual(string);

  string getRazaoSocial() const;
  void setRazaoSocial(string);

  virtual void exibirPessoa() const;

private:
  string CNPJ;
  string inscricaoEstadual;
  string razaoSocial;
};

#endif 