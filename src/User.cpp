#include "./../include/User.h"

User::User() {
  this->id = -1;
}

User::~User() {
  
}

void User::setId(int id) {
  this->id = id;
}

void User::setName(string name) {
  this->name = name;
}

void User::setEmail(string email) {
  this->email = email;
}

void User::setPassword(string password) {
  this->password = password;
}

int User::getId() {
  return id;
}

string User::getName() {
  return name;
}

string User::getEmail() {
  return email;
}

string User::getPassword() {
  return password;
}
