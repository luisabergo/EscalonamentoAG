#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include "instancia.h"
#include "tarefa.h"
#include "operacao.h"
#include "custo.h"
#include "populacao.h"
#include "genotipo.h"

using namespace std;




int main ()
{

//---------------------------------------------------------------------------------------------Leitura
    // Leitura dos parametros do executavel
    std::string nomeEntrada = "DFJSP02.txt";
    //Declaracao de todas as variaveis utilizadas no main
    string leitura, aux;
    int auxInt, somatorio=0, aux1, aux2;
    float aux3, aux4, aux5, aux6;
    vector<int> auxVector;
    //Tipo de dados da Instancia lida
    Instancia *instancia1 = new Instancia();;
    Custo *c6;
    //Funcoes para abertura doarquivo de instancia
    std::ifstream arquivoEntrada;
    arquivoEntrada.open(nomeEntrada);
    arquivoEntrada >> leitura;
    if(arquivoEntrada.is_open())
    cout << "Leitura da Instância tipo : " << leitura << endl;
    else
    {
        cout << "Erro na leitura do arquivo" << endl;
        exit(0);
    }

    //alocacao de estrutura para armazenar dados da instancia
//     instancia1 = new Instancia();

    //leitura dos parametros iniciais e armazenamento na instancia
    arquivoEntrada >> auxInt;
    //cout << auxInt<< endl;
    instancia1->setNTarefas(auxInt);
    arquivoEntrada >> auxInt;
    //cout << auxInt<< endl;
    instancia1->setNMaquinas(auxInt);
    arquivoEntrada >> auxInt;
    //cout << auxInt<< endl;
    instancia1->setNClassesTrab(auxInt);

    //Busca na instancia pelo marcador de leitura de qtd de tarefas
    do{
        arquivoEntrada >> aux;

    }while(aux!="vector:");

    //Declaracao de variavel para receber estrutura de tarefas
    Tarefa* t;

    //Coloca a informação de numero de operacoes por tarefa em um vetor na instancia e soma total de operacoes na instancia
    for(int i=0; i<instancia1->getNTarefas(); i++)
    {

        arquivoEntrada >> auxInt;
        t = new Tarefa(somatorio, auxInt);
        //cout << "Numero de operacoes "<< auxInt << " e indice da primeira operacao " << somatorio << endl;
        instancia1->controleTarefas.push_back(t);

        instancia1->vetQtdOperacoes.push_back(auxInt);
        somatorio += auxInt;
    }
    instancia1->setNTotalOps(somatorio);
    somatorio =0;

    //Busca na instancia pelo marcador de leitura de qtd de maquinas e soma total de maquinas a serem lidas
    do{
        arquivoEntrada >> aux;
    }while(aux!="vector:");

    Operacao* op;
    int cont=0;
    //Coloca a informacao da qtd de maquinas que podem realizar uma operacao em um vetor
    for(int i=0; i<instancia1->controleTarefas.size(); i++)
    {
        for(int j=0; j<instancia1->controleTarefas.at(i)->getQtdOperacoes(); j++)
        {
            arquivoEntrada >> auxInt;
            op = new Operacao(i, auxInt, instancia1->getNClassesTrab(), cont, j);
            //cout << "id da Tarefa "<< i << " e id da operacao " << j << " e nro de maquinas "<< auxInt << endl;
            instancia1->vetQtdMaqPorOperacao.push_back(auxInt);
            instancia1->custosPorOpMaqClass.push_back(op);
            somatorio += auxInt;
            cont++;
        }

    }
    instancia1->setNTotalLeituraMaqs(somatorio);

    //Busca na instancia pelo marcador de leitura de ID de maquinas a serem lidas
    do{
        arquivoEntrada >> aux;
    }while(aux!="vector:");


    //Armazena na estrutura da instancia o id das maquinas cada uma na posicao de operacao
    for(int i=0; i<instancia1->getNTotalOps(); i++)
    {
        for(int j=0; j<instancia1->vetQtdMaqPorOperacao.at(i); j++)
        {
            arquivoEntrada >> auxInt;
            auxVector.push_back(auxInt);
            //cout << instancia1->custosPorOpMaqClass.at(i)->getIdTarefa()<< endl;

        }
        instancia1->vetvetMaquinasPorOperacao.push_back(auxVector);
        while(auxVector.size() !=0)
            auxVector.pop_back();

    }


    for(int i=0; i<instancia1->vetvetMaquinasPorOperacao.size(); i++)
    {
        for(int j=0; j<instancia1->vetvetMaquinasPorOperacao.at(i).size(); j++)
        {
           // cout <<"ID sequencial tarefa:"<< i << " Id da op dentro da tarefa:"<< j << " Id da maquina:" << instancia1->vetvetMaquinasPorOperacao.at(i).at(j) << endl;
        }
    }

    //Busca na instancia pelo marcador de leitura de custos a serem lidos
    do{
        arquivoEntrada >> aux;
    }while(aux!="array:");



    //Leitura de uma estrutura da instancia Custo*
    for(int i=0; i<instancia1->custosPorOpMaqClass.size(); i++)
    {
        for(int j=0; j<instancia1->custosPorOpMaqClass.at(i)->getQtdMaquinas(); j++)
        {
            for(int k=0; k<3;k++)
            {

                arquivoEntrada >> aux1;
                arquivoEntrada >> aux2;
                arquivoEntrada >> aux3;
                arquivoEntrada >> aux4;
                arquivoEntrada >> aux5;
                arquivoEntrada >> aux6;

                c6 = new Custo(aux1, aux2, aux3, aux4, aux5, aux6);

                instancia1->custosPorOpMaqClass.at(i)->insereCusto(c6, k, j);
                cout <<"Minha operação:"<< i << " Na máquina:"<< j << " Na classe de trabalhador:" << k << " Tem custo de tempo:"<< aux2 <<  endl;

            }

        }
    }


    arquivoEntrada.close();

//---------------------------------------------------------------------------------------------Fim da Leitura


//-----------------------------------------------------------------TESTES HEURISTICA CONSTRUTIVA
   Genotipo* sol = new Genotipo(instancia1->getNTotalOps(), instancia1->getNMaquinas());
    Genotipo* sol3 = new Genotipo(instancia1->getNTotalOps(), instancia1->getNMaquinas());
	sol->ConstroiH(instancia1);

    cout << "Para i, SOLUCAO SEQUENCIA:" << endl;
    for(int i=0; i<instancia1->getNTotalOps(); i++)
    {
        cout<< sol->getSeqOp(i) << " ";

    }
    cout << endl;
  cout << "Para i, SOLUCAO MAQUINAS:" << endl;
    for(int i=0; i<instancia1->getNTotalOps(); i++)
    {
        cout<< instancia1->vetvetMaquinasPorOperacao.at(i).at(sol->getIdMaq(i)) << " " ;

    }
    cout << "Para i, SOLUCAO ID CLASSES:" << endl;
    for(int i=0; i<instancia1->getNTotalOps(); i++)
    {
        cout<< sol->getIdClasses(i)<< " " ;

    }

	
    cout << "Custo Tempo" << sol->getFitnessTempo() << endl;
    cout << "Custo Financeiro:" <<  sol->getFitnessFinanceiro() << endl;
    cout << "Custo Verde:" <<  sol->getFitnessVerde() << endl;

    for(int i=0 ; i<20; i++)
   sol->MutacaoMaquina(instancia1,sol3);



    cout << "Custo Tempo" << sol3->getFitnessTempo() << endl;
    cout << "Custo Financeiro:" <<  sol3->getFitnessFinanceiro() << endl;
    cout << "Custo Verde:" <<  sol3->getFitnessVerde() << endl;


    //----------------------------------------- ALGORITMO GENETICO-------------------------//


    //Geracao da Populacao Inicial atraves de Heuristica Construtiva

    int tamanhoPopulacao=20, nGeracoes=10;
    Populacao* p = new Populacao();

    for(int i=0; i<tamanhoPopulacao; i++)
    {
        Genotipo* sol = new Genotipo(instancia1->getNTotalOps(), instancia1->getNMaquinas());
        cout << "Criando Solução " <<  i << endl;
        sol->ConstroiH(instancia1);

        cout << "Solução Criada" << endl;
        cout << "Inserindo Solução " << i <<  endl;
        p->pInicial.push_back(sol);
	sol->calculaFitness(instancia1);
	sol->calculaMakeSpan(instancia1);
        cout << "Solução inserida com custo " << sol->getFitnessTempo() <<  endl;

    }
   //p->RankingTempo();

  for(int i=0; i<20; i++)
    {
        Genotipo* sol1 = new Genotipo(instancia1->getNTotalOps(), instancia1->getNMaquinas());
        Genotipo* sol2 = new Genotipo(instancia1->getNTotalOps(), instancia1->getNMaquinas());
        cout << "Solucao na posicao " << i << ":" << p->pInicial.at(i)->getFitnessTempo() << endl;

        p->pInicial.at(i)->MutacaoMaquina(instancia1, sol1);
        p->pInicial.at(i)->MutacaoClasse(instancia1,sol2);
        p->pMutacao1.push_back(sol1);
        p->pMutacao2.push_back(sol2);

        cout << "Mutacao 1 na posicao " << i << ":" << p->pMutacao1.at(i)->getFitnessTempo() << endl;


        cout << "Mutacao 2 na posicao " << i  << ":" << p->pMutacao2.at(i)->getFitnessTempo() << endl;
    }


    //Algoritmo Genetico




    return 0;
}
