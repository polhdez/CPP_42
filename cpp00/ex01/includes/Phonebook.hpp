#include <cstring>
#include "Contact.hpp"

class Phonebook
{
private:
  static const int list_size = 8;
  int n_entries;
  int last_contact_id;
  Contact contacts[list_size];

public:
  Phonebook(void);
  void addContact(Contact contact);
  void displayById(int id);
  bool displayAll(void);
};
