#include "Cliente.h"
#include "Funcionario.h"
#include "Empresa.h"

#include <iostream>
using std::cout;
using std::endl;

int main(){
  Empresa company("VTEX",1233123312312, "VTEX BRASIL TECNOLOGIA PARA E-COMMERCE LTDA");
  
  Cliente client1("Nattan", 32415675654, "Rua Pedro Gondim", 988360000);
  Cliente client2("Tarcisio", 12312312312, "Rua João Pessoa", 988361111);

  Funcionario employee1("Vinicius Medeiros", 12312312312, 23023, 220, 200, 6000);
  Funcionario employee2("João Victor", 45678945632, 12322, 220, 194, 5500);
  Funcionario employee3("Thales Luiz", 78945612323, 87774, 220, 215, 5000);

  company.addEmployee(employee1);
  company.addEmployee(employee2);
  company.addEmployee(employee3);

  company.addClient(client1);
  company.addClient(client2);

  company.showEmployees();
  company.showClients();

  cout << "Folha de Pagamentos: " << company.calculatePaymentSheet() << endl;

  return 0;
}

// g++ -Wall -std=c++17  U2A4/11/*.cpp -o main && ./main