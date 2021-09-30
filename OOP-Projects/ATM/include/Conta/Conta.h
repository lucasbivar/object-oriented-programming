#ifndef CONTA_H
#define CONTA_H

#include <string>
using std::string;

#include "../Transacao/Transacao.h"

#include "Pessoa.h"

#include "../Excecoes/DepositoInvalido.h"
#include "../Excecoes/SaldoInsuficiente.h"

#include <list>
using std::list;

#include <string>
using std::string;

class Conta {
public:

  Conta(Pessoa* p){
    this->pessoa = p;
    this->saldo = 0;
    this->numeroDaConta; 
  }

  void operator<<(double valor){
    if(valor <=0){
      throw DepositoInvalido();
    }

    Transacao transacaoAtual(valor, "DEPOSITO", this->numeroDaConta);
    this->listaDeTransacoes.push_back(transacaoAtual);

    saldo += valor;
  }

  virtual void operator>>(double valor){
    if(valor <= 0 || valor > saldo){
      throw SaldoInsuficiente();
    }

    valor *= -1;
    this->saldo += valor;

    Transacao transacaoAtual(valor, "RETIRADA", this->numeroDaConta);
    this->listaDeTransacoes.push_back(transacaoAtual);
  }

  void transferir(double valor, Conta* ptrConta){
    *this >> valor;
    *ptrConta << valor;
  }

  virtual void imprimirExtrato() const = 0;

protected:
  Pessoa* pessoa;
  char numeroDaConta[15];
  double saldo;
  list<Transacao> listaDeTransacoes;
};

#endif