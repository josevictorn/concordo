#include "./../include/Server.h"

Server::Server() {
  
}

Server::~Server() {
  
}

void Server::setUserId(int id) {
  this->userId = id;
}

int Server::getUserId() {
  return userId;
}

void Server::setName(string name) {
  this->name = name;
}

string Server::getName() {
  return name;
}

void Server::setDescription(string desc) {
  this->description = desc;
}

string Server::getDescription() {
  return description;
}

void Server::setInviteCode(string code) {
  this->inviteCode = code;
}

string Server::getInviteCode() {
  return inviteCode;
}

void Server::setParticipantsIds(int userId) {
  this->participantsIds.push_back(userId);
}

vector<int> Server::getParticipantsIds() {
  return participantsIds;
}

bool Server::thisUserIsAParticipant(int userId) {
  for(int i=0; i<participantsIds.size(); i++) {
    if(participantsIds[i] == userId) {
      return true;
    }
  }

  return false;
}