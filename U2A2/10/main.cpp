#include <iostream>
using std::cout;
using std::endl;

#include "Agenda.h"
#include "Pessoa.h"

int main () {
	char linha[] = "---------------------------------------------\n";
	Agenda A(20);

	A.armazenaPessoa("Abel", 22, 1.78);

	A.armazenaPessoa(Pessoa("Tiago", 20, 1.80));
	A.imprimePovo();
	cout << linha;

	int posicao = A.buscaPessoa("Tiago");
	if (posicao > 0)
    	A.imprimePessoa(posicao);
	cout << linha;

	A.removePessoa("Abel");
	A.imprimePovo();
	cout << linha;
	
 	return 0;
}

// g++ -Wall -std=c++17  U2A2/10/*.cpp -o main && ./main