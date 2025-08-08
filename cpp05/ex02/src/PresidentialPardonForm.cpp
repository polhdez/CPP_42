#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

using std::string;

void PresidentialPardonForm::_pardon() const {
  std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const string &name,
                                               const string &target)
    : AForm(name, target, 25, 5) {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  try {
    if (!isSigned())
      throw FormNotSignedException();
    if (executor.getGrade() <= getGradeToExecute())
      _pardon();
    else
      throw GradeTooLowException();
  } catch (std::exception &e) {
    std::cout << executor.getName() << " couldn't execute form " << getName()
              << " because " << e.what() << std::endl;
  }
}
