//
// Created by luisa on 25/07/2019.
//

#ifndef ESCALONAMENTOAG_POPULACAO_H
#define ESCALONAMENTOAG_POPULACAO_H

using namespace std;

#include <vector>
#include "genotipo.h"

class Populacao
        {

    private:
        int maiorRankingTempo;
        int maiorRankingFinanceiro;
        float maiorRankingVerde;
    public:
        vector<Genotipo*> pInicial;
        vector<Genotipo*> pMutacao1;
        vector<Genotipo*> pMutacao2;
        vector<Genotipo*> pMutacao3;

            vector<Genotipo*> pFinal;

        Populacao();
        ~Populacao();

        int getMaiorRankingTempo();
    void RankingTempo();

    int getMaiorRankingFinanceiro();
    void RankingFinanceiro();
    float getMaiorRankingVerde();
    void RankingVerde();








};
#endif //ESCALONAMENTOAG_POPULACAO_H

