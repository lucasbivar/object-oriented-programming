#ifndef __QUEUE_FULL_ERROR_H__
#define __QUEUE_FULL_ERROR_H__

#include <stdexcept>
using std::out_of_range;


class queue_full_error: public out_of_range {
public:
  queue_full_error(const char*e ="A fila está cheia!"):out_of_range(e){}
};


#endif // __QUEUE_FULL_ERROR_H__