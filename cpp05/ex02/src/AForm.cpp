#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

using std::string;

const char *AForm::GradeTooHighException::what() const throw() {
  return "grade was set too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "grade was set too low!";
}

const char *AForm::FormNotSignedException::what() const throw() {
  return "form isn't signed!";
}

void AForm::_checkValidFormGrade(int grade) const {
  if (grade > 150)
    throw AForm::GradeTooLowException();
  if (grade < 1)
    throw AForm::GradeTooHighException();
}

void AForm::_checkSignGrade(int grade) const {
  if (grade > _gradeToSign)
    throw AForm::GradeTooLowException();
  if (grade < 1)
    throw AForm::GradeTooHighException();
}

void AForm::_checkExecuteGrade(int grade) const {
  if (grade > _gradeToExecute)
    throw AForm::GradeTooLowException();
  if (grade < 1)
    throw AForm::GradeTooHighException();
}

AForm::AForm() : _name("Form"), _gradeToSign(150), _gradeToExecute(150) {
  _isSigned = false;
}

AForm::AForm(const string &name, const int gradeToSign,
             const int gradeToExecute)
    : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
  try {
    _checkValidFormGrade(gradeToSign);
    _checkValidFormGrade(gradeToExecute);
  } catch (std::exception &e) {
    std::cout << _name << " is a invalid form because the " << e.what()
              << std::endl;
  }
  _isSigned = false;
}

AForm::AForm(const AForm &form)
    : _name(form._name), _gradeToSign(form._gradeToSign),
      _gradeToExecute(form._gradeToExecute) {
  _isSigned = form._isSigned;
}
AForm::~AForm() {}

AForm &AForm::operator=(const AForm &form) {
  if (&form != this) {
    _isSigned = form._isSigned;
  }
  return *this;
}

const string &AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }
void AForm::beSigned(const Bureaucrat &bureaucrat) {
  try {
    _checkSignGrade(bureaucrat.getGrade());
    _isSigned = true;
  } catch (std::exception &e) {
    throw;
  }
}

void AForm::beExecuted(const Bureaucrat &bureaucrat) const {
  try {
    _checkExecuteGrade(bureaucrat.getGrade());
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

std::ostream &operator<<(std::ostream &os, AForm &form) {
  os << "Form with name " << form.getName() << " requires "
     << form.getGradeToSign() << " grade to sign and "
     << form.getGradeToExecute() << " grade to execute." << std::endl;
  if (form.isSigned())
    os << "The form is signed." << std::endl;
  else
    os << "The form is not signed." << std::endl;
  return os;
}
