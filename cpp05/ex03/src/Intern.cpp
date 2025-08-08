#include "../include/Intern.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include <cstddef>

Intern::Intern() {};
Intern::Intern(const Intern &intern) { *this = intern; }

Intern &Intern::operator=(const Intern &intern) {
    (void)intern;
    return *this; }

Intern::~Intern() {};

const AForm *Intern::makeForm(const string &formName, const string &formTarget) {
  int arrLen = 3;
  string arr[] = {"shrubbery", "robotomy", "pardon"};

  for (int i = 0; i < arrLen; i++) {
    if (arr[i] == formName) {
      switch (i) {
      case 0:
        return new ShrubberyCreationForm(formName, formTarget);
      case 1:
        return new RobotomyRequestForm(formName, formTarget);
      case 2:
        return new PresidentialPardonForm(formName, formTarget);
      }
    }
  }
  return NULL;
}
