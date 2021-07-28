#include "ContaBanco.h"

#include <iostream>
using std::cout;
using std::endl;


int main(){
  cout << "=-=-=-=-=-=-=-=CONTA 1=-=-=-=-=-=-=-=" << endl;
  ContaBanco conta1(256.2);

  cout << "Saldo da conta 1: " << conta1.getSaldo() << endl << endl;

  cout << "Tentando debitar um valor maior que o saldo..." << endl;
  conta1.debitar(300);

  cout << "Debitando 50 reais da conta 1..." << endl;
  conta1.debitar(50);

  cout << "Saldo da conta 1: " << conta1.getSaldo() << endl << endl;

  cout << "Creditando 50 reais na conta 1..." << endl;
  conta1.creditar(50);

  cout << "Saldo da conta 1: " << conta1.getSaldo() << endl;

  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

  cout << endl << endl;

  cout << "=-=-=-=-=-=-=-=CONTA 2=-=-=-=-=-=-=-=" << endl;
  ContaBanco conta2(-302.50);
  cout << "Saldo da conta 2: " << conta2.getSaldo() << endl << endl;

  cout << "Tentando debitar um valor maior que o saldo..." << endl;
  conta2.debitar(500);

  cout << "Creditando 120 reais na conta 2..." << endl;
  conta2.creditar(120);

  cout << "Saldo da conta 2: " << conta2.getSaldo() << endl << endl;

  cout << "Debitando 100 reais da conta 2..." << endl;
  conta2.debitar(100);

  cout << "Saldo da conta 1: " << conta2.getSaldo() << endl;
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

  return 0;
}

// g++ -Wall -std=c++17 U1A4/17/*.cpp -o main && ./main