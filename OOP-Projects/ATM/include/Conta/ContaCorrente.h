#ifndef CONTA_CORRENTE_H
#define CONTA_CORRENTE_H

#include <string>
using std::string;

#include "Conta.h"

#include "../Pessoa/Pessoa.h"

class ContaCorrente : public Conta {
public:
  ContaCorrente(Pessoa* p=nullptr, string prefixoConta="", string prefixoPessoa="", double saldo=0, 
                string numeroDaConta="", list<Transacao> transacoes=list<Transacao>());


  virtual void imprimirExtrato() const;

  virtual void mostrarConta() const;
};

#endif
