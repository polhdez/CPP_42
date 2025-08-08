#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Intern.hpp"
#include <iostream>
#include <sstream>

int main(int argc, char **argv) {

  // Handle first argument to set the bureoucrat level;
  int grade;
  if (argc == 2) {
    std::stringstream ss(argv[1]);
    ss >> grade;
    if (ss.fail())
      grade = 1;
  } else
    grade = 1;

  Intern intern;

  // Required to sign 145 to execute 137
  Bureaucrat b1 = Bureaucrat("Pepe", grade);
  std::cout << "Bureoucrat info:" << std::endl << b1;
  std::cout << "-------------------------------------" << std::endl;
  ShrubberyCreationForm* sForm1 = (ShrubberyCreationForm*)intern.makeForm("shrubbery", "garden");
  b1.signForm(*sForm1);
  std::cout << "Form info:" << std::endl << *sForm1;
  b1.executeForm(*sForm1);
  delete sForm1;
  // Required to sign 72 to execute 45
  std::cout << "#####################################" << std::endl;
  Bureaucrat b2 = Bureaucrat("Maria", grade);
  std::cout << "Bureoucrat info:" << std::endl << b2;
  std::cout << "-------------------------------------" << std::endl;
  RobotomyRequestForm* rForm1 =
     (RobotomyRequestForm*)intern.makeForm("robotomy", "bad guy");
  b2.signForm(*rForm1);
  std::cout << "-------------------------------------" << std::endl;
  std::cout << "Form info:" << std::endl << *rForm1;
  std::cout << "-------------------------------------" << std::endl;
  b2.executeForm(*rForm1);
  delete rForm1;
  // Required to sign 25 to execute 5
  std::cout << "#####################################" << std::endl;
  Bureaucrat b3 = Bureaucrat("Joe", grade);
  std::cout << "Bureoucrat info:" << std::endl << b3;
  std::cout << "-------------------------------------" << std::endl;
  PresidentialPardonForm* pForm1 =
     (PresidentialPardonForm*)intern.makeForm("pardon", "political oponent");
  b3.signForm(*pForm1);
  std::cout << "-------------------------------------" << std::endl;
  std::cout << "Form info:" << std::endl << *pForm1;
  std::cout << "-------------------------------------" << std::endl;
  b3.executeForm(*pForm1);
  delete pForm1;
}
