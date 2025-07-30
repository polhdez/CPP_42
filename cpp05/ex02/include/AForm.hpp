#ifndef AFORM_HPP
#define AFORM_HPP
#include <string>

using std::string;

class Bureaucrat;

class AForm {
private:
  const string _name;
  const int _gradeToSign;
  const int _gradeToExecute;
  bool _isSigned;
  void _checkValidFormGrade(int grade) const;
  void _checkSignGrade(int grade) const;
  void _checkExecuteGrade(int grade) const;

public:
  class GradeTooHighException : public std::exception {
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
    const char *what() const throw();
  };
  class FormNotSignedException : public std::exception {
    const char *what() const throw();
  };
  AForm();
  AForm(const string &name, const int gradeToSign, const int gradeToExecute);
  AForm(const AForm &form);
  ~AForm();
  AForm &operator=(const AForm &form);
  const string &getName() const;
  bool isSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;
  void beSigned(const Bureaucrat &bureaucrat);
  void beExecuted(const Bureaucrat &bureaucrat) const;
  virtual void execute(const Bureaucrat &executor) const = 0;
};
std::ostream &operator<<(std::ostream &os, AForm &form);
#endif
