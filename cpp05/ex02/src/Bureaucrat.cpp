#include "../include/Bureaucrat.hpp"
#include <exception>
#include <iostream>

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "grade was set too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "grade was set too low!";
}

Bureaucrat::Bureaucrat() {};

Bureaucrat::Bureaucrat(string name, int grade) : _name(name) {
  try {
    if (grade < 1)
      throw GradeTooHighException();
    if (grade > 150)
      throw GradeTooLowException();
    _grade = grade;
  } catch (std::exception &e) {
    std::cout << _name << "'s " << e.what() << " Resetting to a default of 150."
              << std::endl;
    _grade = 150;
  }
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) { *this = bureaucrat; }

Bureaucrat::~Bureaucrat() {};

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
  if (&bureaucrat != this) {
    this->_name = bureaucrat._name;
    this->_grade = bureaucrat._grade;
  }
  return *this;
}
void Bureaucrat::signForm(AForm &form) const {
  try {
    form.beSigned(*this);
    std::cout << _name << " signed form " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << _name << " couldn't sign form " << form.getName()
              << " because " << e.what() << std::endl;
  }
}
const string &Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

std::ostream &operator<<(std::ostream &os, Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << ", " << "bureaucrat grade "
     << bureaucrat.getGrade() << std::endl;
  return os;
}
