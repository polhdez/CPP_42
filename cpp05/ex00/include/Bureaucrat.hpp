#pragma once
#include <string>

using std::string;

class Bureaucrat {
private:
  string _name;
  int _grade;

public:
  class GradeTooHighException : public std::exception {
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
    const char *what() const throw();
  };
  Bureaucrat();
  Bureaucrat(string name, int grade);
  Bureaucrat(const Bureaucrat &bureaucrat);
  ~Bureaucrat();
  Bureaucrat &operator=(const Bureaucrat &bureaucrat);
  const string &getName() const;
  int getGrade() const;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat &bureaucrat);
