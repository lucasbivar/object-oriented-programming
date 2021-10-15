#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include<string>
using std::string;

#include "../include/Pessoa/Pessoa.h"
#include "../include/Pessoa/PessoaFisica.h"
#include "../include/Pessoa/PessoaJuridica.h"

#include "../include/Conta/ContaCorrente.h"
#include "../include/Conta/ContaCorrenteLimite.h"
#include "../include/Conta/ContaPoupanca.h"
#include "../include/Conta/Conta.h"
#include "../include/Banco/Banco.h"

#include <stdexcept>
using std::runtime_error;
using std::invalid_argument;

#include <chrono>
#include <thread>
using namespace std::literals::chrono_literals;

void visaoCorrentista(Banco& banco);
void visaoGerente(Banco& banco);

int main(){
  Banco banco("IFBank", "ifbank@org.com", "12341234123412", "9999999", "IFBank S.A");

  int opVisao;

  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cout << "         Bem-vindo ao IFBank" << endl;
  cout << "-------------------------------------------" << endl;

  cout << "Em qual cargo você se encaixa?" << endl;
  cout << "1 - Gerente" << endl;
  cout << "2 - Correntista" << endl;
  cout << "3 - Encerrar programa" << endl;
  cout << "Op.: ";
  while(true){
    cin >> opVisao;
    if (cin.fail()){
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if(opVisao >= 1 && opVisao <= 3) break;
    cout << "Opção Inválida. Tente novamente!" << endl;
    cout << "Op.: ";
  }

  if(opVisao == 3) return 0;
  system("clear");

  if(opVisao == 1){
    visaoGerente(banco);
  }else{
    visaoCorrentista(banco);
  }

  return 0;
}

void visaoGerente(Banco& banco){
  int opAtual;
  string strAux;
  while (true){
      cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
      cout << "            Gerente - IFBank" << endl;
      cout << "-------------------------------------------" << endl;
      cout << "1 - Abrir Conta" << endl;
      cout << "2 - Consultar Conta" << endl;
      cout << "3 - Atualizar Conta" << endl;
      cout << "4 - Fechar Conta" << endl;
      cout << "5 - Listar contas" << endl;
      cout << "6 - Listar contas de um correntista" << endl;
      cout << "7 - Sair do programa" << endl;
      cout << "-------------------------------------------" << endl;
      cout << "Op.: ";
      while(true){
        cin >> opAtual;
        if (cin.fail()){
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if(opAtual == 7) break;
        if(opAtual >= 1 && opAtual <= 6) break;
        cout << "Opção Inválida. Tente novamente!" << endl;
        cout << "Op.: ";
      }

      if(opAtual == 1){
        banco.cadastrarConta();
      }else if(opAtual == 2){
        cout << "Número da Conta: ";
        cin.ignore();
        getline(cin, strAux);
        try{
          banco.consultarConta(strAux);
        }catch(runtime_error& e){
          cout << e.what();
          cout << endl << endl;
        }
      }else if(opAtual == 3){
        cout << "Número da Conta: ";
        cin.ignore();
        getline(cin, strAux);
        cout << strAux << endl;
        try{
          banco.editarConta(strAux);
          cout << "Conta editada com sucesso!" << endl;
        }catch(runtime_error& e){
          cout << e.what();
          cout << endl << endl;
        }
      }else if(opAtual == 4){
        cout << "Número da Conta: ";
        cin.ignore();
        getline(cin, strAux);
        try{
          banco.removerConta(strAux);
          cout << "Conta removida com sucesso!" << endl;
        }catch(runtime_error& e){
          cout << e.what();
          cout << endl << endl;
        }
      }else if(opAtual == 5){
        banco.listarContas();
      }else if(opAtual == 6){
        cout << "Digite o nome do correntista:" << endl;
        cin.ignore();
        getline(cin, strAux);
        try{
          banco.listarContasCorrentista(strAux);
        }catch(runtime_error& e){
          cout << e.what();
          cout << endl << endl;
        }
      }else if(opAtual == 7){
        std::this_thread::sleep_for(1500ms);
        system("clear");
        break;
      }
    }
}


void visaoCorrentista(Banco& banco){
  string numeroDaContaAtual;
  Conta* contaAtual;
  int opAtual;
  double valor;

  while(true){
    cout << "Digite o número da sua conta (-1 encerra): ";
    cin.ignore();
    cin >> numeroDaContaAtual;
    if(numeroDaContaAtual == "-1") break;

    try{
      contaAtual = banco.existeConta(numeroDaContaAtual);
    }catch(runtime_error& e){
      cout << e.what();
      cout << endl << endl;
      continue;
    }

    while (true){
      cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
      cout << "          Correntista - IFBank" << endl;
      cout << "-------------------------------------------" << endl;
      cout << "1 - Depositar" << endl;
      cout << "2 - Retirar" << endl;
      cout << "3 - Transferir" << endl;
      cout << "4 - Saldo" << endl;
      cout << "5 - Extrato" << endl;
      cout << "6 - Sair da conta" << endl;
      cout << "-------------------------------------------" << endl;
      cout << "Op.: ";
      while(true){
        cin >> opAtual;
        if (cin.fail()){
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if(opAtual >= 1 && opAtual <= 6) break;
        cout << "Opção Inválida. Tente novamente!" << endl;
        cout << "Op.: ";
      }
      
      if(opAtual == 1) {

        cout << "Insira o valor do deposito." << endl << "R$ ";
        cin >> valor;
        if (cin.fail()){
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        try{
          (*contaAtual) << valor;
          cout << "Deposito realizado com sucesso!!" << endl;
        }catch(invalid_argument& e){
          cout << e.what();
          cout << endl << endl;
          continue;
        }

      }else if(opAtual == 2){
        cout << "Insira o valor da retirada." << endl << "R$ ";
        cin >> valor;
        if (cin.fail()){
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        try{
          (*contaAtual) >> valor;
          cout << "Retirada realizada com sucesso!!" << endl;
        }catch(invalid_argument& e){
          cout << e.what();
          cout << endl << endl;
          continue;
        }

      }else if(opAtual == 3){
        Conta* contaDestino;
        
        cout << "Digite o número da conta de destino: ";
        cin >> numeroDaContaAtual;
        try{
          contaDestino = banco.existeConta(numeroDaContaAtual);
        }catch(runtime_error& e){
          cout << e.what();
          cout << endl << endl;
          continue;
        }

        
        cout << "Digite o valor da transferência." << endl << "R$ ";
        cin >> valor;
        if (cin.fail()){
          cin.clear();
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        try{
          contaAtual->transferir(valor, contaDestino);
          cout << "Transferência realizado com sucesso!!" << endl;
        }catch(runtime_error& e){
          cout << e.what();
          cout << endl << endl;
          continue;
        }

      }else if(opAtual == 4){
        contaAtual->mostrarConta();
      }else if(opAtual == 5){
        contaAtual->imprimirExtrato();
      }else if(opAtual == 6){
        std::this_thread::sleep_for(1500ms);
        system("clear");
        break;
      }
    }      
  }
}