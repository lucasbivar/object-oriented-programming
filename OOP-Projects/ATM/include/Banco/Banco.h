#ifndef __BANCO_H__
#define __BANCO_H__

#include "../Pessoa/PessoaJuridica.h"
#include "../Pessoa/Pessoa.h"
#include "../Conta/Conta.h"


#include <list>
using std::list;

class Banco: public PessoaJuridica {
public:
  Banco(const char* ="", const char* ="", const char* ="", 
    const char* ="", const char* ="");
  ~Banco();
    
  void listarContasCorrentista(const char* ="") const;
  void listarContas() const;
  
  void editarConta(const char* ="");
  void cadastrarConta();
  void removerConta(const char* ="");
  void consultarConta(const char* ="") const;

  Conta* existeConta(const char* ="") const;
private:
  list<Pessoa*> correntistas;
  list<Conta*> contas;
};

#endif 