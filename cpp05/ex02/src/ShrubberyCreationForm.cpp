#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

using std::string;

void ShrubberyCreationForm::_createTreeFile() const {
  string fileName = getTarget() + "_shrubbery";
  std::cout << "Creating tree file with name: " << fileName << std::endl;
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

ShrubberyCreationForm::ShrubberyCreationForm(const string &name,
                                             const string &target)
    : AForm(name, target, 145, 137) {}

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
