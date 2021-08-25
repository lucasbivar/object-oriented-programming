#include "Funcionario.h"

#include <iostream>
using std::cout;
using std::endl;

ostream& operator<<(ostream& out, const Funcionario& employee){
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cout << "Nome: " << employee.getName() << endl;
  cout << "CPF: " << employee.getCpf() << endl;
  cout << "Matrícula: " << employee.getEnrollment() << endl;
  cout << "Salario Base: " << employee.getBaseSalary() << endl;
  cout << "Salario Bruto: " << employee.calculateGrossSalary() << endl;
  cout << "Carga horaria mensal: " << employee.getMonthlyWorkload() << endl;
  cout << "Quantidade de horas trabalhadas no mes: " << employee.getHoursWorkedInMonth() << endl;
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  return out;
}

Funcionario::Funcionario(string name, unsigned long long cpf, unsigned int enrollment, 
unsigned int monthlyWorkload, unsigned int hoursWorkedInMonth, double baseSalary)
 : PessoaFisica(name, cpf){
   this->enrollment = enrollment; 
   this->monthlyWorkload = monthlyWorkload;
   this->hoursWorkedInMonth = hoursWorkedInMonth;
   this->baseSalary = baseSalary;
}

double Funcionario::calculateGrossSalary() const {
  double grossSalary = getBaseSalary() * 
    static_cast<double>(hoursWorkedInMonth)/monthlyWorkload;

  return grossSalary;
}

void Funcionario::setEnrollment(unsigned int enrollment){
  this->enrollment = enrollment < 0 ? 0 : enrollment;
}

unsigned int Funcionario::getEnrollment() const {
  return enrollment;
}

void Funcionario::setMonthlyWorkload(unsigned int monthlyWorkload){
  this->monthlyWorkload = monthlyWorkload < 0 ? 220 : monthlyWorkload;
}

unsigned int Funcionario::getMonthlyWorkload() const {
  return monthlyWorkload;
}

void Funcionario::setHoursWorkedInMonth(unsigned int hoursWorkedInMonth){
  this->hoursWorkedInMonth = (hoursWorkedInMonth > 0 && 
  hoursWorkedInMonth <= getMonthlyWorkload()) ? hoursWorkedInMonth : 0;
}

unsigned int Funcionario::getHoursWorkedInMonth() const {
  return hoursWorkedInMonth;
}

void Funcionario::setBaseSalary(double baseSalary) {
  this->baseSalary = baseSalary < 0 ? 1100 : baseSalary;
}

double Funcionario::getBaseSalary() const {
  return baseSalary;
}