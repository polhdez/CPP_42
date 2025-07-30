#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

using std::string;

class ShrubberyCreationForm : public AForm {
private:
  void _createTreeFile() const;

public:
  ShrubberyCreationForm(const string &name);
  void execute(const Bureaucrat &executor) const;
};

#endif
