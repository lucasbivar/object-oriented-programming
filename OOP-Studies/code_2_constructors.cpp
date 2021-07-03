#include <iostream>

using std::string;

class Employee{
public:
  string Name;
  string Company;
  unsigned short int Age;
  // Default constructor
  Employee(){
      Name = "No name";
      Company = "No company";
      Age = 0;
      std::cout << "Object is being created!" << std::endl;
  };

  Employee(string name, string company, unsigned short int age){
    Name = name;
    Company = company;
    Age = age;
    std::cout << "Object is being created!" << std::endl;
  };

  ~Employee(){
    std::cout << "Object is being deleted!" << std::endl;
  };

  void IntroduceYourself(){
    std::cout << "Name - " << Name << std::endl;
    std::cout << "Company - " << Company << std::endl;
    std::cout << "Age - " << Age << std::endl;
    std::cout << std::endl;
  }
};


int main(){
  

  Employee employee1 = Employee("Lucas Bivar", "Google", 18);
  Employee employee2 = Employee("Vinicius Celestino", "Spotify", 19);
  Employee employee3 = Employee("Joao Victor", "Facebook", 18);
  Employee employee4;
  
  employee1.IntroduceYourself();
  employee2.IntroduceYourself();
  employee3.IntroduceYourself();
  employee4.IntroduceYourself(); // the default constructor was called

  return 0;
}

// g++ -Wall -std=c++17 OOP-Studies/code_2_constructors.cpp -o main && ./main