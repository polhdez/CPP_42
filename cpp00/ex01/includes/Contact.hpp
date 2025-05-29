#include <string>

class Contact
{
private:
  int id;
  std::string name;
  std::string last_name;
  std::string nick;
  std::string phone_number;
  std::string darkest_secret;

  void printField(std::string str, int width);

public:
  Contact();
  void printRow(void);
  void printInfo(void);

  // Setters
  void setId(int contact_id);
  void setName(std::string str);
  void setLastName(std::string str);
  void setNick(std::string str);
  void setPhone(std::string str);
  void setSecret(std::string str);

  // Getters
  std::string getName(void);
  std::string getLastName(void);
  std::string getNick(void);
  std::string getPhone(void);
  std::string getSecret(void);
};
