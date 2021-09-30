#ifndef __VALOR_INVALIDO_H__
#define __VALOR_INVALIDO_H__


#include <stdexcept>
using std::invalid_argument;

class ValorInvalido : public invalid_argument {
public:
  ValorInvalido(const char* e="Impossível realizar essa operação com um valor nulo ou negativo!") : invalid_argument(e){}
};


#endif 