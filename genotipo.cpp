//
// Created by luisa on 25/07/2019.
//

#include "genotipo.h"
#include <stdlib.h>
#include <random>
#include <iostream>

//Construtores da classe
Genotipo::Genotipo()
{
}
Genotipo::~Genotipo()
{
   delete seqOp;
    delete idMaq;
    delete idClasses;
    delete  tempoFinalMaquinas;
}

Genotipo::Genotipo(int nOp, int nmaquinas)
{
    seqOp = new int[nOp];
    idMaq = new int[nOp];
    idClasses = new int[nOp];
    tempoFinalMaquinas = new int[nmaquinas];
    this->nOperacoes = nOp;

}

int Genotipo::getNOperacoes()
{
    return this->nOperacoes;
}

void Genotipo::setNOperacoes(int nops)
{
    this->nOperacoes = nops;

}

void Genotipo::setFitness(int financeiro, int verde)
{
    fitnessFinanceiro = financeiro;
    fitnessVerde = verde;

}
void Genotipo::setMakeSpan(int ct)
{
    fitnessTempo = ct;
}
int Genotipo::getFitnessTempo()
{
    return this->fitnessTempo;
}

void Genotipo::setFitnessTempo(int ft)
{
    this->fitnessTempo = ft;
}

int Genotipo::getFitnessFinanceiro()
{
    return this->fitnessFinanceiro;
}

void Genotipo::setFitnessFinanceiro(int ff)
{
    this->fitnessFinanceiro = ff;
}

float Genotipo::getFitnessVerde()
{
    return this->fitnessVerde;
}

void Genotipo::setFitnessVerde(int fv)
{
    this->fitnessTempo = fv;
}

int* Genotipo::getSeqOp()
{
    return this->seqOp;
}

int Genotipo::getSeqOp(int indice)
{
    return this->seqOp[indice];

}
void Genotipo::setSeqOp(int s[], int nOperacoes)
{
    for(int i=0; i<nOperacoes; i++)
    {
        this->seqOp[i] = s[i];

    }
}

int* Genotipo::getIdMaq()
{
    return this->idMaq;

}

int Genotipo::getIdMaq(int indice)
{
    return this->idMaq[indice];
}

void Genotipo::setIdMaq(int s[], int nOperacoes)
{
    for(int i=0; i<nOperacoes; i++)
    {
    this->idMaq[i] = s[i];
    }
}
void Genotipo::setIdMaq(int indice, int valor)
{
    this->idMaq[indice] = valor;
}

int* Genotipo::getIdClasses()
{
    return this->idClasses;
}

int Genotipo::getIdClasses(int indice)
{
    return this->idClasses[indice];
}
void Genotipo::setIdClasses(int indice, int valor)
{
        this->idClasses[indice] = valor;
}

void Genotipo::setIdClasses(int s[], int nOperacoes)
{
    for(int i=0; i<nOperacoes; i++)
    {
    this->idClasses[i] = s[i];

    }
}

int* Genotipo::getTempoFinalMaquinas()
{
    return this->tempoFinalMaquinas;
}

int Genotipo::getTempoFinalMaquinas(int indice)
{
    return this->idClasses[indice];
}

void Genotipo::setTempoFinalMaquinas(int s[], int nOperacoes)
{
    for(int i=0; i<nOperacoes; i++)
    {
        this->idClasses[i] = s[i];

    }
}

void Genotipo::setTempoFinalMaquinas(int indice, int valor)
{
    this->idClasses[indice] = valor;
}

void Genotipo::calculaFitness(Instancia * dados)
{
    int c1=0, c2=0;
    int indiceMaquina, indiceClasse;
    float c3=0;
    for(int i=0; i<dados->getNTotalOps(); i++)
    {
        indiceMaquina = this->getIdMaq(i);
        indiceClasse = this->getIdClasses(i);
        //Eh preciso montar a solucao pra calcular o makespan
        c2 += dados->custosPorOpMaqClass.at(i)->estruturaCustos[indiceClasse].at(0)->getCustoFinanceiro();
        c3 += dados->custosPorOpMaqClass.at(i)->estruturaCustos[indiceClasse].at(0)->getCustoVerde();
    }
    this->setFitness(c2, c3);
}

void Genotipo::calculaMakeSpan(Instancia * dados)
{

    int idMaquina, custotempo, idOperacao, idClasse;
    for(int i=0; i<dados->getNMaquinas(); i++)
    {
        this->tempoFinalMaquinas[i] = 0;
    }
    for(int i=0; i<dados->getNTotalOps(); i++)
    {
        idOperacao = this->getSeqOp(i);
        idMaquina = this->getIdMaq(idOperacao);
        idClasse = this->getIdClasses(idOperacao);
        this->tempoFinalMaquinas[dados->vetvetMaquinasPorOperacao.at(idOperacao).at(idMaquina)-1] +=
                dados->custosPorOpMaqClass.at(idOperacao)->estruturaCustos[idClasse].at(idMaquina)->getCustoTempo();

    }
    int aux =0;
    for(int i=0; i<dados->getNMaquinas(); i++)
    {
        if (this->tempoFinalMaquinas[i] > aux)
        {
            aux = this->tempoFinalMaquinas[i];

        }

    }

    this->setMakeSpan(aux);

}

bool Genotipo::verificaViabilidade(Instancia * dados)
{
    int controle, controleAux=-1;
    bool viavel= true;
    for(int i=0; i<dados->controleTarefas.size(); i++)
    {
        for(int j=0; j<dados->controleTarefas.at(i)->getQtdOperacoes(); j++)
        {
            controle = dados->controleTarefas.at(i)->getInd1Op();
            for(int k=0; k<dados->getNTotalOps(); k++)
            {
                if(controle == this->getSeqOp(k))
                {
                    if(controle < controleAux)
                    {

                        viavel = false;
                        return false;
                    }


                }


            }
            controleAux = controle;

        }

    }

    return viavel;

}


void Genotipo::ConstroiH(Instancia * dados)
{
    bool insere;
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 6);

    for(int i=0; i<dados->getNTotalOps(); i++)
    {
        this->seqOp[i] = -1;
        this->idMaq[i] = -1;
        this->idClasses[i] = -1;
    }
    //Criacao de estruturas de controle da heuristica
    //Lista de candidatos
    int indiceOperacao1, sorteioListadeCandidatos, sorteioMaquina, cont=0, controle, controleID;
    int j;

    vector<Operacao*> listaCandidatos;
    
    for(int i=0; i<dados->getNTarefas(); i++)
    {
        indiceOperacao1 =  dados->controleTarefas.at(i)->getInd1Op();

	
        
        listaCandidatos.push_back(dados->custosPorOpMaqClass.at(indiceOperacao1));

    }

	cout << "Tamanho Lista Candidatos" << listaCandidatos.size() << endl;

    for(int i=0; i<dados->getNMaquinas(); i++)
    {
        this->tempoFinalMaquinas[i] = 0;
    }

    int idSeq, idT, idOp, contSol= dados->getNTotalOps();

    while(contSol!=0 && listaCandidatos.size()!=0)
    {
	
        sorteioListadeCandidatos = dis(gen)%listaCandidatos.size();
        idSeq = listaCandidatos.at(sorteioListadeCandidatos)->getIdSequencial();
        idOp = listaCandidatos.at(sorteioListadeCandidatos)->getIdOperacao();
        idT = listaCandidatos.at(sorteioListadeCandidatos)->getIdTarefa();
        insere = true;

        for(int i=0; i<dados->getNTotalOps(); i++)
        {
            if(this->seqOp[i] == listaCandidatos.at(sorteioListadeCandidatos)->getIdSequencial())
            {
                insere = false;
                break;

            }
        }
        //INSERCAO NA SOLUCAO

        if(insere)
        {
            this->seqOp[cont] =  listaCandidatos.at(sorteioListadeCandidatos)->getIdSequencial();
            sorteioMaquina = dis(gen)%dados->vetQtdMaqPorOperacao.at(idSeq);
            this->idMaq[listaCandidatos.at(sorteioListadeCandidatos)->getIdSequencial()] = sorteioMaquina;
            this->idClasses[listaCandidatos.at(sorteioListadeCandidatos)->getIdSequencial()] = dis(gen)%3;
            //INSERCAO NO BUFFER DE TEMPO DE MAQUINA
            this->tempoFinalMaquinas[dados->vetvetMaquinasPorOperacao.at(idSeq).at(sorteioMaquina)-1] += listaCandidatos.at(sorteioListadeCandidatos)->estruturaCustos[0].at(sorteioMaquina)->getCustoTempo();
            contSol--;
        }

        //TROCA NA LISTA DE CANDIDATOS


        //INSERCAO DE NOVA OPERACAO
        controleID = listaCandidatos.at(sorteioListadeCandidatos)->getIdSequencial();
        controle = listaCandidatos.at(sorteioListadeCandidatos)->getIdTarefa();
        controle = dados->controleTarefas.at(controle)->getInd1Op() + dados->controleTarefas.at(controle)->getQtdOperacoes();
        listaCandidatos.erase(listaCandidatos.begin()+sorteioListadeCandidatos);

        if(controleID+1 < controle)
        {
            controleID++;
            listaCandidatos.push_back(dados->custosPorOpMaqClass.at(controleID));

        }
        cont++;

    }

    int aux =0;
    for(int i=0; i<dados->getNMaquinas(); i++)
    {
        if(tempoFinalMaquinas[i] >aux)
        {
            aux = tempoFinalMaquinas[i];

        }

    }

    if( this->verificaViabilidade(dados))
    {
	this->calculaFitness(dados);
	this->calculaMakeSpan(dados);
    }else 
	{
		cout << "SOLUCAO NAO VIAVEL GERADA" << endl;
		exit(0);
	}

  listaCandidatos.clear();

}

void Genotipo::MutacaoMaquina(Instancia * dados)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 6);
    int sorteioPosicao = dis(gen)%dados->getNTotalOps();
    int sorteioMaquina = dis(gen)%dados->vetQtdMaqPorOperacao.at(sorteioPosicao);
    this->setIdMaq(sorteioPosicao, sorteioMaquina);
    this->calculaFitness(dados);
    this->calculaMakeSpan(dados);
}

void Genotipo::FazerCopia(Genotipo * g1, Genotipo * g2)
{
    g2->setFitnessTempo(g1->getFitnessTempo());
    g2->setFitnessFinanceiro(g1->getFitnessFinanceiro());
    g2->setFitnessVerde(g1->getFitnessVerde());
    g2->setNOperacoes(g1->getNOperacoes());
    g2->setSeqOp(g1->getSeqOp(), g1->getNOperacoes());
    g2->setIdMaq(g1->getIdMaq(), g1->getNOperacoes());
    g2->setIdClasses(g1->getIdClasses(), g1->getNOperacoes());
    g2->setTempoFinalMaquinas(g1->getTempoFinalMaquinas(), g1->getNOperacoes());

}

void Genotipo::MutacaoClasse(Instancia * dados)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 6);
    int sorteioClasse = dis(gen)%3;
    int sorteioPosicao = dis(gen)%dados->getNTotalOps();
    this->setIdClasses(sorteioPosicao, sorteioClasse);
    this->calculaFitness(dados);
    this->calculaMakeSpan(dados);

}

void Genotipo::MutacaoOperacao(Instancia * dados)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 6);
    //PRECISO VERIFICAR TODAS AS RESTRICOES


    this->calculaFitness(dados);
    this->calculaMakeSpan(dados);

}

