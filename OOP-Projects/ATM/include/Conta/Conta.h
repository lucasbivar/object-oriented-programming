#ifndef CONTA_H
#define CONTA_H

#include <string>
using std::string;

#include<iostream>
using std::cout;
using std::endl;

#include "../Transacao/Transacao.h"

#include "../Pessoa/Pessoa.h"

#include "../Excecoes/ValorInvalido.h"
#include "../Excecoes/SaldoInsuficiente.h"

#include <list>
using std::list;

#include <string>
using std::string;
using std::to_string;

#include <time.h>


class Conta {
public:

  Conta(Pessoa* p=nullptr, string prefixoConta="", string prefixoPessoa="", double saldo = 0, string numeroDaConta="", list<Transacao> transacoes=list<Transacao>()){
    this->pessoa = p;
    this->saldo = saldo;
    this->listaDeTransacoes = transacoes;
    if(numeroDaConta == ""){
      this->gerarNumeroConta(prefixoConta, prefixoPessoa);
    }else{
      this->numeroDaConta = numeroDaConta;
    }
  } 

  virtual ~Conta()=default;


  void operator<<(double valor){
    if(valor <= 0){
      throw ValorInvalido();
    }

    Transacao transacaoAtual(valor, "DEPOSITO", this->numeroDaConta);
    this->listaDeTransacoes.push_back(transacaoAtual);

    saldo += valor;
  }

  void operator>>(double valor){
    this->validarRetirada(valor);

    valor *= -1;
    this->saldo += valor;

    Transacao transacaoAtual(valor, "RETIRADA", this->numeroDaConta);
    this->listaDeTransacoes.push_back(transacaoAtual);
  }

  void transferir(double valor, Conta* ptrConta){
    this->validarRetirada(valor);

    valor *= -1;
    this->saldo += valor;

    Transacao transacaoEnviado(valor, "TRANSFERENCIA", this->numeroDaConta);
    this->listaDeTransacoes.push_back(transacaoEnviado);


    valor *= -1;
    ptrConta->saldo += valor;

    Transacao transacaoRecebido(valor, "TRANSFERENCIA", ptrConta->numeroDaConta);
    ptrConta->listaDeTransacoes.push_back(transacaoRecebido);

  }

  virtual void imprimirExtrato() const = 0;

  virtual void mostrarConta() const = 0;


  string getNumeroDaConta() const {
    return numeroDaConta;
  }

private:

  void gerarNumeroConta(string prefixoConta, string prefixoPessoa){

    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);
    
    string dia = to_string(aTime->tm_mday);
    dia = string(2 - dia.size(), '0') + dia;
    string mes = to_string(aTime->tm_mon + 1);
    mes = string(2 - mes.size(), '0') + mes;
    string ano = to_string(aTime->tm_year + 1900);
    
    string hora = to_string((aTime->tm_hour+21)%24);
    hora = string(2 - hora.size(), '0') + hora;
    string minuto = to_string(aTime->tm_min);
    minuto = string(2 - minuto.size(), '0') + minuto;
    string segundo = to_string(aTime->tm_sec);
    segundo = string(2 - segundo.size(), '0') + segundo;


    string novoNumeroConta = prefixoConta+prefixoPessoa+ano+dia+mes+segundo+hora+minuto;
    this->numeroDaConta = novoNumeroConta;
  }

protected:
  Pessoa* pessoa;
  string numeroDaConta;
  double saldo;
  list<Transacao> listaDeTransacoes;

  friend class Banco;
  
  virtual void validarRetirada(double valor) const {
    if(valor <= 0){
      throw ValorInvalido();
    }else if(valor > this->saldo){
      throw SaldoInsuficiente();
    }
  }
};

#endif