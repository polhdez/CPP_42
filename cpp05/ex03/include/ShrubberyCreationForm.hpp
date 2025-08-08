#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

using std::string;

class ShrubberyCreationForm : public AForm {
private:
  void _createTreeFile() const;

public:
  ShrubberyCreationForm(const string &name, const string &target);
  void execute(const Bureaucrat &executor) const;
};
