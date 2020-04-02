//
// Created by luisa on 25/07/2019.
//

#ifndef ESCALONAMENTOAG_INSTANCIA_H
#define ESCALONAMENTOAG_INSTANCIA_H

using namespace std;

#include <vector>
#include "tarefa.h"
#include "operacao.h"


class Instancia
{
private:
    int nTarefas;  //Numero de tarefas a serem escalonadas
    int nMaquinas;//Numero de maquinas envolvidas no escalonamento
    int nClassesTrab; // numero de classes de trabalhadores
    int totalOperacoes; // número total de operacoes de todo o escalonamento
    int totalLeituraMaquinas; //somatorio dos valores de vetQtdMaqPorOperacao (total de maquinas a serem lidas)
public:
    //variaveis publicas (retornar em funcoes publicas)
    vector<int> vetQtdOperacoes; //para cada tarefa, numero de operacoes
    //IMPORTANTE : O TAMANHO DESSE  VETOR É nTarefas e seu somatorio é totalOperacoes
    vector<int> vetQtdMaqPorOperacao; //para cada operacao, quantidade de maquinas que podem executa-la
    //IMPORTANTE : O TAMANHO DESSE  VETOR É totalOperacoes e seu somatorio é totalLeituraMaquinas
    vector<vector<int>> vetvetMaquinasPorOperacao; //para armazenar o ID das maquinas que podem executar uma dada operacao
    //IMPORTANTE: Uma dimensao vale totalOperacoes e a outra é o valor em vetQtdMaqPorOperacao

    vector<Tarefa*> controleTarefas; //Lista com valores dos indices de inicio e fim da tarefa
    vector<Operacao*> custosPorOpMaqClass; //Lista com estrutura de custos por OperacaoxMaquinaxClassedeTrabalhador

    //funcoes publicas
    Instancia();  //Construtor
    Instancia(int n, int nm, int nc);//Construtor da classe inicializando variáveis principais
    ~Instancia(); //Destrutor


    int getNTarefas();
    void setNTarefas(int nt);

    int getNMaquinas();
    void setNMaquinas(int nm);

    int getNClassesTrab();
    void setNClassesTrab(int nct);

    int getNTotalOps();
    void setNTotalOps(int nto);

    int getNTotalLeituraMaqs();
    void setNTotalLeituraMaqs(int ntlm);

};

#endif //ESCALONAMENTOAG_INSTANCIA_H
