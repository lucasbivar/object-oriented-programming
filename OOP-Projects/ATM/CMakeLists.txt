cmake_minimum_required(VERSION 3.0.0)
project(ATM VERSION 0.1.0)

set(CMAKE_BUILD_TYPE Relase)
set(QTCP_PROJECT_DIR ${PROJECT_SOURCE_DIR})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

add_executable(ATM src/main.cpp 
                src/Banco/Banco.cpp
                src/Transacao/Transacao.cpp
                src/Conta/ContaCorrente.cpp src/Conta/ContaCorrenteLimite.cpp src/Conta/ContaPoupanca.cpp
                src/Pessoa/PessoaFisica.cpp src/Pessoa/PessoaJuridica.cpp)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/database/dataBase.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
