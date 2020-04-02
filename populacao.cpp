//
// Created by luisa on 25/07/2019.
//
#include "populacao.h"
#include <algorithm>

Populacao::Populacao()
{

}

Populacao::~Populacao()
{

}
bool comparaTempo(Genotipo* g1, Genotipo* g2)
{
    if(g1->getFitnessTempo()>=g2->getFitnessTempo())
        return false;
    else
        return true;
}
bool comparaFinanceiro(Genotipo* g1, Genotipo* g2)
{
    if(g1->getFitnessFinanceiro()>=g2->getFitnessFinanceiro())
        return false;
    else
        return true;
}
bool comparaVerde(Genotipo* g1, Genotipo* g2)
{
    if(g1->getFitnessVerde()>=g2->getFitnessVerde())
        return false;
    else
        return true;
}

int Populacao::getMaiorRankingTempo()
{
    return this->maiorRankingTempo;
}
void Populacao::RankingTempo()
{
    std::sort(pInicial.begin(), pInicial.end(), comparaTempo);

}
int Populacao::getMaiorRankingFinanceiro()
{
    return this->maiorRankingFinanceiro;
}
void Populacao::RankingFinanceiro()
{
    std::sort(pInicial.begin(), pInicial.end(), comparaFinanceiro);
}
float Populacao::getMaiorRankingVerde()
{
   return this->maiorRankingVerde;
}
void Populacao::RankingVerde()
{
    std::sort(pInicial.begin(), pInicial.end(), comparaVerde);

}
