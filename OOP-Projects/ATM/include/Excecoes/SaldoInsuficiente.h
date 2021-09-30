#ifndef __SALDO_INSUFICIENTE_H__
#define __SALDO_INSUFICIENTE_H__


#include <stdexcept>
using std::runtime_error;

class SaldoInsuficiente : public runtime_error {
public:
  SaldoInsuficiente(const char* e="Saldo insuficiente para realizar a retirada!") : runtime_error(e){}
};


#endif 