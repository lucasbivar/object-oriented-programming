#ifndef CONTABANCO_H
#define CONTABANCO_H

class ContaBanco{
public:
  ContaBanco(double saldoInicial);

  void creditar(double valor);

  void debitar(double valor);

  double getSaldo();

private:
  double saldo;
};

#endif