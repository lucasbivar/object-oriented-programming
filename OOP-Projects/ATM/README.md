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
         - DESCREVER
  
       - Consultar conta
         - Informar número da conta que deve ser consultada. Se o número da conta informada não existir, é lançada uma exceção de conta inexistente, e o gerente tem a opção de selecionar uma nova operação.
  
       - Fechar conta
         - Informar número da conta que deve ser fechada. Se o correntista só tiver essa conta, o seu cadastro também é removido da base de dados, juntamente com a conta. (IMPLEMENTAR) Se a conta informada não existir, é lançada uma exceção de conta inexistente, e o gerente tem a opção de selecionar uma nova operação.

      - Atualizar conta
        - DESCREVER

       - Listar contas
         - Lista todas as contas do banco com o saldo e algumas informações sobre elas e o correntista.

       - Listar contas de um correntista
         - Informar o nome do correntista. Com base no nome será retornado todas suas contas com o saldo e algumas informações sobre a conta e o correntista. Para realização da busca não é necessário se preocupar com letras maiúsculas/minúsculas, as comparações são feitas com tudo em minúsculo. (IMPLEMENTAR ISSO) Se não existir nenhuma conta com o nome informado, é lançada uma exceção de conta inexistente, e o gerente tem a opção de selecionar uma nova operação.

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