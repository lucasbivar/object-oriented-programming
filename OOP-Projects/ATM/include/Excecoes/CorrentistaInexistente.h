#ifndef __CORRENTISTA_INEXISTENTE_H__
#define __CORRENTISTA_INEXISTENTE_H__


#include <stdexcept>
using std::runtime_error;

class CorrentistaInexistente : public runtime_error {
public:
  CorrentistaInexistente(const char* e="A conta informada não existe.\n") : runtime_error(e){}
};

#endif