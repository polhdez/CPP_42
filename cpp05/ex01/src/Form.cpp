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

Form::Form() : _name("Form"), _gradeToSign(150) { _isSigned = false; }

Form::Form(const string &name, const int gradeToSign)
    : _name(name), _gradeToSign(gradeToSign) {
  try {
    _checkValidFormGrade(gradeToSign);
  } catch (std::exception &e) {
    std::cout << _name << " is a invalid form because the " << e.what()
              << std::endl;
  }
  _isSigned = false;
}

Form::Form(const Form &form)
    : _name(form._name), _gradeToSign(form._gradeToSign)     {
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
void Form::beSigned(const Bureaucrat &bureaucrat) {
  try {
    _checkSignGrade(bureaucrat.getGrade());
    _isSigned = true;
  } catch (std::exception &e) {
    throw;
  }
}

std::ostream &operator<<(std::ostream &os, Form &form) {
  os << "Form with name " << form.getName() << " requires "
     << form.getGradeToSign() << " grade to sign." << std::endl;
  if (form.isSigned())
    os << "The form is signed." << std::endl;
  else
    os << "The form is not signed." << std::endl;
  return os;
}
