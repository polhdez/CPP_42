#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

using std::string;

class RobotomyRequestForm : public AForm {
private:
  void _robotomize() const;

public:
  RobotomyRequestForm(const string &name, const string &target);
  void execute(const Bureaucrat &executor) const;
};

#endif
