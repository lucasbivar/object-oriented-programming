#ifndef EMPREGADO_H
#define EMPREGADO_H

#include <string>
using std::string;

class Empregado{
public:
  Empregado(string nome, string sobrenome, double salario);

  void setNome(string novoNome);
  string getNome();
  
  void setSobrenome(string novoSobrenome);
  string getSobrenome();

  void setSalarioMensal(double novoSalario);
  double getSalarioMensal();

private:
  string nome, sobrenome;
  double salarioMensal;
};

#endif