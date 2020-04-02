//
// Created by luisa on 25/07/2019.
//

#include "custo.h"

Custo::Custo()
{


}

Custo::~Custo()
{

}

Custo::Custo(int cf, int ct, float ce, float b, float r, float s)
{
    this->custoFinanceiro = cf;
    this->custoTempo = ct;
    this->consumoEnergia = ce;
    this->barulho = b;
    this->reciclagem = r;
    this->seguranca = s;
    this->custoVerde = ce+b+r+s;

}
int Custo::getCustoFinanceiro()
{
    return this->custoFinanceiro;
}

void Custo::setCustoFinanceiro(int cf)
{
    this->custoFinanceiro = cf;
}

int Custo::getCustoTempo()
{
    return this->custoTempo;
}

void Custo::setCustoTempo(int ct)
{
    this->custoTempo = ct;
}

float Custo::getConsumoEnergia()
{
    return this->consumoEnergia;
}
void Custo::setConsumoEnergia(float ce)
{
    this->consumoEnergia = ce;
}

float Custo::getBarulho()
{
    return this->barulho;
}

void Custo::setBarulho(float b)
{
    this->barulho = b;
}

float Custo::getReciclagem()
{
    return this->reciclagem;
}
void Custo::setReciclagem(float r)
{
    this->reciclagem = r;
}

float Custo::getSeguranca()
{
    return this->seguranca;
}
void Custo::setSeguranca(float s)
{
    this->seguranca = s;
}

float Custo::getCustoVerde()
{
    return this->custoVerde;
}
void Custo::setCustoVerde(float cv)
{
    this->custoVerde = cv;
}

void Custo::calculaCustoVerde()
{

}