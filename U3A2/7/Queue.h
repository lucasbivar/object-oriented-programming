#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

template<class T>
class Queue {
  friend ostream &operator<<(ostream &out, const Queue<T> &q){
    out << "[";
    for(int i = 0, aux = q.begin; i < q.currentSize; i++, aux = (aux + 1)%q.maxSize){
      out << "  " << q.arr[aux];
    }
    out << " ]" << endl;
    return out;
  }

public:
  Queue(int = 10);  
  ~Queue();          

  bool front(T&);

  bool push_back(const T&);
  bool pop_front(T&);
  
  int size();
  bool isEmpty();
  bool isFull();


private:
  T* arr;
  int currentSize, maxSize, begin, end;
};

template <class T>
Queue<T>::Queue(int size){
  this->maxSize = size > 0 ? size : 10;

  this->currentSize = 0;
  begin = 0;
  end = 0;

  arr = new T[this->maxSize];
}


template <class T>
bool Queue<T>::front(T& data){
  if(this->isEmpty()) return false;

  data = this->arr[this->begin];

  return true;
}


template <class T>
bool Queue<T>::push_back(const T& data){
  if(this->isFull()) return false;

  this->arr[this->end] = data;
  this->end = (this->end + 1) % maxSize;
  this->currentSize++;

  return true;
}

template <class T>
bool Queue<T>::pop_front(T& data){
  if(this->isEmpty()) return false;

  data = this->arr[this->begin];
  this->begin = (this->begin + 1) % maxSize;
  this->currentSize--;
  
  return true;
}


template <class T>
int Queue<T>::size(){
  return currentSize;
}


template <class T>
bool Queue<T>::isEmpty(){
  return currentSize == 0;
}

template <class T>
bool Queue<T>::isFull(){
  return currentSize == maxSize;
}


template <class T>
Queue<T>::~Queue(){
  delete [] arr;
}

#endif 