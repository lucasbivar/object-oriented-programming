#ifndef __PESSOA_H__
#define __PESSOA_H__

#include <iostream>
using std::ostream;

#include <string>
using std::string;

class Pessoa {
public:
  Pessoa(string nome, string email){
    this->setNome(nome);
    this->setEmail(email);
  };

  virtual ~Pessoa()=default;

  string getNome() const {
    return nome;
  };

  void setNome(string nome){
    this->nome = nome;
  }

  string getEmail() const {
    return email;
  }

  void setEmail(string email){
    // TODO: VALIDAR EMAIL
    this->email = email;
  }

  virtual void exibirPessoa() const = 0;
  
protected:
  string nome;
  string email;
};

#endif 