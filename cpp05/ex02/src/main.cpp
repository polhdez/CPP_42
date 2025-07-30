#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;

  Bureaucrat b1 = Bureaucrat("Pepe", 1);
  ShrubberyCreationForm sForm1 = ShrubberyCreationForm("garden");
  b1.signForm(sForm1);
  sForm1.execute(b1);
  Bureaucrat b2 = Bureaucrat("Maria", 1);
  RobotomyRequestForm rForm1 = RobotomyRequestForm("mutant");
  b2.signForm(rForm1);
  rForm1.execute(b2);
  Bureaucrat b3 = Bureaucrat("Joe", 1);
  PresidentialPardonForm pForm1 = PresidentialPardonForm("Criminal");
  b3.signForm(pForm1);
  pForm1.execute(b3);
  /*
  std::cout << "--- starting form1 tests ---" << std::endl;
  Bureaucrat b1 = Bureaucrat("Pepe", 40);
  Form form1 = Form("Form1", 10, 100);
  std::cout << b1 << std::endl;
  b1.signForm(form1);
  std::cout << form1 << std::endl;
  std::cout << "--- starting form2 tests ---" << std::endl;
  Bureaucrat b2 = Bureaucrat("Maria", 40);
  Form form2 = Form("Form2", 50, 100);
  std::cout << b2 << std::endl;
  b2.signForm(form2);
  std::cout << form2 << std::endl;
  std::cout << "--- starting form3 tests ---" << std::endl;
  Bureaucrat b3 = Bureaucrat("Juan", 170);
  Form form3 = Form("Form3", 10, 100);
  std::cout << b3 << std::endl;
  std::cout << form3 << std::endl;
  std::cout << "--- starting form4 tests ---" << std::endl;
  Bureaucrat b4 = Bureaucrat("Alberto", 40);
  Form form4 = Form("Form4", 10, 200);
  std::cout << b4 << std::endl;
  b4.signForm(form4);
  std::cout << form4 << std::endl;
  std::cout << "--- starting form5 tests ---" << std::endl;
  Bureaucrat b5 = Bureaucrat("Anna", 100);
  Form form5 = Form("Form5", 120, 100);
  std::cout << b5 << std::endl;
  b5.signForm(form5);
  std::cout << form5 << std::endl;
  */
}
