#include <iostream>
using std::cout;
using std::endl;

#include "Queue.h"

#include <string>
using std::string;

int main(){
  Queue<int, 5> q1;
  int aux;
  
  cout << "ta vazia? " << (q1.isEmpty() ? "true" : "false") << endl;
  cout << "ta cheia? " << (q1.isFull() ? "true" : "false") << endl;


  cout << q1;
  cout << endl;

  for(int i = 11; i < 17; i++){
    cout << "tamanho da fila: " << q1.size() << endl;
    cout << "Adicionando " << i << endl;
    if(!q1.push_back(i)) cout << "Erro ao adicionar o " << i << ". Fila lotada!" << endl;
  }

  cout << endl;

  cout << q1;

  cout << endl;

  cout << "ta vazia? " << (q1.isEmpty() ? "true" : "false") << endl;
  cout << "ta cheia? " << (q1.isFull() ? "true" : "false") << endl;
  
  cout << endl;


  if(q1.front(aux)) cout << "Frente da Fila: " << aux << endl;

  cout << endl;

  for(int i = 0; i < 6; i++){
    if(q1.pop_front(aux)){
      cout << "Removendo " << aux << endl;
      cout << "tamanho da fila: " << q1.size() << endl;
      
    }else{
      cout << "Erro ao tentar remover. Fila vazia!" << endl;
    }

  }

  cout << endl;

  Queue<string> q2;
  string aux_str;

  q2.push_back("Lucas");
  q2.push_back("Victor");
  cout << q2;

  q2.pop_front(aux_str);
  cout << q2;
  
  q2.pop_front(aux_str);
  cout << q2;
  



  return 0;
}