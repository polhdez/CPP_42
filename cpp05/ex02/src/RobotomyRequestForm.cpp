#include "../include/RobotomyRequestForm.hpp"
#include "../include/Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <time.h>

using std::string;

void RobotomyRequestForm::_robotomize() const {
  std::cout << "Bzzzzzzzzz! BRRRRRRRRR! BZZZZZZZ!" << std::endl;
  srand(time(NULL));
  if (rand() % 2)
    std::cout << "Subject " << getTarget() << " has been robotomized!"
              << std::endl;
  else
    std::cout << "Subject " << getTarget()
              << " woke up during surgery! Robotomization failed!" << std::endl;
  ;
}

RobotomyRequestForm::RobotomyRequestForm(const string &name,
                                         const string &target)
    : AForm(name, target, 72, 45) {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
  try {
    if (!isSigned())
      throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
      throw GradeTooLowException();
    else
      _robotomize();
  } catch (std::exception &e) {
    std::cout << executor.getName() << " couldn't execute form " << getName()
              << " because " << e.what() << std::endl;
  }
}
