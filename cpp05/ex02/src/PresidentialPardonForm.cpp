#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"
#include <iostream>
#include <string>

using std::string;

void PresidentialPardonForm::_pardon() const {
  std::cout << getName() << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const string &name)
    : AForm(name, 25, 5) {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  if (executor.getGrade() <= getGradeToExecute())
    _pardon();
  else
    throw GradeTooLowException();
}
