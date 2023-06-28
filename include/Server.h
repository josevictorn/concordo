#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <vector>

using namespace std;

class Server{
  private:
    int userId; /*Esta variável do tipo inteiro armazena o ID do usuário criador do servidor.*/
    string name; /*Esta variável do tipo string armazena o nome do servidor.*/
    string description; /*Esta variável do tipo string armazena a descrição do servidor.*/
    string inviteCode; /*Esta variável do tipo string armazena o código de acesso ao servidor.*/

  public:
    Server();
    ~Server();
    vector<int> participantsIds; /*Este vetor de inteiros armazena os ID's dos usuários que são participantes do servidor.*/

    void setUserId(int id);
    int getUserId();
    void setName(string name);
    string getName();
    void setDescription(string desc);
    string getDescription();
    void setInviteCode(string code);
    string getInviteCode();
    void setParticipantsIds(int userId);
    vector<int> getParticipantsIds();

    /**
    * @brief Este método verifica se um usuário específico faz parte do servidor em questão.
    * @param userId Um inteiro que indica o ID do usuário a ser verificado na lista de participantes do servidor.
    * @return 1 (true) caso o usuário faça parte do servidor, ou 0 (false) caso contrário.
    */
    bool thisUserIsAParticipant(int userId);
};

#endif