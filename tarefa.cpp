//
// Created by luisa on 25/07/2019.
//
#include "tarefa.h"

//Construtores da classe
Tarefa::Tarefa()
{
}
Tarefa::~Tarefa()
{
}
Tarefa::Tarefa(int io, int qo)
{
    this->ind1Op = io;
    this->qtdOperacoes = qo;
}

//Gets e sets das variaveis basicas
int Tarefa::getInd1Op()
{
    return this->ind1Op;
}
void Tarefa::setInd1Op(int io)
{
    this->ind1Op = io;
}

int Tarefa::getQtdOperacoes()
{
    return this->qtdOperacoes;
}

void Tarefa::getQtdOperacoes(int qo)
{
    this->qtdOperacoes = qo;
}
