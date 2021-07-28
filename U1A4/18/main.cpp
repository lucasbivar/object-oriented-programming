#include "Empregado.h"

#include <iostream>
using std::cout;
using std::endl;

int main(){
  cout << "=-=-=-=-=-=-=-=EMPREGADO 1=-=-=-=-=-=-=-=" << endl;
  Empregado empregado1("Mark", "Zuckerberg", 1200);

  cout << "Nome: " << empregado1.getNome() << endl;
  cout << "Sobrenome: " << empregado1.getSobrenome() << endl;
  cout << "Salario Mensal: " << empregado1.getSalarioMensal() << endl << endl;

  cout << "Dando um aumento de 10% para o empregado 1..." << endl << endl;
  empregado1.setSalarioMensal(empregado1.getSalarioMensal()*1.10);

  cout << "Novo Salario Mensal: " << empregado1.getSalarioMensal() << endl;
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cout << endl << endl;

  cout << "=-=-=-=-=-=-=-=EMPREGADO 2=-=-=-=-=-=-=-=" << endl;
  Empregado empregado2("Jeff", "Bezos", -200);

  cout << "Nome: " << empregado2.getNome() << endl;
  cout << "Sobrenome: " << empregado2.getSobrenome() << endl;
  cout << "Salario Mensal: " << empregado2.getSalarioMensal() << endl << endl;

  cout << "Setando o valor do salario mensal do empregado 2 para 1500..." << endl << endl;
  empregado2.setSalarioMensal(1500);

  cout << "Novo Salario Mensal: " << empregado2.getSalarioMensal() << endl << endl;


  cout << "Dando um aumento de 10% para o empregado 2..." << endl << endl;
  empregado2.setSalarioMensal(empregado2.getSalarioMensal()*1.10);

  cout << "Novo Salario Mensal: " << empregado2.getSalarioMensal() << endl;
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cout << endl << endl;

  return 0;
}

// g++ -Wall -std=c++17 U1A4/18/*.cpp -o main && ./main
