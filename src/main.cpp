#include <iostream>
#include "./../include/System.h"

using namespace std;

int main(int argc, char **argv) {
  System system;
  string command;
  
	cin >> command;

  while(command != "quit") {  
    if(command == "create-user") {
      User user;
      string email;
      string password;
      string name;
      
      cin >> email;
      user.setEmail(email);
  
      cin >> password;
      user.setPassword(password);
  
      cin.ignore();
      getline(cin, name);
      user.setName(name);

      system.createUser(user);
    } else if(command == "login") {
      string email;
      string password;

      cin >> email;
      cin >> password;

      system.userLogin(email, password);
    } else if(command == "disconnect") {
      if(system.isLogged()) {
        cout << "Desconectando usuário " << system.getLogged().getEmail() << endl;
        system.disconnect();
      } else {
        cout << "Não está conectado" << endl;
      }
    } else if (system.isLogged() and command == "create-server") {
      Server server;
      string name;

      cin.ignore();
      getline(cin, name);
      
      server.setUserId(system.getLogged().getId());
      server.setName(name);
      server.setParticipantsIds(system.getLogged().getId());
      
      system.setServers(server);      
    } else if (system.isLogged() and command == "set-server-desc") {
      string nameServer;
      string desc;

      cin >> nameServer;
      cin.ignore();
      getline(cin, desc);

      size_t start = 1, end = 0;
      end = desc.find('"', start);

      if(desc.size() > end + 2) {
        cout << "Comando inválido" << endl;
        break;
      }

      desc.substr(start, end - start);
      cout << desc.substr(start, end - start) << endl;

      system.setServerDescription(nameServer, desc.substr(start, end - start));
    } else if(system.isLogged() and command == "set-server-invite-code") {
      string nameServer = "";
      string code = "";

      cin >> nameServer;
      getline(cin, code);

      code.erase(0,1);

      system.setServerInviteCode(nameServer, code);
    } else if(system.isLogged() and command == "list-servers") {
      system.listServers();
    } else if(system.isLogged() and command == "remove-server") {
      string nameServer;

      cin >> nameServer;
      system.removeServer(nameServer);
    } else if(system.isLogged() and command == "enter-server") {
      string nameServer;
      string inviteCode = "";

      cin >> nameServer;
      getline(cin, inviteCode);

      inviteCode.erase(0,1);

      system.enterServer(nameServer, inviteCode);
    } else if(system.isLogged() and system.isAccessingAserver() and command == "leave-server") {
      system.leaveServer();
    } else if(system.isLogged() and system.isAccessingAserver() and command == "list-participants") {
      system.listParticipants();
    }

    cin >> command;
  }

  cout << "Saindo do Concordo\n\n" << endl;

  cout << "----  Lista de usuários -----\n" << endl;

  for(int i=0; i<system.getUsers().size(); i++) {
    cout << "id: "<< system.getUsers()[i].getId() << endl;
    cout << "email: " << system.getUsers()[i].getEmail() << endl;
    cout << "password: " << system.getUsers()[i].getPassword() << endl;
    cout << "name: " << system.getUsers()[i].getName() << endl;
    cout << "\n";
  }

  cout << "r----  Fim da lista de usuários -----\n\n" << endl;
  cout << "----  Lista de servidores -----\n" << endl;
  

  for(int i=0; i<system.getServers().size(); i++) {
    cout << "id: "<< system.getServers()[i].getUserId() << endl;
    cout << "name: " << system.getServers()[i].getName() << endl;
    cout << "description: " << system.getServers()[i].getDescription() << endl;
    cout << "code: " << system.getServers()[i].getInviteCode() << endl;
    cout << "\n";
  }

  cout << "----  Fim da lista de servidores -----" << endl;
  
	return 0;
}