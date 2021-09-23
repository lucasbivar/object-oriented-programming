#ifndef __EXCECAO_UM_H__
#define __EXCECAO_UM_H__

#include <stdexcept>
using std::runtime_error;

class ExcecaoUm : public runtime_error {
public:
  ExcecaoUm(const char* e="Lançando Exceção Um!") : runtime_error(e){}
};

#endif 