#include "ContaPoupanca.h"

#include "Transacao.h"

#include <iostream>
using std::cout;
using std::endl;
using std::ios_base;

ContaPoupanca::ContaPoupanca(string nome, string numeroDaConta, int diaDeAniversario): 
Conta(nome, numeroDaConta){
  this->diaDeAniversario = diaDeAniversario > 0 && diaDeAniversario <= 31 ? diaDeAniversario : 10;
}
 
bool ContaPoupanca::deposito(double valor){
  if(valor > 0){
    this->saldo += valor;

    Transacao transacaoAtual(valor, "DEPOSITO");
    this->listaDeTransacoes.push_back(transacaoAtual);

    return true;
  }
  return false;
}

bool ContaPoupanca::retirada(double valor){
  if(valor > 0 && valor <= saldo){
    valor *= -1;
    this->saldo += valor;

    Transacao transacaoAtual(valor, "RETIRADA");
    this->listaDeTransacoes.push_back(transacaoAtual);

    return true;
  }
  return false;
}

void ContaPoupanca::imprimirExtrato() const {
  cout << endl;
  cout << "=-=-=-=-=-=-=-=-=-=EXTRATO=-=-=-=-=-=-=-=-=" << endl;
  cout << "DADOS:" << endl;
  cout << "Tipo da Conta       - Poupança" << endl;
  cout << "Nome do Correntista - " << nome << endl;
  cout << "Numero da Conta     - " << numeroDaConta << endl;
  cout << "Dia de Aniversário  - " << diaDeAniversario << endl;
  cout << "-------------------------------------------" << endl;
  cout << "TRANSAÇÕES:" << endl;
  cout << "Data        |  Descrição  |  Valor (R$)" << endl;
  cout << "------------|-------------|----------------" << endl;
  if(!listaDeTransacoes.empty()){
    for(Transacao t: listaDeTransacoes){
      cout << t.getData() << "  |  " << t.getDescricao() << "   |  " << (t.getDescricao() == "DEPOSITO" ? "+": "")  << t.getValorDaTransacao() << endl; 
    }
  }else{
    cout << "     Nenhuma transação foi realizada!      " << endl;
  }
  cout << "-------------------------------------------" << endl;
  cout << "SALDO ATUAL:" << endl;
  cout.setf(ios_base::fixed);
  cout.precision(2);
  cout <<"R$ " << saldo << endl;
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cout << endl;
}