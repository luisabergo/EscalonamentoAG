//
// Created by luisa on 25/07/2019.
//

#ifndef ESCALONAMENTOAG_TAREFA_H
#define ESCALONAMENTOAG_TAREFA_H

using namespace std;

class Tarefa
{
private:
    int ind1Op;  //Guarda o Indice da primeira operacao da tarefa na estrutura de custos
    int qtdOperacoes;     //Quantidade de operacoes da tarefa

public:
    //Construtores da classe
    Tarefa();
    ~Tarefa();
    Tarefa(int io, int qo);

    //Gets e sets das variaveis basicas
    int getInd1Op();
    void setInd1Op(int io);

    int getQtdOperacoes();
    void getQtdOperacoes(int qo);

};

#endif //ESCALONAMENTOAG_TAREFA_H
