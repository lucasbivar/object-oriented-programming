#include "Imovel.h"
#include "ImovelNovo.h"
#include "ImovelVelho.h"

#include <iostream>
using std::cout;
using std::endl;

int main(){
  Imovel i("Rua João Cabral de Melo", 860000);
  ImovelNovo iNovo("Rua Cicero Galdino Pessoa Celestino", 920000, 650);
  ImovelVelho iVelho("Rua Onde Judas Bateu as Botas", 320000, 900);

  cout << "Imovel" << endl;
  cout << "Endereço: " << i.getAddress() << endl;
  cout << "Preço final: " << i.getPrice() << endl;
  cout << "------------------------" << endl << endl;

  cout << "Imovel Novo" << endl;
  cout << "Endereço: " << iNovo.getAddress() << endl;
  cout << "Preço final (Com taxa adicional): " << iNovo.getPrice() << endl;
  cout << "Valor da taxa adicional: " << iNovo.getAdditionalFee() << endl;
  cout << "------------------------" << endl << endl;

  cout << "Imovel Velho" << endl;
  cout << "Endereço: " << iVelho.getAddress() << endl;
  cout << "Preço final (Com desconto aplicado): " << iVelho.getPrice() << endl;
  cout << "Valor do desconto: " << iVelho.getDiscount() << endl;
  cout << "------------------------" << endl << endl;

  return 0;
}

// g++ -Wall -std=c++17  U2A4/7/*.cpp -o main && ./main