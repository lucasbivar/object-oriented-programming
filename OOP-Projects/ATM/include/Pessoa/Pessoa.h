#ifndef __PESSOA_H__
#define __PESSOA_H__

#include <iostream>
using std::ostream;

#include <string.h>

class Pessoa {
public:
  Pessoa(const char* nome, const char* email){
    this->setNome(nome);
    this->setEmail(nome);
  };

  const char* getNome() const {
    return nome;
  };

  void setNome(const char* nome){
    strcpy(this->nome, nome);
  }

  const char* getEmail() const {
    return email;
  }

  void setEmail(const char* email){
    // TODO: VALIDAR EMAIL
    strcpy(this->email, email);
  }

  virtual void exibirPessoa() const = 0;
  
protected:
  char nome[100];
  char email[100];
};

#endif 