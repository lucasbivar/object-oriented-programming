#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include "queue_empty_error.h"
#include "queue_full_error.h"

template<class T = int, int SIZE = 10>
class Queue {
  friend ostream &operator<<(ostream &out, const Queue<T, SIZE> &q){
    out << "[";
    for(int i = 0, aux = q.begin; i < q.currentSize; i++, aux = (aux + 1)%SIZE){
      out << "  " << q.arr[aux];
    }
    out << " ]" << endl;
    return out;
  }

public:
  Queue();  
  ~Queue();          

  void front(T&);

  void push_back(const T&);
  void pop_front(T&);
  
  int size();
  bool isEmpty();
  bool isFull();


private:
  T* arr;
  int currentSize, begin, end;
};

template<class T, int SIZE>
Queue<T, SIZE>::Queue(){
  begin = 0;
  end = 0;
  this->currentSize = 0;
  
  arr = new T[SIZE];
}


template<class T, int SIZE>
void Queue<T, SIZE>::front(T& data){
  if(this->isEmpty()){
    throw queue_empty_error();
  }

  data = this->arr[this->begin];
}


template<class T, int SIZE>
void Queue<T, SIZE>::push_back(const T& data){
  if(this->isFull()){
    throw queue_full_error();
  }

  this->arr[this->end] = data;
  this->end = (this->end + 1) % SIZE;
  this->currentSize++;
}


template<class T, int SIZE>
void Queue<T, SIZE>::pop_front(T& data){
  if(this->isEmpty()){
    throw queue_empty_error();
  }

  data = this->arr[this->begin];
  this->begin = (this->begin + 1) % SIZE;
  this->currentSize--;
}


template<class T, int SIZE>
int Queue<T, SIZE>::size(){
  return currentSize;
}


template<class T, int SIZE>
bool Queue<T, SIZE>::isEmpty(){
  return currentSize == 0;
}

template<class T, int SIZE>
bool Queue<T, SIZE>::isFull(){
  return currentSize == SIZE;
}


template<class T, int SIZE>
Queue<T, SIZE>::~Queue(){
  delete [] arr;
}

#endif 