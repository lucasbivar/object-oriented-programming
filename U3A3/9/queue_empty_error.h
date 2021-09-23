#ifndef __QUEUE_EMPTY_ERROR_H__
#define __QUEUE_EMPTY_ERROR_H__


#include <stdexcept>
using std::out_of_range;


class queue_empty_error: public out_of_range {
public:
  queue_empty_error(const char*e ="A fila está vazia!"):out_of_range(e){}
};


#endif // __QUEUE_EMPTY_ERROR_H__