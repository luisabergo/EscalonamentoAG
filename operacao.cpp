//
// Created by luisa on 25/07/2019.
//

#include "operacao.h"

//Construtores da classe
Operacao::Operacao()
{
}

Operacao::~Operacao()
{
}

Operacao::Operacao(int idT, int qtdM, int nct, int ids, int ido)
{
    idTarefa = idT;
    qtdMaquinas = qtdM;
    idSequencial = ids;
    idOperacao = ido;
}
//Gets e sets das variaveis basicas
int Operacao::getIdTarefa()
{
    return idTarefa;
}
void Operacao::setIdTarefa(int idT)
{
    idTarefa = idT;
}
int Operacao::getIdOperacao()
{
    return idOperacao;
}
void Operacao::setIdOperacao(int idO)
{
    idOperacao = idO;
}

int Operacao::getQtdMaquinas()
{
    return qtdMaquinas;
}
void Operacao::setQtdMaquinas(int qtdM)
{
    qtdMaquinas = qtdM;
}

void Operacao::insereCusto(Custo* c, int idClasse, int idMaquina)
{
    estruturaCustos[idClasse].insert(estruturaCustos[idClasse].begin() + idMaquina, c);

}
int Operacao::getIdSequencial()
{
    return idSequencial;
}
void Operacao::setIdSequencial(int idS)
{
    idSequencial = idS;
}

