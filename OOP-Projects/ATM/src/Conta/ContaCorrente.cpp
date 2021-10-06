#include "../../include/Conta/ContaCorrente.h"

#include "../../include/Transacao/Transacao.h"

#include <iostream>
using std::cout;
using std::endl;
using std::ios_base;

#include <list>
using std::list;

#include <string>
using std::string;

#include <iomanip>
using std::setw;

ContaCorrente::ContaCorrente(Pessoa* p, string prefixoConta, string prefixoPessoa, double saldo, 
                            string numeroDaConta, list<Transacao> transacoes): 
              Conta(p, prefixoConta, prefixoPessoa, saldo, numeroDaConta, transacoes){

}
 
void ContaCorrente::imprimirExtrato() const {
  cout << endl;
  cout << "=-=-=-=-=-=-=-=-=-=EXTRATO=-=-=-=-=-=-=-=-=" << endl;
  cout << "DADOS:" << endl;
  cout << "Tipo da Conta       - Corrente" << endl;
  cout << "Nome do Correntista - " << this->pessoa->getNome() << endl;
  cout << "Numero da Conta     - " << this->numeroDaConta << endl;
  cout << "-------------------------------------------" << endl;
  cout << "TRANSAÇÕES:" << endl;
  cout << "Data        |  Descrição     | Valor (R$)" << endl;
  cout << "------------|----------------|-------------" << endl;
  if(!listaDeTransacoes.empty()){
    int c = 0;

    for(auto it = listaDeTransacoes.rbegin(); it != listaDeTransacoes.rend(); it++){
      if(c > 30) break;
      cout << it->getData() << "  |  " << setw(13) << it->getDescricao() << " |  ";
      
      cout << ((it->getDescricao() == "DEPOSITO" || (it->getDescricao() == "TRANSFERENCIA"
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

void ContaCorrente::mostrarConta() const {
  cout << endl;
  cout << "=-=-=-=-=-=-=-=Dados da Conta-=-=-=-=-=-=-=" << endl;
  cout << "DADOS:" << endl;
  cout << "Tipo da Conta         - Corrente" << endl;
  cout << "Nome do Correntista   - " << this->pessoa->getNome() << endl;
  cout << "E-mail do Correntista - " << this->pessoa->getEmail() << endl;
  cout << "Numero da Conta       - " << this->numeroDaConta << endl;
  cout << "-------------------------------------------" << endl;
  cout << "SALDO ATUAL:" << endl;
  cout << "R$ " << saldo << endl;
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cout << endl;
}
