#ifndef __CONTA_INEXISTENTE_H__
#define __CONTA_INEXISTENTE_H__


#include <stdexcept>
using std::runtime_error;

class ContaInexistente : public runtime_error {
public:
  ContaInexistente(const char* e="A conta informada não existe.\n") : runtime_error(e){}
};

#endif