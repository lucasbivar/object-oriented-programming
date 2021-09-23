#ifndef PILHA_H
#define PILHA_H 

#include "pilha_cheia_error.h"
#include "pilha_vazia_error.h"

template < class T >
class Pilha 
{
public:
  Pilha( int = 10 );
  ~Pilha();
  
  void push(const T &);
  void pop(T &);

  bool isEmpty() const { return pos == 0; }
  bool isFull() const { return pos == tam;}
private:
  T *pPtr;
  int pos, tam;
};

template < class T >
Pilha<T>::Pilha( int tam ){
  this->tam = ( (tam > 0) ? tam : 10 );
  pos = 0;

  pPtr = new T[this->tam];
}

template < class T >
Pilha<T>::~Pilha(){
  delete [] pPtr;
}

template < class T >
void Pilha<T>::push(const T &el){
  if (isFull()){
    throw pilha_cheia_error();
  }
  pPtr[pos++] = el;
}

template < class T>
void Pilha<T>::pop(T &el){
  if (isEmpty()) {
    throw pilha_vazia_error();
  }
  el = pPtr[--pos];
}

#endif