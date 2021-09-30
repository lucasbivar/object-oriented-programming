#ifndef CONTA_H
#define CONTA_H

#include <string>
using std::string;

#include "../Transacao/Transacao.h"

#include "Pessoa.h"

#include "../Excecoes/ValorInvalido.h"
#include "../Excecoes/SaldoInsuficiente.h"

#include <list>
using std::list;

#include <string>
using std::string;
using std::to_string;

#include <string.h>

#include <time.h>


class Conta {
public:

  Conta(Pessoa* p){
    this->pessoa = p;
    this->saldo = 0;
    strcpy(this->numeroDaConta, this->gerarNumeroConta()); 
  }

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

    char descricao[50];
    strcpy(descricao, "Transferencia para ");
    strcat(descricao, ptrConta->numeroDaConta);

    Transacao transacaoEnviado(valor, descricao, this->numeroDaConta);
    this->listaDeTransacoes.push_back(transacaoEnviado);


    valor *= -1;
    ptrConta->saldo += valor;

    strcpy(descricao, "Recebendo transferencia de ");
    strcat(descricao, this->numeroDaConta);

    Transacao transacaoRecebido(valor, descricao, ptrConta->numeroDaConta);
    ptrConta->listaDeTransacoes.push_back(transacaoRecebido);

  }

  virtual void imprimirExtrato() const = 0;

private:

  const char* gerarNumeroConta(){

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


    string novoNumeroConta = ano+dia+mes+segundo+hora+minuto;

    return novoNumeroConta.c_str();
  }

protected:
  Pessoa* pessoa;
  char numeroDaConta[20];
  double saldo;
  list<Transacao> listaDeTransacoes;

  virtual bool validarRetirada(double valor) const {
    if(valor <= 0){
      throw ValorInvalido();
    }else if(valor > this->saldo){
      throw SaldoInsuficiente();
    }
  }
};

#endif