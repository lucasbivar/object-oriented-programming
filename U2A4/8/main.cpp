#include "Pessoa.h"
#include "PessoaFisica.h"
#include "PessoaJuridica.h"

#include <iostream>
using std::cout;
using std::endl;

int main(){
  Pessoa p("Valentina");
  PessoaFisica pFisica("Kleber", 17272636423);
  PessoaJuridica pJuridica("Coca Cola", 23003034123400 ,"Coca Cola Industrias Ltda" );

  cout << p << endl;

  cout << pFisica;
  cout << "CPF: " << pFisica.getCpf() << endl << endl;

  cout << pJuridica << endl;
  cout << "CNPJ: " << pJuridica.getCnpj() << endl;
  cout << "Razao Social: " << pJuridica.getSocialReason() << endl << endl;

  return 0;
}

// g++ -Wall -std=c++17  U2A4/8/*.cpp -o main && ./main