//
// Created by luisa on 25/07/2019.
//
#include "instancia.h"
#include "operacao.h"
#include <stdlib.h>
#include <random>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>

Instancia::Instancia()
{


}

Instancia::~Instancia()
{

}

Instancia::Instancia(int n, int nm, int nc)
{
    this->nTarefas = n;
    this->nMaquinas = nm;
    this->nClassesTrab = nc;

}

void Instancia::setNTarefas(int nt)
{
    this->nTarefas = nt;
}

int Instancia::getNTarefas()
{
    return this->nTarefas;

}

void Instancia::setNMaquinas(int nm)
{
    this->nMaquinas = nm;
}

int Instancia::getNMaquinas()
{
    return this->nMaquinas;
}

void Instancia::setNClassesTrab(int ntc)
{
    this->nClassesTrab = ntc;
}

int Instancia::getNClassesTrab()
{
    return this->nClassesTrab;
}

void Instancia::setNTotalOps(int nto)
{
    this->totalOperacoes = nto;
}

int Instancia::getNTotalOps()
{
    return this->totalOperacoes;
}
int Instancia::getNTotalLeituraMaqs()
{
    return this->totalLeituraMaquinas;
}

void Instancia::setNTotalLeituraMaqs(int ntlm)
{
    this->totalLeituraMaquinas = ntlm;
}



