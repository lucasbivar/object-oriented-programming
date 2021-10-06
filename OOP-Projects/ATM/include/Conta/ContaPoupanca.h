#ifndef CONTA_POUPANCA_H
#define CONTA_POUPANCA_H

#include <string>
using std::string;

#include "Conta.h"

#include "../Pessoa/Pessoa.h"

class ContaPoupanca : public Conta {
public:
  ContaPoupanca(Pessoa* p=nullptr, string prefixoConta="", string prefixoPessoa="", 
                int dataDeAniversario=10 , double saldo=0, 
                string numeroDaConta="", list<Transacao> transacoes=list<Transacao>());


  virtual void imprimirExtrato() const;
  virtual void mostrarConta() const;
  
  void setDiaDeAniversario(int dia);
  int getDiaDeAniversario() const;
private:
  int diaDeAniversario; 
};

#endif
