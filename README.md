
# Concordo

Esse projeto é um sistema com recursos similares ao Discord, porém vai funcionar somente em modo texto e sem recursos de rede.

O sistema é operado através de comandos de uma única linha, compostos por um nome, seguido de parâmetros.

## Funcionalidades

- criar um usuário com nome, e-mail e senha;
- autenticação de usuários;
- sair do sistema;
- desconectar da aplicaçao;
- criar servidores;
- mudar descrição de servidores;
- setar código de convite para um servidor;
- listar servidores do sistema;
- remover um servidor;
- entrar em um servidor;
- sair de um servidor;
- listar membros de um servidor;

## Tecnologias utilizadas

- C++;
- Cmake;

## Comandos

#### Sair do sistema

```bash
  quit
```

#### Criar um usuário

```bash
  create-user <email> <senha_sem_espaços> <nome com espaços>
```
| Parâmetro   | Tipo       | Descrição                           |
| :---------- | :--------- | :---------------------------------- |
| `email` | `string` | **Obrigatório e não deve contér espaços**. O email que deve ser atribuido ao usuário. |
| `password` | `string` | **Obrigatório e não deve contér espaços**. A senha que usuário usará para entrar no sistema. |
| `name` | `string` | **Obrigatório**. O nome do usuário no sistema. |

#### Entrar no sistema

```bash
  login <email> <senha>
```
| Parâmetro   | Tipo       | Descrição                           |
| :---------- | :--------- | :---------------------------------- |
| `email` | `string` | **Obrigatório e não deve contér espaços**. O email utilizado para cadastrar o usuário. |
| `password` | `string` | **Obrigatório e não deve contér espaços**. A senha utilizada para cadastrar o usuário. |

#### Desconectar do Concorda

```bash
  disconnect
```

#### Criar servidores

```bash
  create-server <name>
```

| Parâmetro   | Tipo       | Descrição                                   |
| :---------- | :--------- | :------------------------------------------ |
| `name`      | `string` | **Obrigatório e não deve contér espaços**. O nome do servidor. |

#### Mudar a descrição de um servidor

```bash
  set-server-desc <name> "<description>"
```

| Parâmetro   | Tipo       | Descrição                           |
| :---------- | :--------- | :---------------------------------- |
| `name` | `string` | **Obrigatório e não deve contér espaços**. O nome do servidor que deseja alterar a descrição. |
| `description` | `string` | **Obrigatório**. A nova descrição que deseja atribuir ao servidor. |

#### Setar código de acesso para um servidor

```bash
  set-server-invite-code <name> <code>
```

| Parâmetro   | Tipo       | Descrição                           |
| :---------- | :--------- | :---------------------------------- |
| `name` | `string` | **Obrigatório e não deve contér espaços**. O nome do servidor que deseja alterar o código de acesso. |
| `code` | `string` | **Obrigatório**. O novo código de acesso que deseja atribuir ao servidor. |

#### Listar servidores

```bash
  list-servers
```

#### Remover servidor

```bash
  remove-server <name>
```

| Parâmetro   | Tipo       | Descrição                                   |
| :---------- | :--------- | :------------------------------------------ |
| `name`      | `string` | **Obrigatório**. O nome do servidor a ser removido. |

#### Entrar em um servidor

```bash
  enter-server <name>
```

| Parâmetro   | Tipo       | Descrição                                   |
| :---------- | :--------- | :------------------------------------------ |
| `name`      | `string` | **Obrigatório**. O nome do servidor que o usuário deseja entrar. |

#### Sair do servidor acessado

```bash
  leave-server
```

#### Lista participantes do servidor acessado

```bash
  list-participants
```

## Execução do projeto

```bash
#clone o projeto e acesse a pasta
$ git clone https://github.com/josevictorn/concordo.git
$ cd concorde

# Crie e acesse a pasta build
$ mkdir build
$ cd build

# Gere o execultável com o Cmake
$ cmake..
$ make

# Execute o programa
$ ./program

# Você pode execultar o programa através de um script com o comando
$ ./program < [nome_do_script].txt
```

## Credenciais do autor

- Nome: Jose Victor do Nascimento Ferreira
- Matricula na UFRN: 20220037248
- Github: [@josevictorn](https://github.com/josevictorn)
