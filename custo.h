//
// Created by luisa on 25/07/2019.
//

#ifndef ESCALONAMENTOAG_CUSTO_H
#define ESCALONAMENTOAG_CUSTO_H

using namespace std;

#include <vector>
class Custo
{
    //Custos do processamento de uma operação em determinada máquina e determinada classe
private:
    int custoFinanceiro;  //Custo financeiro
    int custoTempo; //Custo de tempo
    float consumoEnergia; //Consumo de Energia
    float barulho;   //Barulho que a operaçao ira fazer
    float reciclagem; //Reciclagem das Ferramentas
    float seguranca; //Segurança na operação
    float custoVerde; //Custo de questões ecológicas condensadas em apenas um indicador

public:
    Custo();
    ~Custo();
    Custo(int cf, int ct, float ce, float b, float r, float s);
    int getCustoFinanceiro();
    void setCustoFinanceiro(int cf);

    int getCustoTempo();
    void setCustoTempo(int ct);

    float getConsumoEnergia();
    void setConsumoEnergia(float ce);

    float getBarulho();
    void setBarulho(float b);

    float getReciclagem();
    void setReciclagem(float r);

    float getSeguranca();
    void setSeguranca(float s);

    float getCustoVerde();
    void setCustoVerde(float cv);

    void calculaCustoVerde();

};

#endif //ESCALONAMENTOAG_CUSTO_H
