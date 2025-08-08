#pragma once
#include "AForm.hpp"

using std::string;
class Intern {
public:
  Intern();
  Intern(const Intern &intern);
  Intern &operator=(const Intern &intern);
  ~Intern();
  const AForm* makeForm(const string& formName, const string& formTarget);
}
;
