//
// Created by luisa on 25/07/2019.
//

#ifndef ESCALONAMENTOAG_OPERACAO_H
#define ESCALONAMENTOAG_OPERACAO_H

using namespace std;
#include <vector>
#include "custo.h"

class Operacao
{
private:
    int idTarefa;  //Guarda o Indice da tarefa da qual a operacao faz parte
    int idOperacao; //ID da operacao
    int idSequencial; //ID unico que toma como referencia o numero de operacoes
    int qtdMaquinas;     //Quantidade de maquinas que podem realizar a tarefa



public:
    vector<Custo*> estruturaCustos[3];

    //primeiro :  <Classe de trabalhador<Maquina<Custo*>>>
    //classe de trabalhador tem numero fixo.


    //Construtores da classe
    vector<int> vetMaq; //Guarda o ID das maquinas que podem executar a operacao
    Operacao();
    ~Operacao();
    Operacao(int idT, int qtdM, int nct, int ids, int ido);

    //Gets e sets das variaveis basicas
    int getIdTarefa();
    void setIdTarefa(int idT);

    int getIdOperacao();
    void setIdOperacao(int idO);


    int getQtdMaquinas();
    void setQtdMaquinas(int qtdM);

    int getIdSequencial();
    void setIdSequencial(int idS);



    //Funcao para pushback de 6 custos Custo* dentro da estrutura
    void insereCusto(Custo* c, int idClasse, int idMaquina);

};


#endif //ESCALONAMENTOAG_OPERACAO_H
