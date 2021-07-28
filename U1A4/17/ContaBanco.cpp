#include "ContaBanco.h"

#include <iostream>
using std::cerr;
using std::endl;

ContaBanco::ContaBanco(double saldoInicial){
  if(saldoInicial < 0){
    saldoInicial = 0;
  }
  saldo = saldoInicial;
}


void ContaBanco::creditar(double valor){
  saldo += valor;
}

void ContaBanco::debitar(double valor){
  if(valor > saldo){
    cerr << "Nao eh possivel debitar uma valor maior que o saldo. Tente novamente!" 
    << endl << endl;
  }else{
    saldo -= valor;
  }
}

double ContaBanco::getSaldo(){
  return saldo;
}
