#include "Cupom.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

int main(){
  cout << "=-=-=-=-=-=-=-=CUPOM=-=-=-=-=-=-=-=" << endl;
  Cupom cupom1("12", "Coxinha", -2, -3);

  cout << "ID: " << cupom1.getId() << endl;
  cout << "Descricao: " << cupom1.getDescricao() << endl;
  cout << "Preco: " << cupom1.getPreco() << endl;
  cout << "Quantidade: " << cupom1.getQuantidade() << endl;

  cout << endl;
  cout << "Setando preço da " << cupom1.getDescricao() << " para R$3.50..." << endl << endl;
  cupom1.setPreco(3.50);

  cout << "ID: " << cupom1.getId() << endl;
  cout << "Descricao: " << cupom1.getDescricao() << endl;
  cout << "Preco: " << cupom1.getPreco() << endl;
  cout << "Quantidade: " << cupom1.getQuantidade() << endl << endl;

  cout << "Setando a quantidade de " << cupom1.getDescricao() << " para 5..." << endl << endl;
  cupom1.setQuantidade(5);

  cout << "ID: " << cupom1.getId() << endl;
  cout << "Descricao: " << cupom1.getDescricao() << endl;
  cout << "Preco: " << cupom1.getPreco() << endl;
  cout << "Quantidade: " << cupom1.getQuantidade() << endl << endl;

  cout << "Valor total do Cupom: R$" << cupom1.calculaCupom() << endl;

  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  
  return 0;
}

// g++ -Wall -std=c++17 U1A4/20/*.cpp -o main && ./main