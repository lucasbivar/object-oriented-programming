#include "../../include/Conta/ContaPoupanca.h"

#include "../../include/Transacao/Transacao.h"

#include <iostream>
using std::cout;
using std::endl;
using std::ios_base;

#include <iomanip>
using std::setw;

ContaPoupanca::ContaPoupanca(Pessoa* p, string prefixoConta, string prefixoPessoa, int diaDeAniversario): 
Conta(p, prefixoConta, prefixoPessoa){
  this->diaDeAniversario = diaDeAniversario > 0 && diaDeAniversario <= 31 ? diaDeAniversario : 10;
}
 

void ContaPoupanca::imprimirExtrato() const {
  cout << endl;
  cout << "=-=-=-=-=-=-=-=-=-=EXTRATO=-=-=-=-=-=-=-=-=" << endl;
  cout << "DADOS:" << endl;
  cout << "Tipo da Conta       - Poupança" << endl;
  cout << "Nome do Correntista - " << pessoa->getNome() << endl;
  cout << "Numero da Conta     - " << numeroDaConta << endl;
  cout << "Dia de Aniversário  - " << diaDeAniversario << endl;
  cout << "-------------------------------------------" << endl;
  cout << "TRANSAÇÕES:" << endl;
  cout << "Data        |  Descrição     | Valor (R$)" << endl;
  cout << "------------|----------------|-------------" << endl;
  if(!listaDeTransacoes.empty()){
    int c = 0;
    
    for(auto it = listaDeTransacoes.rbegin(); it != listaDeTransacoes.rend(); it++){
      if(c > 30) break;
      cout << it->getData() << "  |  " << setw(13) << it->getDescricao() << " |  ";

      cout << (((strcmp(it->getDescricao(), "DEPOSITO") == 0) || ((strcmp(it->getDescricao(), "TRANSFERENCIA") == 0)
       && it->getValorDaTransacao() > 0 )) ? "+": "")  << it->getValorDaTransacao() << endl; 

      c++;
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

void ContaPoupanca::mostrarConta() const {
  cout << endl;
  cout << "=-=-=-=-=-=-=-=Dados da Conta-=-=-=-=-=-=-=" << endl;
  cout << "DADOS:" << endl;
  cout << "Tipo da Conta         - Poupança" << endl;
  cout << "Nome do Correntista   - " << pessoa->getNome() << endl;
  cout << "E-mail do Correntista - " << pessoa->getEmail() << endl;
  cout << "Numero da Conta       - " << numeroDaConta << endl;
  cout << "Dia de Aniversário    - " << diaDeAniversario << endl;
  cout << "-------------------------------------------" << endl;
  cout << "SALDO ATUAL:" << endl;
  cout << "R$ " << saldo << endl;
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cout << endl;
}

void ContaPoupanca::setDiaDeAniversario(int dia){
  // validar genericamente e criar exceção
  this->diaDeAniversario = dia;
}
