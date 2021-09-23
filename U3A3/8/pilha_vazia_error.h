#ifndef __PILHA_VAZIA_ERROR_H__
#define __PILHA_VAZIA_ERROR_H__

#include <stdexcept>
using std::out_of_range;


class pilha_vazia_error: public out_of_range {
public:
  pilha_vazia_error(const char*e ="A pilha está vazia!"):out_of_range(e){}
};


#endif // __PILHA_VAZIA_ERROR_H__