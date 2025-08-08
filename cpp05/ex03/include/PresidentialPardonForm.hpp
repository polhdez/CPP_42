#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

using std::string;

class PresidentialPardonForm : public AForm {
private:
  void _pardon() const;

public:
  PresidentialPardonForm(const string &name, const string &target);
  void execute(const Bureaucrat &executor) const;
};
