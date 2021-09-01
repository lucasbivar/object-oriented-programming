#include "ContaCorrenteLimite.h"

#include "Transacao.h"

#include <iostream>
using std::cout;
using std::endl;
using std::ios_base;

ContaCorrenteLimite::ContaCorrenteLimite(string nome, string numeroDaConta, double limite): 
Conta(nome, numeroDaConta){
  this->limite = limite >= 0 ? limite : 200;
}
 
bool ContaCorrenteLimite::deposito(double valor){
  if(valor > 0){
    this->saldo += valor;

    Transacao transacaoAtual(valor, "DEPOSITO");
    this->listaDeTransacoes.push_back(transacaoAtual);

    return true;
  }
  return false;
}

bool ContaCorrenteLimite::retirada(double valor){
  if(valor > 0 && valor <= saldo + limite){
    valor *= -1;
    this->saldo += valor;

    Transacao transacaoAtual(valor, "RETIRADA");
    this->listaDeTransacoes.push_back(transacaoAtual);

    return true;
  }
  return false;
}

void ContaCorrenteLimite::imprimirExtrato() const {
  cout.setf(ios_base::fixed);
  cout.precision(2);
  cout << endl;
  cout << "=-=-=-=-=-=-=-=-=-=EXTRATO=-=-=-=-=-=-=-=-=" << endl;
  cout << "DADOS:" << endl;
  cout << "Tipo da Conta       - Corrente Com Limite" << endl;
  cout << "Nome do Correntista - " << nome << endl;
  cout << "Numero da Conta     - " << numeroDaConta << endl;
  cout << "Limite da Conta     - R$ " << limite << endl;
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
  cout <<"R$ " << saldo << endl;
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cout << endl;
}