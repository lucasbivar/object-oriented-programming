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
    
  void listarContasCorrentista(const char* ="") const;
  void listarContas() const;
private:
  list<Pessoa*> correntistas;
  list<Conta*> contas;
};

#endif 