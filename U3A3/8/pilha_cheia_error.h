#ifndef __PILHA_CHEIA_ERROR_H__
#define __PILHA_CHEIA_ERROR_H__

#include <stdexcept>
using std::out_of_range;


class pilha_cheia_error: public out_of_range{
public:
  pilha_cheia_error(const char*e ="A pilha está cheia!"):out_of_range(e){}
};

#endif // __PILHA_CHEIA_ERROR_H__