#include "../../include/Conta/ContaCorrenteLimite.h"

#include "../../include/Transacao/Transacao.h"

#include "../../include/Excecoes/ExcedeLimite.h"
#include "../../include/Excecoes/ValorInvalido.h"

#include <iostream>
using std::cout;
using std::endl;
using std::ios_base;

#include <iomanip>
using std::setw;

ContaCorrenteLimite::ContaCorrenteLimite(Pessoa *p,string prefixoConta, string prefixoPessoa, double limite): 
Conta(p, prefixoConta, prefixoPessoa){
  this->limite = limite >= 0 ? limite : 200;
}

void ContaCorrenteLimite::validarRetirada(double valor) const {
  if(valor <= 0){
    throw ValorInvalido();
  }else if(valor > this->saldo + limite){
    throw ExcedeLimite();
  }
}


void ContaCorrenteLimite::imprimirExtrato() const {
  cout.setf(ios_base::fixed);
  cout.precision(2);
  cout << endl;
  cout << "=-=-=-=-=-=-=-=-=-=EXTRATO=-=-=-=-=-=-=-=-=" << endl;
  cout << "DADOS:" << endl;
  cout << "Tipo da Conta       - Corrente Com Limite" << endl;
  cout << "Nome do Correntista - " << pessoa->getNome() << endl;
  cout << "Numero da Conta     - " << numeroDaConta << endl;
  cout << "Limite da Conta     - R$ " << limite << endl;
  cout << "-------------------------------------------" << endl;
  cout << "TRANSAÇÕES:" << endl;
  cout << "Data        |  Descrição     | Valor (R$)" << endl;
  cout << "------------|----------------|-------------" << endl;
  if(!listaDeTransacoes.empty()){
    int c = 0;

    for(auto it = listaDeTransacoes.rbegin(); it != listaDeTransacoes.rend(); it++){
      if(c > 30) break;

      cout << it->getData() << "  |  " << setw(13) << it->getDescricao() << " |  ";
      
      cout << (((strcmp(it->getDescricao(), "DEPOSITO") == 0) || ((strcmp(it->getDescricao(), 
      "TRANSFERENCIA") == 0) && it->getValorDaTransacao() > 0 )) ? "+": "")  << it->getValorDaTransacao() << endl; 
      c++;
    }
  }else{
    cout << "     Nenhuma transação foi realizada!      " << endl;
  }
  cout << "-------------------------------------------" << endl;
  cout << "SALDO ATUAL:" << endl;
  cout << "R$ " << saldo << endl;
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cout << endl;
}

void ContaCorrenteLimite::mostrarConta() const {
  cout << endl;
  cout << "=-=-=-=-=-=-=-=Dados da Conta-=-=-=-=-=-=-=" << endl;
  cout << "DADOS:" << endl;
  cout << "Tipo da Conta         - Corrente Com Limite" << endl;
  cout << "Nome do Correntista   - " << pessoa->getNome() << endl;
  cout << "E-mail do Correntista - " << pessoa->getEmail() << endl;
  cout << "Numero da Conta       - " << numeroDaConta << endl;
  cout << "Limite da Conta       - R$ " << limite << endl;
  cout << "-------------------------------------------" << endl;
  cout << "SALDO ATUAL:" << endl;
  cout << "R$ " << saldo << endl;
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cout << endl;
}

void ContaCorrenteLimite::setLimite(double valor){
  if(valor <= 0){
    throw ValorInvalido();
  }
  this->limite = valor;
}
