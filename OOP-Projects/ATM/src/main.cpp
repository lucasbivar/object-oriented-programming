#include <iostream>
using std::cout;
using std::endl;

#include "../include/Pessoa/Pessoa.h"
#include "../include/Pessoa/PessoaFisica.h"
#include "../include/Pessoa/PessoaJuridica.h"

#include "../include/Conta/ContaCorrente.h"
#include "../include/Conta/ContaCorrenteLimite.h"
#include "../include/Conta/ContaPoupanca.h"
#include "../include/Conta/Conta.h"

int main(){
  Pessoa* arr[2] = {new PessoaFisica("Lucas Bivar", "lucas@gmail.com", "12312", "234233", "dasda ds"),
                    new PessoaJuridica("lUCAS", "123123", "1234", "12312", "FSDFS")};

  Conta* contas[3] = {new ContaCorrente(arr[0]),
                      new ContaCorrenteLimite(arr[0], 400),
                      new ContaPoupanca(arr[1], 20)};

  *contas[0] << 120;                     
  *contas[1] << 200;                     
  *contas[2] << 400;                     
  contas[0]->imprimirExtrato();
  contas[1]->imprimirExtrato();
  contas[2]->imprimirExtrato();

  contas[1]->transferir(200, contas[2]);
  *contas[1] >> 400;

  contas[0]->imprimirExtrato();
  contas[1]->imprimirExtrato();
  contas[2]->imprimirExtrato();
  return 0;
}