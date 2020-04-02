//
// Created by luisa on 25/07/2019.
//

#ifndef ESCALONAMENTOAG_GENOTIPO_H
#define ESCALONAMENTOAG_GENOTIPO_H

using namespace std;
#include "instancia.h"

class Genotipo
{
private:
    //o tamanho dos 3 vetores será o numero de operações total
    int nOperacoes; //Numero de operacoes total
    int fitnessTempo; // Custo total de tempo após montar solução no tempo
    int fitnessFinanceiro; // custo total de gastos financeiros após montar solucao no tempo
    float fitnessVerde; // custo total de impacto ambiental e social ao montar solucoes no tempo
    int* seqOp; //Vetor que guarda informaçao da ordem que as operações serão escalonadas
    int* idMaq; //Vetor que guarda informações de qual maquina ira executar qual operação
    int* idClasses; //Vetor que guarda informações de qual classe de trabalhadores ira executar qual operação
    int* tempoFinalMaquinas; //vetor com estrutura de buffer com os tempos de cada uma das maquinas

public:
    //Construtores da classe
    Genotipo();
    ~Genotipo();
    Genotipo(int nOp, int nmaquinas);

    //setar os valores fitness da solucao
    void setFitness(int financeiro, int verde);

    void setMakeSpan(int ct);

    int getFitnessTempo();

    int getFitnessFinanceiro();

    float getFitnessVerde();

    int getSeqOp(int indice);

    void setSeqOp(int s[], int nOperacoes);

    int getIdMaq(int indice);

    void setIdMaq(int s[], int nOperacoes);

    void setIdMaq(int indice, int valor);

    int getIdClasses(int indice);

    void setIdClasses(int s[], int nOperacoes);

    void setIdClasses(int indice, int valor);

    //construir solucao do zero com heuristica
    void ConstroiH(Instancia * dados);

    bool verificaViabilidade(Instancia * dados);

    void calculaFitness(Instancia * dados);

    void calculaMakeSpan(Instancia * dados);

    void MutacaoClasse(Instancia * dados);

    void MutacaoMaquina(Instancia * dados);

    void MutacaoOperacao(Instancia * dados);

    void AlgGenetico();

};

#endif //ESCALONAMENTOAG_GENOTIPO_H
