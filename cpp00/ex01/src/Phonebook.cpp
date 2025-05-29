#include <cstring>
#include <ostream>
#include <iostream>
#include "../includes/Phonebook.hpp"

Phonebook::Phonebook(void)
{
  last_contact_id = -1;
  n_entries = 0;
}

void Phonebook::addContact(Contact contact)
{
  if (last_contact_id >= list_size - 1)
    last_contact_id = 0;
  else
    last_contact_id += 1;
  contact.setId(last_contact_id);
  contacts[last_contact_id] = contact;
  if (n_entries < list_size)
    n_entries++;
}
void Phonebook::displayById(int id)
{
  if (id > n_entries)
    std::cout << "[!] Id doesn't match any existing contact!\n";
  else
    contacts[id].printInfo();
}
bool Phonebook::displayAll(void)
{
  if (!n_entries)
    return false;
  for (int i = 0; i < n_entries; i++)
  {
    contacts[i].printRow();
  }
  return true;
}
