#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(){
  double quilometragemAtual = 0, litrosAtual = 0, consumoAtual, litrosTotal = 0;
  while (true){
    cout << "Insira a quilometragem dirigida (-1 para sair): ";
    cin >> quilometragemAtual;
    if(quilometragemAtual == -1) break;

    cout << "Quantidade de combustível em litros: ";
    cin >> litrosAtual;
    litrosTotal += litrosAtual;

    consumoAtual = quilometragemAtual/litrosAtual;
    cout << "O consumo do tanque foi " << consumoAtual << " km/l." << endl;
  }
  cout << "A quantidade de combustivel utilizado foi: " << litrosTotal << " litros." << endl;

  return 0;
}