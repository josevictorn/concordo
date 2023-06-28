#include "./../include/System.h"
#include <iterator>

System::System() {
  
}

System::~System() {
  
}

void System::setUsers(User user) {
  this->users.push_back(user);
}

vector<User> System::getUsers() {
  return users;
}

void System::createUser(User user) {
  user.setId(this->users.size() + 1);
  
  if(this->users.size() == 0) {
    this->setUsers(user);
    cout << "Usuário criado" << endl;
  } else {
    for(int i=0; i<this->users.size(); i++) {
      if(this->users[i].getEmail() == user.getEmail()) { 
        cout << "Usuário já existe!" << endl;
      } else {
        this->setUsers(user);
        cout << "Usuário criado" << endl;
        break;
      }
    }
  }
}

void System::userLogin(string email, string password) {
  for(int i=0; i<this->users.size(); i++) {
    if(this->users[i].getEmail() == email) {
      if(this->users[i].getPassword() == password) {
        this->setLogged(this->users[i]);
        cout << "Logado como " << this->logged.getEmail() << endl;
      } else {
        cout << "Senha ou usuário inválidos!" << endl;
      }
      
      break;
    }

    if(i == this->users.size() - 1) {
      cout << "Senha ou usuário inválidos!" << endl;
    }
  }
}

void System::setServers(Server server) {
  for(int i=0; i<servers.size(); i++) {
    if(servers[i].getName() == server.getName()) {
      cout << "Servidor com esse nome já existe" << endl;
      return;
    }
  }
 
  this->servers.push_back(server);
  cout << "Servidor criado" << endl;
}

void System::setServerDescription(string name, string desc){
  for(int i=0; i<this->servers.size(); i++) {
    if(this->servers[i].getName() == name) {
      if(this->servers[i].getUserId() == this->logged.getId()) {
        this->servers[i].setDescription(desc);
        cout << "Descrição do servidor ‘" << this->servers[i].getName() << "’ modificada!" << endl;
        return;
      } else {
        cout << "Você não pode alterar a descrição de um servidor que não foi criado por você" << endl;
        return;
      }
    }
  }

  cout << "Servidor ‘"<< name <<"’ não existe" << endl;
}

void System::setServerInviteCode(string name, string code){
  for(int i=0; i<this->servers.size(); i++) {
    if(this->servers[i].getName() == name) {
      if(this->servers[i].getUserId() == this->logged.getId()) {
        this->servers[i].setInviteCode(code);
        
        if(code == "") {
          cout << "Código de convite do servidor '" << this->servers[i].getName() << "' removido!" << endl;
        } else {
          cout << "Código de convite do servidor ‘" << this->servers[i].getName() << "’ modificado!" << endl;
        }
        
        return;
      } else {
        cout << "Você não pode alterar a o código de convite de um servidor que não foi criado por você" << endl;
        return;
      }
    }
  }

  cout << "Servidor ‘"<< name <<"’ não existe" << endl;
} 

vector<Server> System::getServers() {
  return servers;
}

void System::listServers() {
  for(int i=0; i<this->servers.size(); i++) {
    cout << this->servers[i].getName() << endl;
  }
}

void System::removeServer(string name) {
  for(int i=0; i<this->servers.size(); i++) {
    if(this->servers[i].getName() == name) {
      if(this->servers[i].getUserId() == this->logged.getId()) {
        cout << "Servidor ‘" << this->servers[i].getName() << "’ removido" << endl;
        this->servers.erase(servers.begin()+i);
        return;
      } else {
        cout << "Você não é o dono do servidor '" << this->servers[i].getName() <<"'" << endl;
        return;
      }
    }
  }

  cout << "Servidor ‘"<< name <<"’ não encontrado" << endl;
}

void System::enterServer(string name, string code) {
  for(int i=0; i<this->servers.size(); i++) {
    if(this->servers[i].getName() == name) {
      if (this->servers[i].thisUserIsAParticipant(this->logged.getId())) {
        this->serverAccessed = &servers[i];
        cout << "Entrou no servidor com sucesso" << endl;
        break;
      } else if(this->logged.getId() == this->servers[i].getUserId() or this->servers[i].getInviteCode() == "" or this->servers[i].getInviteCode() == code) {
        this->servers[i].setParticipantsIds(this->logged.getId());
        this->serverAccessed = &servers[i];
        cout << "Entrou no servidor com sucesso" << endl;
        break;
      } else {
        cout << "Servidor requer código de convite" << endl;
        break;
      }
    }
  }
}

bool System::isAccessingAserver() {
  return serverAccessed != nullptr;
}

void System::leaveServer() {
  if(serverAccessed == nullptr) {
    cout << "Você não está visualizando nenhum servidor" << endl;
  } else {
    cout << "Saindo do servidor ‘" << serverAccessed->getName() <<"’" << endl;
    this->serverAccessed = nullptr;
  }
}

void System::listParticipants(){
  for(int i=0; i<this->serverAccessed->getParticipantsIds().size(); i++) {
    cout << this->users[this->serverAccessed->participantsIds[i] - 1].getName() << endl;
  }  
}

void System::setLogged(User user) {
  this->logged = user;
}

User System::getLogged() {
  return logged;
}

bool System::isLogged() {
  return this->logged.getId() != -1;
}

void System::disconnect() {
  this->logged.setId(-1);
  this->logged.setName("");
  this->logged.setEmail("");
  this->logged.setPassword("");
  this->serverAccessed = nullptr;
}
