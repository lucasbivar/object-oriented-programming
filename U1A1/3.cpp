#include <iostream>
 
int main(){
  std::string name;
  double n1, n2, n3;
 
  std::cout << "Digite seu primeiro nome: ";
  std::cin >> name;
  std::cout << "Digite as 3 notas separadas por espaço: ";
 
  std::cin >> n1 >> n2 >> n3;
  double average = (n1*3 + n2*4 + n3*5)/12.;
 
  std::cout << "O aluno " << name << " obteve média " << average << std::endl;
  return 0;
}

