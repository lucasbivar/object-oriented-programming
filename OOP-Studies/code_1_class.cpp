#include <iostream>

using std::string;

class Employee{
public:
  string Name;
  string Company;
  unsigned short int Age;

  void IntroduceYourself(){
    std::cout << "Name - " << Name << std::endl;
    std::cout << "Company - " << Company << std::endl;
    std::cout << "Age - " << Age << std::endl;
    std::cout << std::endl;
  }
};


int main(){
  Employee employee1, employee2, employee3;

  employee1.Name = "Lucas Bivar";
  employee1.Company = "Google";
  employee1.Age = 18;

  employee2.Name = "Vinicius Celestino";
  employee3.Company = "Spotify";
  employee2.Age = 19;

  employee3.Name = "João Victor";
  employee3.Company = "Facebook";
  employee3.Age = 19;

  employee1.IntroduceYourself();
  employee2.IntroduceYourself();
  employee3.IntroduceYourself();

  return 0;
}

// g++ -Wall -std=c++17 OOP-Studies/code_1_class.cpp -o main && ./main