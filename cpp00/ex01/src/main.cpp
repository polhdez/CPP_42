#include "../includes/Phonebook.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <sstream>

std::string prompt(std::string text)
{
  std::string input;
  std::cout << text + " > ";
  std::getline(std::cin, input);
  if (std::cin.eof())
  {
    exit(EXIT_SUCCESS);
  }
  if (input == "")
    input = prompt(text);
  return input;
}

bool is_number(std::string str)
{
  for (int i = 0; i < (int)str.size(); i++)
  {
    if (!std::isdigit(str[i]))
      return false;
  }
  return true;
}

bool check_valid_phone(std::string str)
{
  if (!((char)str[0] == '+' || std::isdigit((char)str[0])))
  {
    std::cout << "[!] Invalid number!\n";
    return false;
  }
  for (int i = 1; i < (int)str.length(); i++)
  {
    if (!std::isdigit((char)str[i]))
    {
      std::cout << "[!] Invalid number!\n";
      return false;
    }
  }
  return (true);
}

void add_contact_dialog(Phonebook *phonebook)
{
  Contact contact = Contact();
  contact.setName(prompt("[ADD] Input name"));
  contact.setLastName(prompt("[ADD] Input Last Name"));
  contact.setNick(prompt("[ADD] Input Nickname"));
  std::string phone = prompt("[ADD] Input Phone Number");
  while (!check_valid_phone(phone))
    phone = prompt("[ADD] Input Phone Number");
  contact.setSecret(prompt("[ADD] Input Darkest Secret"));
  phonebook->addContact(contact);
}

void search_contact_dialog(Phonebook *phonebook)
{
  if (!phonebook->displayAll())
  {
    std::cout << "[!] No contacts found!\n";
    return;
  }
  int num;
  std::istringstream convert(prompt("[SEARCH] Select Id:"));
  if (!(convert >> num))
  {
    std::cout << "[!] Please enter a number!\n";
    search_contact_dialog(phonebook);
    return;
  }
  phonebook->displayById(num);
}

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  Phonebook phonebook = Phonebook();
  std::string input;
  while (true)
  {
    input = prompt("Enter command (ADD, SEARCH, EXIT)");
    if (input == "ADD")
      add_contact_dialog(&phonebook);
    if (input == "SEARCH")
      search_contact_dialog(&phonebook);
    if (input == "EXIT")
      exit(EXIT_SUCCESS);
  }
}
