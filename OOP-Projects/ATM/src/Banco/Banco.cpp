#include "../../include/Banco/Banco.h"

#include "../../include/Excecoes/ContaInexistente.h"
#include "../../include/Excecoes/CorrentistaInexistente.h"

#include "../../include/Pessoa/Pessoa.h"
#include "../../include/Pessoa/PessoaJuridica.h"
#include "../../include/Pessoa/PessoaFisica.h"

#include "../../include/Conta/ContaCorrente.h"
#include "../../include/Conta/ContaCorrenteLimite.h"
#include "../../include/Conta/ContaPoupanca.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include <string.h>

Banco::Banco(const char* nome, const char* email, 
  const char* cnpj, const char* inscricaoEstadual, const char* razaoSocial):PessoaJuridica(nome, email, cnpj, inscricaoEstadual, razaoSocial){

}

Banco::~Banco(){
  for(Conta* c: contas){
    delete c;
  }
  for(Pessoa* p: correntistas){
    delete p;
  }
}


void Banco::removerConta(const char* numeroDaConta){
  bool encontrou = false;
  for(list<Conta*>::iterator it = contas.begin(); it != contas.end(); it++){
    if(strcmp((*it)->getNumeroDaConta() , numeroDaConta) == 0){
      contas.erase(it);
      encontrou = true;
      break;
    }
  }
  
  if(!encontrou){
    throw ContaInexistente();
  }
}

void Banco::consultarConta(const char* numeroDaConta) const{
  bool encontrou = false;

  for(auto c: contas){
    if(strcmp(c->getNumeroDaConta(), numeroDaConta) == 0){
      c->imprimirExtrato();
      encontrou = true;
      break;
    }
  }

  if(!encontrou) {
    throw ContaInexistente();
  }
}


void Banco::cadastrarConta() {
  PessoaFisica* novaPessoaFisica = nullptr;
  PessoaJuridica* novaPessoaJuridica = nullptr;
  Pessoa* pAux = nullptr;
  int opPessoa, opConta, opAux, opTemConta;
  string strAux1, strAux2;
  double limite;
  bool operacaoCancelada = false;

  cout << "Já possui alguma conta no banco?" << endl;
  cout << "1 - Sim" << endl;
  cout << "2 - Não" << endl;
  cout << "Op.: ";
  while(true){
    cin >> opTemConta;
    if(opTemConta >= 1 && opTemConta <= 2) break;
    cout << "Opção Inválida. Tente novamente!" << endl;
    cout << "Op.: ";
  }

  cout << "Tipo de Pessoa:" << endl;
  cout << "1 - Pessoa Física" << endl;
  cout << "2 - Pessoa Jurídica" << endl;
  cout << "Op.: ";
  while(true){
    cin >> opPessoa;
    if(opPessoa >= 1 && opPessoa <=2) break;
    cout << "Opção Inválida. Tente novamente!" << endl;
    cout << "Op.: ";
  }

  if(opTemConta == 2){
    cin.ignore();
    cout << "Nome: " << endl;
    getline(cin, strAux1);

    cout << "E-mail: " << endl;
    cin >> strAux2;

    if(opPessoa == 1){
      novaPessoaFisica = new PessoaFisica(strAux1.c_str(), strAux2.c_str());
    }else{
      novaPessoaJuridica = new PessoaJuridica(strAux1.c_str(), strAux2.c_str());
    }

    if(opPessoa == 1){
      cout << "CPF (sem pontuação): ";
      cin >> strAux1;
      novaPessoaFisica->setCPF(strAux1.c_str());

      cout << "Data de Nascimento (sem pontuação - ddmmyyyy): ";
      cin >> strAux1;
      novaPessoaFisica->setDataDeNascimento(strAux1.c_str());
    
      string estadoCivil[5] = {"Solteiro", "Casado", "Separado", "Divorciado", "Viúvo"};
      cout << "Estado Civil: " << endl;;
      for(int i = 1; i <= 5; i++){
        cout << i << " - " << estadoCivil[i-1] << endl;
      }
      cout << "Op.: ";
      while(true){
        cin >> opAux;
        if(opAux >= 1 && opAux <= 5) break;
        cout << "Opção Inválida. Tente novamente!" << endl;
        cout << "Op.: ";
      }
      novaPessoaFisica->setEstadoCivil(estadoCivil[opAux-1].c_str());

      correntistas.push_back(novaPessoaFisica);
    }else{
      cout << "CNPJ (sem pontuação): ";
      cin.ignore();
      getline(cin, strAux1);
      novaPessoaJuridica->setCNPJ(strAux1.c_str());

      cout << "Inscrição Estadual: ";
      getline(cin, strAux1);
      novaPessoaJuridica->setInscricaoEstadual(strAux1.c_str());

      cout << "Razão Social: ";
      getline(cin, strAux1);
      novaPessoaJuridica->setRazaoSocial(strAux1.c_str());

      correntistas.push_back(novaPessoaJuridica);
    }
  }else{
    bool achou = false;
    while(true){
      cin.ignore();
      cout << "Nome (-1 para cancelar): ";
      getline(cin, strAux1);

      if(strcmp(strAux1.c_str(), "-1") == 0){
        operacaoCancelada = true;
        break;
      }

      for(Pessoa* p: correntistas){
        if(strcmp(p->getNome(), strAux1.c_str()) == 0){
          achou = true;
          pAux = p;
          break;
        }
      }
      if(achou) break;
      cout << "Nome não encontrado na base. Tente novamente!" << endl;
      cout << "Nome: ";
    }

  }

  if(operacaoCancelada) return;

  cout << "Tipo da conta:" << endl;
  cout << "1 - Conta Corrente" << endl;
  cout << "2 - Conta Corrente Com Limite" << endl;
  cout << "3 - Conta Poupança" << endl;
  cout << "Op.: ";
  while(true){
    cin >> opConta;
    if(opConta >= 1 && opConta <= 3) break;
    cout << "Opção Inválida. Tente novamente!" << endl;
    cout << "Op.: ";
  }
  if(opConta == 1){
    if(opTemConta == 1){
      novaPessoaFisica = dynamic_cast<PessoaFisica*>(pAux);
      ContaCorrente *novaConta;
      if(novaPessoaFisica){
        novaConta = new ContaCorrente(pAux,"1","1");
      }else{
        novaConta = new ContaCorrente(pAux,"1","2");
      }
      contas.push_back(novaConta);
      cout << "DADOS DA CONTA CRIADA:" << endl;
      novaConta->mostrarConta();      
    }else{
      if(opPessoa == 1){
        ContaCorrente *novaConta = new ContaCorrente(novaPessoaFisica, "1", "1");
        contas.push_back(novaConta);
        cout << "DADOS DA CONTA CRIADA:" << endl;
        novaConta->mostrarConta();        
      }else{
        ContaCorrente *novaConta = new ContaCorrente(novaPessoaJuridica, "1", "2");
        contas.push_back(novaConta);
        cout << "DADOS DA CONTA CRIADA:" << endl;
        novaConta->mostrarConta();        
      }
    }
  }else if(opConta == 2){
    cout << "Valor do Limite: " << endl;
    cin >> limite;
    if(opTemConta == 1){
      novaPessoaFisica = dynamic_cast<PessoaFisica*>(pAux);
      ContaCorrenteLimite *novaConta;
      if(novaPessoaFisica){
        novaConta = new ContaCorrenteLimite(pAux, "2", "1", limite);
      }else{
        novaConta = new ContaCorrenteLimite(pAux, "2", "2", limite);
      }
      contas.push_back(novaConta);
      cout << "DADOS DA CONTA CRIADA:" << endl;
      novaConta->mostrarConta();      
    }else{
      if(opPessoa == 1){
        ContaCorrenteLimite *novaConta = new ContaCorrenteLimite(novaPessoaFisica, "2", "1", limite);
        contas.push_back(novaConta);
        cout << "DADOS DA CONTA CRIADA:" << endl;
        novaConta->mostrarConta();        
      }else{
        ContaCorrenteLimite *novaConta = new ContaCorrenteLimite(novaPessoaJuridica, "2", "2", limite);
        contas.push_back(novaConta);
        cout << "DADOS DA CONTA CRIADA:" << endl;
        novaConta->mostrarConta();        
      }
    }
  }else{
    cout << "Dia de Aniversário da Conta: " << endl;
    int aniversarioConta;
    cin >> aniversarioConta;
    if(opTemConta == 1){
      novaPessoaFisica = dynamic_cast<PessoaFisica*>(pAux);
      ContaPoupanca *novaConta;
      if(novaPessoaFisica){
        novaConta = new ContaPoupanca(pAux, "3", "1", aniversarioConta);
      }else{
        novaConta = new ContaPoupanca(pAux, "3", "2", aniversarioConta);
      }
      contas.push_back(novaConta);
      cout << "DADOS DA CONTA CRIADA:" << endl;
      novaConta->mostrarConta();      
    }else{
      if(opPessoa == 1){
        ContaPoupanca *novaConta = new ContaPoupanca(novaPessoaFisica, "3", "1", aniversarioConta);
        contas.push_back(novaConta);
        cout << "DADOS DA CONTA CRIADA:" << endl;
        novaConta->mostrarConta();
      }else{
        ContaPoupanca *novaConta = new ContaPoupanca(novaPessoaJuridica,"3", "2", aniversarioConta);
        contas.push_back(novaConta);
        cout << "DADOS DA CONTA CRIADA:" << endl;
        novaConta->mostrarConta();
      } 
    }
  }

}

void Banco::editarConta(const char* numeroDaConta) {
  bool encontrou = false;
  Conta* cAtual = nullptr;
  string strAux;
  char op;
  double valor;
  int novaData, opAux;

  for(Conta* c: contas){
    if(strcmp(c->getNumeroDaConta(), numeroDaConta) == 0){
      encontrou = true;
      cAtual = c;
      break;
    }
  }

  if(!encontrou) {
    throw ContaInexistente();
  }

  cout << "Deseja alterar o nome? [S/N]" << endl;
  cin >> op;
  if(op == 'S' || op == 's'){
    cout << "Novo nome: ";
    cin.ignore();
    getline(cin, strAux);
    cAtual->pessoa->setNome(strAux.c_str());
  }


  cout << "Deseja alterar o e-mail? [S/N]" << endl;
  cin >> op;
  if(op == 'S' || op == 's'){
    cout << "Novo e-mail: ";
    cin.ignore();
    getline(cin, strAux);
    cAtual->pessoa->setEmail(strAux.c_str());
  }


  if(numeroDaConta[1] == '1'){
    PessoaFisica* pessoaFisicaAtual = dynamic_cast<PessoaFisica*>(cAtual->pessoa);
    cout << "Deseja alterar o CPF? [S/N]" << endl;
    cin >> op;
    if(op == 'S' || op == 's'){
      cout << "Novo CPF: ";
      cin >> strAux;
      pessoaFisicaAtual->setCPF(strAux.c_str());
    }

    cout << "Deseja alterar a data de nascimento? [S/N]" << endl;
    cin >> op;
    if(op == 'S'){
      cout << "Nova data de nascimento (sem pontuação - ddmmyyyy): ";
      cin >> strAux;
      pessoaFisicaAtual->setDataDeNascimento(strAux.c_str());
    }

    cout << "Deseja alterar o estado civil? [S/N]" << endl;
    cin >> op;
    if(op == 'S' || op == 's'){
      string estadoCivil[5] = {"Solteiro", "Casado", "Separado", "Divorciado", "Viúvo"};
      cout << "Estado Civil: " << endl;;
      for(int i = 1; i <= 5; i++){
        cout << i << " - " << estadoCivil[i-1] << endl;
      }
      cout << "Op.: ";
      while(true){
        cin >> opAux;
        if(opAux >= 1 && opAux <= 5) break;
        cout << "Opção Inválida. Tente novamente!" << endl;
        cout << "Op.: ";
      }
      pessoaFisicaAtual->setEstadoCivil(estadoCivil[opAux-1].c_str());
    }

  }else if(numeroDaConta[1] == '2'){
    PessoaJuridica* pessoaJuridicaAtual = dynamic_cast<PessoaJuridica*>(cAtual->pessoa);

    cout << "Deseja alterar o CNPJ? [S/N]" << endl;
    cin >> op;
    if(op == 'S' || op == 's'){
      cout << "Novo CNPJ: ";
      cin >> strAux;
      pessoaJuridicaAtual->setCNPJ(strAux.c_str());
    }

    cout << "Deseja alterar a inscrição estadual? [S/N]" << endl;
    cin >> op;
    if(op == 'S' || op == 's'){
      cout << "Novo inscrição estadual: ";
      cin.ignore();
      getline(cin, strAux);
      pessoaJuridicaAtual->setInscricaoEstadual(strAux.c_str());
    }

    cout << "Deseja alterar a razão social? [S/N]" << endl;
    cin >> op;
    if(op == 'S' || op == 's'){
      cout << "Novo razão social: ";
      cin.ignore();
      getline(cin, strAux);
      pessoaJuridicaAtual->setRazaoSocial(strAux.c_str());
    }

  }

  if (numeroDaConta[0] == '2'){
    ContaCorrenteLimite* contaCorrenteAtual = dynamic_cast<ContaCorrenteLimite*>(cAtual);
    cout << "Deseja alterar o limite da conta? [S/N]" << endl;
    cin >> op;
    if(op == 'S' || op == 's'){
      cout << "Novo limite: ";
      cin >> valor;
      contaCorrenteAtual->setLimite(valor);
    }
  }else if(numeroDaConta[0] == '3'){
    ContaPoupanca* contaPoupancaAtual = dynamic_cast<ContaPoupanca*>(cAtual);
    cout << "Deseja alterar o dia de aniversário da conta? [S/N]" << endl;
    cin >> op;
    if(op == 'S' || op == 's'){
      cout << "Novo dia: ";
      cin >> novaData;
      contaPoupancaAtual->setDiaDeAniversario(novaData);
    }
  }


} 


void Banco::listarContas() const {
  if(contas.size() == 0){
    cout << "O BANCO NÃO POSSUI NENHUMA CONTA" << endl;
  }
  for(auto c: contas){
    c->mostrarConta();
  }
}


void Banco::listarContasCorrentista(const char* nome) const {
  bool encontrou = false;
  for(auto c: contas){
    if(strcmp(c->pessoa->getNome(), nome) == 0){
      c->mostrarConta();
      encontrou = true;
    }
  }

  if(!encontrou){
    throw CorrentistaInexistente();
  }
}


Conta* Banco::existeConta(const char* numeroDaConta) const {
  for(Conta* c: contas){
    if(strcmp(c->getNumeroDaConta(), numeroDaConta) == 0){
      return c;
    }
  }

  throw ContaInexistente();
}
