cmake_minimum_required(VERSION 3.14)
project(EscalonamentoAG)

set(CMAKE_CXX_STANDARD 14)

add_executable(EscalonamentoAG main.cpp instancia.h instancia.cpp operacao.h operacao.cpp custo.cpp custo.h tarefa.h tarefa.cpp genotipo.h genotipo.cpp populacao.h populacao.cpp)