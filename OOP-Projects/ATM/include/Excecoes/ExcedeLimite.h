#ifndef __EXCEDE_LIMITE_H__
#define __EXCEDE_LIMITE_H__


#include <stdexcept>
using std::runtime_error;

class ExcedeLimite : public runtime_error {
public:
  ExcedeLimite(const char* e="Você já excedeu o seu limite!") : runtime_error(e){}
};

#endif