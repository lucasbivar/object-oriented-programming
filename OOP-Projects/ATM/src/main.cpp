#include <iostream>
using std::cout;
using std::endl;

#include "../include/Pessoa/Pessoa.h"
#include "../include/Pessoa/PessoaFisica.h"
#include "../include/Pessoa/PessoaJuridica.h"

int main(){
  Pessoa* arr[2] = {new PessoaFisica("Lucas Bivar", "lucas@gmail.com", "12312", "234233", "dasda ds"),
  new PessoaJuridica("lUCAS", "123123", "1234", "12312", "FSDFS")};
  
  arr[0]->exibirPessoa();
  arr[1]->exibirPessoa();
  return 0;
}