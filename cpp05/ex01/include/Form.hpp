#pragma once
#include <string>

using std::string;

class Bureaucrat;

class Form {
private:
  const string _name;
  const int _gradeToSign;
  bool _isSigned;
  void _checkValidFormGrade(int grade) const;
  void _checkSignGrade(int grade) const;

public:
  class GradeTooHighException : public std::exception {
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
    const char *what() const throw();
  };
  Form();
  Form(const string &name, const int gradeToSign);
  Form(const Form &form);
  ~Form();
  Form &operator=(const Form &form);
  const string &getName() const;
  bool isSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;
  void beSigned(const Bureaucrat &bureaucrat);
  void beExecuted(const Bureaucrat &bureaucrat) const;
};

std::ostream &operator<<(std::ostream &os, Form &form);
