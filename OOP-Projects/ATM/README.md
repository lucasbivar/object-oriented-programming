# Como executar o projeto?

1º - Abrir o terminal na pasta do projeto

2º - Instalar o CMake
  - `sudo apt install cmake`

3º - Criar pasta build e entrar nela
  - `mkdir build && cd build`

4º - Executar o CMake apontando para o diretório anterior
  - `cmake ..`

5º - Compilar o projeto
  - `make`

6º - Testar o binário final
  - `./ATM`

# Sobre a interface do projeto

## O IFBank conta com duas visões:
  1. **Gerente**
       - Abrir conta
         - Se o usuário já tiver uma conta no banco não é necessário pedir novamente todos os dados do correntista, apenas o nome, esse será comparado com os nomes que estão presente na base de correntistas, ignorando letras maiúsculas e minúsculas. Uma vez que foi encontrado os dados de um correntista com o mesmo nome, será pedido apenas o tipo de conta que se deseja abrir e suas determinadas informações. Se não for encontrado nenhum correntista com o nome digitado, o gerente tem a opção de tentar novamente ou cancelar a operação com "-1" e retornar para sua tela principal. No caso do usuário não ter conta no banco, será pedido todos os dados do correntista e os dados referentes ao tipo de conta que ele quer criar.
  
       - Consultar conta
         - Informar o número da conta que deve ser consultada. Se o número da conta informada não existir, é lançada uma exceção de conta inexistente, e o gerente tem a opção de selecionar uma nova operação.
  
       - Fechar conta
         - Informar o número da conta que deve ser fechada. Se o correntista só tiver essa conta, o seu cadastro também é removido da base de dados dos correntistas, juntamente com a conta. Se a conta informada não existir, é lançada uma exceção de conta inexistente, e o gerente tem a opção de selecionar uma nova operação.

      - Atualizar conta
        - Informar o número da conta que deve ser atualizada. Se ela existir, será perguntado atributo por atributo se o usuário deseja editar. Se não, será lançada uma exceção de conta inexistente.

       - Listar contas
         - Lista todas as contas do banco com o saldo e algumas informações sobre elas e o correntista.

       - Listar contas de um correntista
         - Informar o nome do correntista. Com base no nome será retornado todas suas contas com o saldo e algumas informações sobre a conta e o correntista. Para realização da busca não é necessário se preocupar com letras maiúsculas/minúsculas, as comparações são feitas com tudo em minúsculo. Se não existir nenhuma conta com o nome informado, é lançada uma exceção de conta inexistente, e o gerente tem a opção de selecionar uma nova operação.

       - Sair do programa
         - O programa é encerrado.
  

  2. **Correntista**
       - Inicialmente é pedido o número da conta até que um número de conta existente seja digitado. Para fins de teste, o programa começa com uma base de dados fictícia. Dessa forma, se não tiver criado uma conta na visão do gerente, segue um número da conta presente na base de dados para você testar: `2120210610091532` 

       - Após entrar com um número de conta válido, temos as seguintes operações:
          - Depositar
            - Informar o valor do depósito, se for um valor inválido, uma exceção é lançada e é pedido para o correntista escolher uma nova operação
  
          - Retirar
            - Informar o valor da retirada, se for um valor inválido, uma exceção é lançada e é pedido para o correntista escolher uma nova operação. Na conta poupança e na conta corrente, um valor é válido se não exceder o saldo, já na conta corrente se não exceder o saldo + limite.
  
          - Transferir
            - Informar o número da conta destino e o valor. Se o valor for inválido, usando os mesmos critérios da operação de retirada, é lançada uma exceção. Se a conta destino não existir, é lançada uma exceção de conta inexistente. Se uma das exceções forem lançadas, é pedido que o correntista escolha uma nova operação.
  
          - Saldo
            - É exibido na tela o saldo do correntista e algumas informações sobre sua conta.
  
          - Extrato
            - É exibido na tela algumas informações sobre sua conta, o saldo e as 30 últimas transações realizadas na presente conta.
  
          - Sair da conta
            - Ao sair da conta é pedido novamente para digitar o número de uma conta ou -1 para terminar o programa.

## Algumas informações sobre os dados no arquivo de texto
  - Indicação do tipo de dado em cada linha:
      - PF -> Pessoa Fisica
      - PJ -> Pessoa Juridica
      - C -> Conta
      - T -> Transacao


  - Metadados Do Número da Conta:
    - Ex.: 2120210610091532
        - 2    -> Prefixo Tipo De Conta  (1 - Conta Corrente; 2 - Conta Corrente Com Limite; 3 - Conta Poupança);
        - 1    -> Prefixo Tipo de Pessoa (1 - Pessoa Física;  2 - Pessoa Jurídica);
        - 2021 -> Ano que a conta foi criada
        - 06   -> Dia que a conta foi criada
        - 10   -> Mês que a conta foi criada
        - 09   -> Segundo que a conta foi criada;
        - 15   -> Hora que a conta foi criada;
        - 32   -> Minuto que a conta foi criada;