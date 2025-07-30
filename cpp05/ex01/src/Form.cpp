#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

using std::string;

const char *Form::GradeTooHighException::what() const throw() {
  return "grade was set too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "grade was set too low!";
}

void Form::_checkValidFormGrade(int grade) const {
  if (grade > 150)
    throw Form::GradeTooLowException();
  if (grade < 1)
    throw Form::GradeTooHighException();
}

void Form::_checkSignGrade(int grade) const {
  if (grade > _gradeToSign)
    throw Form::GradeTooLowException();
  if (grade < 1)
    throw Form::GradeTooHighException();
}

void Form::_checkExecuteGrade(int grade) const {
  if (grade > _gradeToExecute)
    throw Form::GradeTooLowException();
  if (grade < 1)
    throw Form::GradeTooHighException();
}

Form::Form() : _name("Form"), _gradeToSign(150), _gradeToExecute(150) {
  _isSigned = false;
}

Form::Form(const string &name, const int gradeToSign, const int gradeToExecute)
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

Form::Form(const Form &form)
    : _name(form._name), _gradeToSign(form._gradeToSign),
      _gradeToExecute(form._gradeToExecute) {
  _isSigned = form._isSigned;
}
Form::~Form() {}

Form &Form::operator=(const Form &form) {
  if (&form != this) {
    _isSigned = form._isSigned;
  }
  return *this;
}

const string &Form::getName() const { return _name; }
bool Form::isSigned() const { return _isSigned; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }
void Form::beSigned(const Bureaucrat &bureaucrat) {
  try {
    _checkSignGrade(bureaucrat.getGrade());
    _isSigned = true;
  } catch (std::exception &e) {
    throw;
  }
}

void Form::beExecuted(const Bureaucrat &bureaucrat) const {
  try {
    _checkExecuteGrade(bureaucrat.getGrade());
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

std::ostream &operator<<(std::ostream &os, Form &form) {
  os << "Form with name " << form.getName() << " requires "
     << form.getGradeToSign() << " grade to sign and "
     << form.getGradeToExecute() << " grade to execute." << std::endl;
  if (form.isSigned())
    os << "The form is signed." << std::endl;
  else
    os << "The form is not signed." << std::endl;
  return os;
}
