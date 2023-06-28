#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User{
  private:
    int id; /* Esta variável inteira armazena o ID do usuário.*/
    string name; /* Esta variável do tipo string armazena o nome do usuário.*/
    string email; /* Esta variável do tipo string armazena o email do usuário.*/
    string password; /* Esta variável do tipo string armazena a senha do usuário.*/

  public:
    User();
    ~User();
    void setId(int id);
    void setName(string name);
    void setEmail(string email);
    void setPassword(string password);
    int getId();
    string getName();
    string getEmail();
    string getPassword();
};

#endif