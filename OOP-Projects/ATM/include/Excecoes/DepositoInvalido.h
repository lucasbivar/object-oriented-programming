#ifndef __DEPOSITO_INVALIDO_H__
#define __DEPOSITO_INVALIDO_H__

#include <stdexcept>
using std::invalid_argument;

class DepositoInvalido : public invalid_argument {
public:
  DepositoInvalido(const char* e="Impossível depositar um valor nulo ou negativo!") : invalid_argument(e){}
};


#endif 