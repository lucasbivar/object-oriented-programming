#ifndef __EXCECAO_DOIS_H__
#define __EXCECAO_DOIS_H__

#include <stdexcept>
using std::runtime_error;

class ExcecaoDois : public runtime_error {
public:
  ExcecaoDois(const char* e="Lançando Exceção Dois!") : runtime_error(e){}
};

#endif 