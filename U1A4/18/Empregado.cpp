#include "Empregado.h"

Empregado::Empregado(string nome, string sobrenome, double salario){
  setNome(nome);
  setSobrenome(sobrenome);
  setSalarioMensal(salario);
}

void Empregado::setNome(string novoNome){
  nome = novoNome;
}

string Empregado::getNome(){
  return nome;
}

void Empregado::setSobrenome(string novoSobrenome){
  sobrenome = novoSobrenome;
}

string Empregado::getSobrenome(){
  return sobrenome;
}

void Empregado::setSalarioMensal(double novoSalario){
  salarioMensal = novoSalario < 0 ? 0 : novoSalario;
}

double Empregado::getSalarioMensal(){
  return salarioMensal;
}