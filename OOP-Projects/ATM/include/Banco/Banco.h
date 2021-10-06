#ifndef __BANCO_H__
#define __BANCO_H__

#include "../Pessoa/PessoaJuridica.h"
#include "../Pessoa/Pessoa.h"
#include "../Conta/Conta.h"


#include <list>
using std::list;

#include <string>
using std::string;

class Banco: public PessoaJuridica {
public:
  Banco(string ="", string ="", string ="", 
    string ="", string ="");
  ~Banco();
    
  void listarContasCorrentista(string ="") const;
  void listarContas() const;
  
  void editarConta(string ="");
  void cadastrarConta();
  void removerConta(string ="");
  void consultarConta(string ="") const;

  Conta* existeConta(string ="") const;
private:
  list<Pessoa*> correntistas;
  list<Conta*> contas;
  Pessoa* getPonteiroPessoa(string="");
};



#endif 