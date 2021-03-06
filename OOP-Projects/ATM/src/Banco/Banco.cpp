#include "../../include/Banco/Banco.h"

#include "../../include/Excecoes/ContaInexistente.h"
#include "../../include/Excecoes/CorrentistaInexistente.h"

#include "../../include/Pessoa/Pessoa.h"
#include "../../include/Pessoa/PessoaJuridica.h"
#include "../../include/Pessoa/PessoaFisica.h"

#include "../../include/Conta/ContaCorrente.h"
#include "../../include/Conta/ContaCorrenteLimite.h"
#include "../../include/Conta/ContaPoupanca.h"

#include "../../include/Transacao/Transacao.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;
using std::to_string;

#include <fstream>
using std::fstream;
using std::ofstream;

using std::ios;


#include <list>
using std::list;

#include <vector>
using std::vector;

#include <unordered_map>
using std::unordered_map;

#include <sstream>
using std::stringstream;

#include <algorithm>
using std::transform;

Banco::Banco(string nome, string email, 
  string cnpj, string inscricaoEstadual, string razaoSocial):
  PessoaJuridica(nome, email, cnpj, inscricaoEstadual, razaoSocial){

  fstream dataBase;
  dataBase.open("dataBase.txt", ios::in);
  if(!dataBase){
    dataBase.close();
    dataBase.open("dataBase.txt", ios::out);
    dataBase.close();
  }else{
    string line;
    list<string> lines;
    while(!dataBase.eof()){
      getline(dataBase, line);
      lines.push_back(line);
    }

    dataBase.close();
    unordered_map<string, list<Transacao>> transacoesContas;
    
    for(string line: lines){
      stringstream ss(line);
      vector<string> currentData;

      while(ss.good()){
        string substr;
        getline(ss, substr, ';');
        currentData.push_back(substr);
      }

      if(currentData[0] == "PF"){
        PessoaFisica* novaPF = new PessoaFisica(currentData[1], currentData[2], currentData[3], currentData[4], currentData[5]);
        correntistas.push_back(novaPF);
      }else if(currentData[0] == "PJ"){
        PessoaJuridica* novaPJ = new PessoaJuridica(currentData[1], currentData[2], currentData[3], currentData[4], currentData[5]);
        correntistas.push_back(novaPJ);
      } else if(currentData[0] == "C"){
        if(currentData[1][0] == '1'){

          Pessoa* pContaAtual = getPonteiroPessoa(currentData[2]);

          ContaCorrente* novaCC = new ContaCorrente(pContaAtual, to_string(currentData[1][0]), to_string(currentData[1][1]),
          stod(currentData[3]), currentData[1], transacoesContas[currentData[1]]);

          contas.push_back(novaCC);

        }else if(currentData[1][0] == '2'){

          Pessoa* pContaAtual = getPonteiroPessoa(currentData[2]);

          ContaCorrenteLimite* novaCCL = new ContaCorrenteLimite(pContaAtual, to_string(currentData[1][0]), to_string(currentData[1][1]),
          stod(currentData[4]), stod(currentData[3]), currentData[1], transacoesContas[currentData[1]]);

          contas.push_back(novaCCL);

        }else if(currentData[1][0] == '3'){
          Pessoa* pContaAtual = getPonteiroPessoa(currentData[2]);

          ContaPoupanca* novaCP = new ContaPoupanca(pContaAtual, to_string(currentData[1][0]), to_string(currentData[1][1]),
          stoi(currentData[4]), stod(currentData[3]), currentData[1], transacoesContas[currentData[1]]);

          contas.push_back(novaCP);
        }
      } else if(currentData[0] == "T"){

        Transacao novaTransacao = Transacao(stod(currentData[2]), currentData[3], currentData[1], currentData[4]);
        transacoesContas[currentData[1]].push_back(novaTransacao);
      }
    }

  }
}

Banco::~Banco(){
  ofstream dataBase;
  dataBase.open("dataBase.txt");
  for(Pessoa* p: correntistas){
    string line;
    PessoaFisica* pessoaF = dynamic_cast<PessoaFisica*>(p);
    if(pessoaF){
      line = "PF;"+pessoaF->getNome()+";"+pessoaF->getEmail()+";"+pessoaF->getCPF()+";"+pessoaF->getDataDeNascimento()+";"+pessoaF->getEstadoCivil();
      dataBase << line << endl;
    }else{
      PessoaJuridica* pessoaJ = dynamic_cast<PessoaJuridica*>(p);
      line = "PJ;"+pessoaJ->getNome()+";"+pessoaJ->getEmail()+";"+pessoaJ->getCNPJ()+";"+pessoaJ->getInscricaoEstadual()+";"+pessoaJ->getRazaoSocial();
      dataBase << line << endl;
    }
  }

  for(Conta* c: contas){
    string line;
    for(Transacao t: c->listaDeTransacoes){
      line = "T;"+c->getNumeroDaConta()+";"+to_string(t.getValorDaTransacao())+";"+t.getDescricao()+";"+t.getData();
      dataBase << line << endl;
      line = "";
    }

    ContaCorrenteLimite* contaCL = dynamic_cast<ContaCorrenteLimite*>(c);
    ContaPoupanca* contaP = dynamic_cast<ContaPoupanca*>(c);
    line = "C;"+c->getNumeroDaConta()+";"+c->pessoa->getNome()+";"+to_string(c->saldo)+";";
    if(contaCL){
      line += to_string(contaCL->getLimite());
    }else if(contaP){
      line += to_string(contaP->getDiaDeAniversario());
    }
    dataBase << line << endl;
    line = "";
  }

  dataBase.close();

  for(Pessoa* p: correntistas){
    delete p;
  }

  for(Conta* c: contas){
    delete c;
  }

}


void Banco::removerConta(string numeroDaConta){
  bool encontrou = false;
  Pessoa *p = nullptr;

  for(list<Conta*>::iterator it = contas.begin(); it != contas.end(); it++){
    if((*it)->getNumeroDaConta() == numeroDaConta){
      p = (*it)->pessoa;
      delete *it;
      contas.erase(it);
      encontrou = true;
      break;
    }
  }

  if(!encontrou){
    throw ContaInexistente();
  }

  bool temOutraConta = false;

  for(list<Conta*>::iterator it = contas.begin(); it != contas.end(); it++){
    if((*it)->pessoa->getNome() == p->getNome()){
      temOutraConta = true;
      break;
    }
  }

  if(!temOutraConta){
    list<Pessoa*>::iterator it;
    for(list<Pessoa*>::iterator it = correntistas.begin(); it != correntistas.end(); it++){
      if((*it)->getNome() == p->getNome()){
        correntistas.erase(it);
        delete p;
        break;
      }
    }
  }

}

void Banco::consultarConta(string numeroDaConta) const{
  bool encontrou = false;

  for(auto c: contas){
    if(c->getNumeroDaConta() == numeroDaConta){
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

  cout << "J?? possui alguma conta no banco?" << endl;
  cout << "1 - Sim" << endl;
  cout << "2 - N??o" << endl;
  cout << "Op.: ";
  while(true){
    cin >> opTemConta;
    if (cin.fail()){
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if(opTemConta >= 1 && opTemConta <= 2) break;
    cout << "Op????o Inv??lida. Tente novamente!" << endl;
    cout << "Op.: ";
  }

  cout << "Tipo de Pessoa:" << endl;
  cout << "1 - Pessoa F??sica" << endl;
  cout << "2 - Pessoa Jur??dica" << endl;
  cout << "3 - Cancelar" << endl;
  cout << "Op.: ";
  while(true){
    cin >> opPessoa;
    if (cin.fail()){
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if(opPessoa == 3)  return;
    if(opPessoa >= 1 && opPessoa <=2) break;
    cout << "Op????o Inv??lida. Tente novamente!" << endl;
    cout << "Op.: ";
  }

  if(opTemConta == 2){
    cin.ignore();
    cout << "Nome: " << endl;
    getline(cin, strAux1);

    cout << "E-mail: " << endl;
    cin >> strAux2;

    if(opPessoa == 1){
      novaPessoaFisica = new PessoaFisica(strAux1, strAux2);
    }else{
      novaPessoaJuridica = new PessoaJuridica(strAux1, strAux2);
    }

    if(opPessoa == 1){
      cout << "CPF (sem pontua????o): ";
      cin >> strAux1;
      novaPessoaFisica->setCPF(strAux1);

      cout << "Data de Nascimento (sem pontua????o - ddmmyyyy): ";
      cin >> strAux1;
      novaPessoaFisica->setDataDeNascimento(strAux1);
    
      string estadoCivil[5] = {"Solteiro", "Casado", "Separado", "Divorciado", "Vi??vo"};
      cout << "Estado Civil: " << endl;
      for(int i = 1; i <= 5; i++){
        cout << i << " - " << estadoCivil[i-1] << endl;
      }
      cout << "Op.: ";
      while(true){
        cin >> opAux;
        if (cin.fail()){
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if(opAux >= 1 && opAux <= 5) break;
        cout << "Op????o Inv??lida. Tente novamente!" << endl;
        cout << "Op.: ";
      }
      novaPessoaFisica->setEstadoCivil(estadoCivil[opAux-1]);

      correntistas.push_back(novaPessoaFisica);
    }else{
      cout << "CNPJ (sem pontua????o): ";
      cin >> strAux1;
      novaPessoaJuridica->setCNPJ(strAux1);

      cout << "Inscri????o Estadual: ";
      cin.ignore();
      getline(cin, strAux1);
      novaPessoaJuridica->setInscricaoEstadual(strAux1);

      cout << "Raz??o Social: ";
      getline(cin, strAux1);
      novaPessoaJuridica->setRazaoSocial(strAux1);

      correntistas.push_back(novaPessoaJuridica);
    }
  }else{
    bool achou = false;
    while(true){
      cout << "Nome (-1 para cancelar): " << endl;
      cin.ignore();
      getline(cin, strAux1);  

      if(strAux1 == "-1" || strAux1 == "1"){
        operacaoCancelada = true;
        break;
      }

      for(Pessoa* p: correntistas){
        if(p->getNome() == strAux1){
          achou = true;
          pAux = p;
          break;
        }
      }
      if(achou) break;
      cout << "Nome n??o encontrado na base. Tente novamente!" << endl;
    }

  }

  if(operacaoCancelada) return;

  cout << "Tipo da conta:" << endl;
  cout << "1 - Conta Corrente" << endl;
  cout << "2 - Conta Corrente Com Limite" << endl;
  cout << "3 - Conta Poupan??a" << endl;
  cout << "Op.: ";
  while(true){
    cin >> opConta;
    if (cin.fail()){
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if(opConta >= 1 && opConta <= 3) break;
    cout << "Op????o Inv??lida. Tente novamente!" << endl;
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
    cout << "Dia de Anivers??rio da Conta: " << endl;
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

void Banco::editarConta(string numeroDaConta) {
  bool encontrou = false;
  Conta* cAtual = nullptr;
  string strAux;
  string op;
  double valor;
  int novaData, opAux;

  for(Conta* c: contas){
    if(c->getNumeroDaConta() == numeroDaConta){
      encontrou = true;
      cAtual = c;
      break;
    }
  }

  if(!encontrou) {
    throw ContaInexistente();
  }
  cout << "Deseja alterar o nome? [S/N]" << endl;
  getline(cin, op);
  if(op[0] == 'S' || op[0] == 's'){
    cout << "Novo nome: ";
    getline(cin, strAux);
    cAtual->pessoa->setNome(strAux);
  }


  cout << "Deseja alterar o e-mail? [S/N]" << endl;
  getline(cin, op);

  if(op[0] == 'S' || op[0] == 's'){
    cout << "Novo e-mail: ";
    getline(cin, strAux);
    cAtual->pessoa->setEmail(strAux);
  }


  if(numeroDaConta[1] == '1'){
    PessoaFisica* pessoaFisicaAtual = dynamic_cast<PessoaFisica*>(cAtual->pessoa);
    cout << "Deseja alterar o CPF? [S/N]" << endl;
    getline(cin, op);
    if(op[0] == 'S' || op[0] == 's'){
      cout << "Novo CPF: ";
      getline(cin, strAux);
      pessoaFisicaAtual->setCPF(strAux);
    }

    cout << "Deseja alterar a data de nascimento? [S/N]" << endl;
    getline(cin, op);
    if(op[0] == 'S' || op[0] == 's'){
      cout << "Nova data de nascimento (sem pontua????o - ddmmyyyy): ";
      getline(cin, strAux);
      pessoaFisicaAtual->setDataDeNascimento(strAux);
    }

    cout << "Deseja alterar o estado civil? [S/N]" << endl;
    getline(cin, op);
    if(op[0] == 'S' || op[0] == 's'){
      string estadoCivil[5] = {"Solteiro", "Casado", "Separado", "Divorciado", "Vi??vo"};
      cout << "Estado Civil: " << endl;;
      for(int i = 1; i <= 5; i++){
        cout << i << " - " << estadoCivil[i-1] << endl;
      }
      cout << "Op.: ";
      while(true){
        cin >> opAux;
        if (cin.fail()){
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if(opAux >= 1 && opAux <= 5) break;
        cout << "Op????o Inv??lida. Tente novamente!" << endl;
        cout << "Op.: ";
      }
      pessoaFisicaAtual->setEstadoCivil(estadoCivil[opAux-1]);
    }

  }else if(numeroDaConta[1] == '2'){
    PessoaJuridica* pessoaJuridicaAtual = dynamic_cast<PessoaJuridica*>(cAtual->pessoa);

    cout << "Deseja alterar o CNPJ? [S/N]" << endl;
    getline(cin, op);
    if(op[0] == 'S' || op[0] == 's'){
      cout << "Novo CNPJ: ";
      getline(cin, strAux);
      pessoaJuridicaAtual->setCNPJ(strAux);
    }

    cout << "Deseja alterar a inscri????o estadual? [S/N]" << endl;
    getline(cin, op);
    if(op[0] == 'S' || op[0] == 's'){
      cout << "Novo inscri????o estadual: ";
      getline(cin, strAux);
      pessoaJuridicaAtual->setInscricaoEstadual(strAux);
    }

    cout << "Deseja alterar a raz??o social? [S/N]" << endl;
    getline(cin, op);
    if(op[0] == 'S' || op[0] == 's'){
      cout << "Novo raz??o social: ";
      getline(cin, strAux);
      pessoaJuridicaAtual->setRazaoSocial(strAux);
    }

  }

  if (numeroDaConta[0] == '2'){
    ContaCorrenteLimite* contaCorrenteAtual = dynamic_cast<ContaCorrenteLimite*>(cAtual);
    cout << "Deseja alterar o limite da conta? [S/N]" << endl;
    getline(cin, op);
    if(op[0] == 'S' || op[0] == 's'){
      cout << "Novo limite: ";
      cin >> valor;
      if (cin.fail()){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      contaCorrenteAtual->setLimite(valor);
    }
  }else if(numeroDaConta[0] == '3'){
    ContaPoupanca* contaPoupancaAtual = dynamic_cast<ContaPoupanca*>(cAtual);
    cout << "Deseja alterar o dia de anivers??rio da conta? [S/N]" << endl;
    getline(cin, op);
    if(op[0] == 'S' || op[0] == 's'){
      cout << "Novo dia: ";
      cin >> novaData;
      if (cin.fail()){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      };
      contaPoupancaAtual->setDiaDeAniversario(novaData);
    }
  }


} 


void Banco::listarContas() const {
  if(contas.size() == 0){
    cout << "O BANCO N??O POSSUI NENHUMA CONTA" << endl;
  }
  for(auto c: contas){
    c->mostrarConta();
  }
}


void Banco::listarContasCorrentista(string nome) const {
  bool encontrou = false;
  transform(nome.begin(), nome.end(), nome.begin(), ::tolower);
  for(auto c: contas){
    string cmpNome = c->pessoa->getNome();
    transform(cmpNome.begin(), cmpNome.end(), cmpNome.begin(), ::tolower);

    if(cmpNome == nome){
      c->mostrarConta();
      encontrou = true;
    }
  }

  if(!encontrou){
    throw CorrentistaInexistente();
  }
}


Conta* Banco::existeConta(string numeroDaConta) const {
  for(Conta* c: contas){
    if(c->getNumeroDaConta() == numeroDaConta){
      return c;
    }
  }

  throw ContaInexistente();
}

Pessoa* Banco::getPonteiroPessoa(string nomeDoCorrentista) {
  for(Pessoa* p: correntistas){
    if(p->getNome() == nomeDoCorrentista){
      return p;
    }
  }
  return nullptr;
}