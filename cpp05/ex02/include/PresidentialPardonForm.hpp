#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

using std::string;

class PresidentialPardonForm : public AForm {
private:
  void _pardon() const;

public:
  PresidentialPardonForm(const string &name);
  void execute(const Bureaucrat &executor) const;
};

#endif
