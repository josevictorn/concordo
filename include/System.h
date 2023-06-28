#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include "./../include/User.h"
#include "./../include/Server.h"

class System{
  private:
    vector<User> users; /*Este vetor de Usuários - instâncias da classe User - armazena todos os usuários cadastrados na aplicação.*/
    vector<Server> servers; /*Este vetor de Servidores - instâncias da classe Server - armazena todos os servidores cadastrados na aplicação.*/
    Server* serverAccessed = nullptr; /*Esta instância da classe Server aponta para o servidor que está sendo acessado na aplicação. Como quando iniciada nenhum servidor está sendo acessado, então, de inicio, essa variável é setada como nula.*/
    User logged; /*Esta instância da classe User armazena os dados do atual usuário logado no sistema.*/

  public:
    System();
    ~System();
    void setUsers(User user);
    vector<User> getUsers(); 
    
    /**
    * @brief Este método adiciona um novo usuário - instância da classe User - ao vetor de usuários users, que armazena os usuários do sistema.
    * @param user Uma instância da classe User com os dados do usuário a ser adicionado no sistema.
    */
    void createUser(User user);
    
    /**
    * @brief Este método autentica um usuário ao sistema, atribuindo os dados do usuário à variável logged.
    * @param email Uma string que armazena o email do usuário a ser autenticado no sistema.
    * @param password Uma string que armazena a senha do usuário a ser autenticado no sistema.
    */
    void userLogin(string email, string password);
    
    void setServers(Server server);
    vector<Server> getServers();
    
    /**
    * @brief Este método altera a descrição de um servidor.
    * @param name Uma string que armazena o nome do servidor a ser manipulado no sistema.
    * @param desc Uma string que armazena a nova descrição do servidor.
    */
    void setServerDescription(string name, string desc);
    
    /**
    * @brief Este método altera a código de acesso de um servidor.
    * @param name Uma string que armazena o nome do servidor a ser manipulado no sistema.
    * @param code Uma string que armazena o novo código de acesso do servidor.
    */
    void setServerInviteCode(string name, string code);
    
    /**
    * @brief Este método lista o nome de todos os servidores do sistema.
    */
    void listServers();
    
    /**
    * @brief Este método remove um servidor do sistema.
    * @param name Uma string que armazena o nome do servidor a ser removido do sistema.
    */
    void removeServer(string name);
    
    /**
    * @brief Este método adiciona o atual usuário logado no sistema à lista de participantes de um servidor, ou seja, concede acesso do usuário logado a um servidor específico.
    * @param name Uma string que armazena o nome do servidor em que usuário deseja entrar.
    * @param code Uma string que armazena o código de acesso do servidor que o usuário deseja entrar.
    */
    void enterServer(string name, string code);
    
    /**
    * @brief Este método verifica se há algum servidor sendo acesso no sistema.
    * @return 1 (true) caso algum servidor esteja sendo acessado, ou 0 (false) caso contrário.
    */
    bool isAccessingAserver();
    
    /**
    * @brief Este método desconecta o usuário logado do servidor que está sendo acesso.
    */
    void leaveServer();
    
    /**
    * @brief Este método lista o nome de todos os usuários que fazem parte do servidor que está sendo acessado no momento.
    */
    void listParticipants();

    void setLogged(User user);
    User getLogged(); 
    
    /**
    * @brief Este método verifica se há algum usuário autenticado no sistema.
    * @return 1 (true) caso algum usuário esteja autenticado ao sistema, ou 0 (false) caso contrário.
    */
    bool isLogged();
    
    /**
    * @brief Este método desconecta o atual usuário autenticado ao sistema.
    */
    void disconnect();
};

#endif