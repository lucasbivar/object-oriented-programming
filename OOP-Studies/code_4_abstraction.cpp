#include <iostream>

using std::string;

//abstract class - contract with rules
class AbstractEmployee{
  // pure virtual function or abstract function
  // the zero tells the compiler that the function has no body and above virtual
  // function will be called pure virtual function.
  virtual void AskForPromotion() = 0; 
};

class Employee:AbstractEmployee{
private:
  string Name;
  string Company;
  unsigned short int Age;

public:
  Employee(){
      Name = "No name";
      Company = "No company";
      Age = 0;
  };

  Employee(string name, string company, unsigned short int age){
    Name = name;
    Company = company;
    Age = age;
  };

  void setName(string name){
    Name = name;
  }

  string getName(){
    return Name;
  }

  void setCompany(string company){
    Company = company;
  }

  string getCompany(){
    return Company;
  }

  void setAge(unsigned short int age){
    if(age >= 18){
      Age = age;
    }
  }

  unsigned short int getAge(){
    return Age;
  }


  void IntroduceYourself(){
    std::cout << "Name - " << Name << std::endl;
    std::cout << "Company - " << Company << std::endl;
    std::cout << "Age - " << Age << std::endl;
    std::cout << std::endl;
  }

  void AskForPromotion(){
    if(Age > 30){
      std::cout << Name << " got promoted!" << std::endl;
    }else{
      std::cout << Name << ", sorry No promotion for you!" << std::endl;
    }
  };
};


int main(){
  Employee employee1, employee2, employee3, employee4;
  
  employee1 = Employee("Lucas Bivar", "Google", 18);
  employee2 = Employee("Vinicius Celestino", "Spotify", 19);
  employee3 = Employee("Joao Victor", "Facebook", 18);
  employee4 = Employee("John Doe", "Amazon", 35);

  employee1.IntroduceYourself();
  employee2.IntroduceYourself();
  employee3.IntroduceYourself();
  employee4.IntroduceYourself(); // the default constructor was called

  employee1.AskForPromotion();
  employee4.AskForPromotion();

  return 0;
}

// g++ -Wall -std=c++17 OOP-Studies/code_4_abstraction.cpp -o main && ./main