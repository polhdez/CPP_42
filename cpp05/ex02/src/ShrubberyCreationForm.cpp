#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

using std::string;

void ShrubberyCreationForm::_createTreeFile() const {
  string fileName = getName() + "_shrubbery";
  std::ofstream file(fileName.data());
  file << "              * *    \n\
              *    *  *\n\
           *  *    *     *  *\n\
      *    *  *    *\n\
     * *   *    *    *    *   *\n\
 *     *  *    * * .#  *   *\n\
 *   *     * #.  .# *   *\n\
   *     \"#.  #: #\" * *    *\n\
 *   * * \"#. ##\"       *\n\
   *       \"###\n\
             \"##\n\
              ##.\n\
              .##:\n\
              :###\n\
              ;###\n\
            ,####.\n\
/\\/\\/\\/\\/\\/.######.\\/\\/\\/\\/\\"
       << std::endl;
  file.close();
}

ShrubberyCreationForm::ShrubberyCreationForm(const string &name)
    : AForm(name, 145, 137) {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {

  try {
    if (!isSigned())
      throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
      throw GradeTooLowException();
    else
      _createTreeFile();
  } catch (std::exception &e) {
    std::cout << executor.getName() << " couldn't execute form " << getName()
              << " because " << e.what() << std::endl;
  }
}
