#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include <iostream>

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;

  // Required to sign 145 to execute 137
  std::cout << "-------------------------------------" << std::endl;
  Bureaucrat b1 = Bureaucrat("Pepe", 1);
  std::cout << "Bureoucrat info:" << std::endl << b1;
  ShrubberyCreationForm sForm1 =
      ShrubberyCreationForm("GardeningRequest", "garden");
  b1.signForm(sForm1);
  std::cout << "Form info:" << std::endl << sForm1;
  sForm1.execute(b1);
  // Required to sign 72 to execute 45
  std::cout << "-------------------------------------" << std::endl;
  Bureaucrat b2 = Bureaucrat("Maria", 1);
  std::cout << "Bureoucrat info:" << std::endl << b2 << std::endl;
  RobotomyRequestForm rForm1 =
      RobotomyRequestForm("RobotomyRequest", "political opponent");
  b2.signForm(rForm1);
  std::cout << "Form info:" << std::endl << rForm1;
  rForm1.execute(b2);
  // Required to sign 25 to execute 5
  std::cout << "-------------------------------------" << std::endl;
  Bureaucrat b3 = Bureaucrat("Joe", 26);
  std::cout << "Bureoucrat info:" << std::endl << b3;
  PresidentialPardonForm pForm1 =
      PresidentialPardonForm("PardonRequest", "criminal");
  b3.signForm(pForm1);
  std::cout << "Form info:" << std::endl << pForm1;
  pForm1.execute(b3);
  std::cout << "-------------------------------------" << std::endl;
}
