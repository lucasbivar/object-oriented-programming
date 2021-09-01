#include "Conta.h"
#include "ContaCorrente.h"
#include "ContaCorrenteLimite.h"
#include "ContaPoupanca.h"

#include <iostream>
using std::cout;
using std::endl;

int main(){
  Conta *contas [] = {new ContaCorrente("Lucas Bivar", "0023012"), 
  new ContaCorrenteLimite("João Medeiros", "1123015", 300), 
  new ContaPoupanca("Leticia Campos", "2253021", 31)};


  contas[0]->imprimirExtrato();
  cout << (contas[0]->deposito(4000) ? "Sucesso" : "Erro") << endl;
  cout << (contas[0]->retirada(800) ? "Sucesso" : "Erro") << endl;
  contas[0]->imprimirExtrato();

  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

  cout << (contas[1]->deposito(400) ? "Sucesso" : "Erro") << endl;
  cout << (contas[1]->retirada(500) ? "Sucesso" : "Erro") << endl;
  if(!contas[1]->retirada(300)){
    cout << "Não foi possivel realizar essa operação, saldo insuficiente..." << endl;
  }

  contas[1]->imprimirExtrato();

  cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

  cout << (contas[2]->deposito(5000) ? "Sucesso" : "Erro") << endl;
  cout << (contas[2]->retirada(4000) ? "Sucesso" : "Erro") << endl;
  if(!contas[2]->retirada(2000)){
    cout << "Não foi possivel realizar essa operação, saldo insuficiente..." << endl;
  }
  contas[2]->imprimirExtrato();



  for(int i = 0; i < 3; i++){
    delete contas[i];
  }

  return 0;
}