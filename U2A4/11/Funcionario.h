#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "PessoaFisica.h"

#include <iostream>
using std::ostream;

class Funcionario : public PessoaFisica {
  friend ostream& operator<<(ostream&, const Funcionario&);
public:
  Funcionario(string="", unsigned long long = 0, unsigned int = 0, 
  unsigned int = 220, unsigned int = 1100, double = 0);

  double calculateGrossSalary() const;

  void setEnrollment(unsigned int enrollment);
  unsigned int getEnrollment() const;

  void setMonthlyWorkload(unsigned int monthlyWorkload);
  unsigned int getMonthlyWorkload() const;

  void setHoursWorkedInMonth(unsigned int hoursWorkedInMonth);
  unsigned int getHoursWorkedInMonth() const;

  void setBaseSalary(double baseSalary);
  double getBaseSalary() const;

private:
  unsigned int enrollment, monthlyWorkload, hoursWorkedInMonth;
  double baseSalary;
};

#endif