/*
 * File: main.cpp
 * Author: Felipe Lopes
 * Created on 21 de Junho de 2016, 20:39
 */

#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h> 
#include <vector>
#include <math.h>
#include "sarda.cpp"
#include "linha.cpp"
#include "kruskal.cpp"

using namespace std;

void quickSort(Sarda *ponto, int p, int r);	// Algori
void makeSet(vector<Sarda>  vertice , Sarda *ponto);
void adicionaVetor(vector<Sarda> vertice,Linha aresta, vector<int> *vet, int aux);

int main(int argc, char **argv){
	float x;
	float y;
	float peso;
	kruskal ptr;
	vector<Sarda>  sardas;

    if(argc !=2) 
    { 
		cout << "\nForma de uso: c:\nome_programa nome_arquivo "; 
        exit(1);          
    } 
	
	FILE *arq;
	
	arq = fopen(argv[1], "r");
	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
		fscanf(arq,"%d\n",&ptr.n);
		sardas.resize(ptr.n); // Cria com a metade do tamanho passado
    // Cria a matriz e adiciona os valores x y 
		for(int i = 0; i < ptr.n;i++){
			if((fscanf(arq,"%f %fn", &x, &y))!=EOF){
				sardas[i].setX(x);
				sardas[i].setY(y);
				if( i == 0)
					sardas[i].setW(0); // Define o primeiro vértice com prioridade
				else
					sardas[i].setW(-1); // -1 para representar o infinito ou não definido
			}
		}

	}

	// =====================================================

	// =====================================================

	for(int i=0; i < ptr.n; i++){
		makeSet(sardas,&sardas[i]); // Cria o grafo completo com vetor de arestas com pesos e vertices destino
	}
	ptr.noe=0;
	
	for(int i=0;i<ptr.n;i++){
	    for(int j = 0;j<ptr.n;j++){
		    peso=(float)sardas[i].arestas[j].getWeight();
		    if(peso!=0){
		               	ptr.graph_edge[ptr.noe][0]=(int)i;
		                ptr.graph_edge[ptr.noe][1]=(int)sardas[i].arestas[j].getCoordenada();
		                ptr.graph_edge[ptr.noe][2]=(int)peso;
		                ptr.weight[ptr.noe] = (float)peso;
		       			ptr.noe=ptr.noe+1;
		       	}
	        }
       }

	    ptr.sort_edges();
	   	ptr.algorithm();

	   	//cout << "Arvore resultante: " << endl;
	  	//ptr.print_min_span_t();
	   	std::cout.precision(5);
	  	cout << "Custo total: " << ptr.w << endl;

		return 0;
}

// ================================================================
// Algoritmo de ordenação para o vetor de pesos das arestas
//=================================================================
void quickSort(Sarda *ponto, int esq, int dir){
    int pivo = esq,i,ch,j;
    Linha aresta;
    for( i = esq+1; i<= dir; i++){
        j = i;
        if(ponto->arestas[i].getWeight() < ponto->arestas[pivo].getWeight() && ponto->arestas[i].getWeight() > 0){
         	aresta = ponto->arestas[j];
         while(j > pivo){    
            ponto->arestas[j] = ponto->arestas[j-1];
            j--;
         }
         ponto->arestas[j] = aresta;
         pivo++;        
        }  
    }
    if(pivo-1 >= esq){
        quickSort(ponto,esq,pivo-1);
    }
    if(pivo+1 <= dir){
        quickSort(ponto,pivo+1,dir);
    }
 }

// Cria um grafo completo, adiciona um vertor de arestas com pesos para cada vertice
// ================================================================================
void makeSet(vector<Sarda> vertice,Sarda *ponto){
	long double peso;
	Linha aresta;
	for(int i = 0 ; i < vertice.size(); i++){
		if( (vertice[i].getX() != ponto->getX()) || vertice[i].getY() != ponto->getY())  {
			peso = pow(ponto->getX() - vertice[i].getX(),2) + pow((ponto->getY() - vertice[i].getY()),2);
			if(peso < 0)
				peso *= -1;
			peso = sqrt(peso);

			aresta.setCoordenada(i);
			aresta.setWeight(peso);
			if(aresta.getWeight() > 0)
				ponto->arestas.push_back(aresta);
		}
	}
	quickSort(ponto,0,ponto->arestas.size());
}
