#include <iostream>
#include <string>
#include <sstream>
#include "../includes/Contact.hpp"

void Contact::printField(std::string str, int width)
{
  if ((int)str.length() > width)
    std::cout << str.substr(0, width - 1) + ".";
  else
  {
    while ((int)str.length() < width)
      str = " " + str;
    std::cout << str;
  }
  return;
}

Contact::Contact()
{
  id = 0;
  name = "";
  last_name = "";
  nick = "";
  phone_number = "";
  darkest_secret = "";
}

void Contact::printRow(void)
{
  std::stringstream ss;
  ss << id;
  printField(ss.str(), 10);
  std::cout << "|";
  printField(name, 10);
  std::cout << "|";
  printField(last_name, 10);
  std::cout << "|";
  printField(nick, 10);
  std::cout << "\n";
}

void Contact::printInfo(void)
{
  std::stringstream ss;
  ss << id;
  std::cout << "Id: " + ss.str() + "\n";
  std::cout << "Name: " + name + "\n";
  std::cout << "Last Name: " + last_name + "\n";
  std::cout << "Nickname: " + nick + "\n";
  std::cout << "Phone Number: " + phone_number + "\n";
  std::cout << "Darkest Secret: " + darkest_secret + "\n";
}

// Setters
void Contact::setId(int contact_id) { id = contact_id; }
void Contact::setName(std::string str) { name = str; }
void Contact::setLastName(std::string str) { last_name = str; }
void Contact::setNick(std::string str) { nick = str; }
void Contact::setPhone(std::string str) { phone_number = str; }
void Contact::setSecret(std::string str) { darkest_secret = str; }

// Getters
std::string Contact::getName(void) { return name; }
std::string Contact::getLastName(void) { return last_name; }
std::string Contact::getNick(void) { return nick; }
std::string Contact::getPhone(void) { return phone_number; }
std::string Contact::getSecret(void) { return darkest_secret; }
