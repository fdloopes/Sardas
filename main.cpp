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
#include "vertex.cpp"
#include "edge.cpp"
#include "kruskal.cpp"

using namespace std;

void makeSet(vector<Vertex>  vertice, Vertex *vertex); // add edges to the vertice.

int main(int argc, char **argv){
	float x; // Store coordinate X
	float y; // Store coordinate Y
	kruskal kruskal;	// kruskal object
	vector<Vertex>  vertices; // Vector of vertex

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
		fscanf(arq,"%d\n",&kruskal.n);
		vertices.resize(kruskal.n); // Cria com a metade do tamanho passado
   		 // Cria a matriz e adiciona os valores x y 
		for(int i = 0; i < kruskal.n;i++){
			if((fscanf(arq,"%f %fn", &x, &y))!=EOF){
				vertices[i].setX(x);
				vertices[i].setY(y);
			}
		}

	}

	// =====================================================

	// =====================================================

	for(int i=0; i < kruskal.n; i++){
		makeSet(vertices,&vertices[i]); // Cria o grafo completo com vetor de edges com ws e vertices destino
	}
	kruskal.noe=0;
	
	for(int i=0;i<kruskal.n;i++){
	    for(int j = 0;j<kruskal.n;j++){
		    if(vertices[i].edges[j].getWeight()!=0){
		               	kruskal.graph_edge[kruskal.noe][0]=(int)i+1;
		                kruskal.graph_edge[kruskal.noe][1]=(int)vertices[i].edges[j].getCoordinate()+1;
		                kruskal.graph_edge[kruskal.noe][2]=(int)vertices[i].edges[j].getWeight();
		                kruskal.weight[kruskal.noe] = vertices[i].edges[j].getWeight();
		       			kruskal.noe+=1;
		       	}
	        }
       	}

	    kruskal.sortEdges();
	   	kruskal.algorithm();

	   	std::cout.precision(5);
	  	cout << "Custo total: " << kruskal.w << endl;

		return 0;
}

// Cria um grafo completo, adiciona um vertor de edges com ws para cada vertice
// ================================================================================
void makeSet(vector<Vertex> vertice,Vertex *vertex){
	float w;
	Edge edge;
	for(int i = 0 ; i < vertice.size(); i++){
		if( (vertice[i].getX() != vertex->getX()) || vertice[i].getY() != vertex->getY())  {
			w = pow(vertex->getX() - vertice[i].getX(),2) + pow((vertex->getY() - vertice[i].getY()),2);
			if(w < 0)
				w *= -1;
			w = sqrt(w);

			edge.setCoordinate(i);
			edge.setWeight(w);
			if(edge.getWeight() > 0)
				vertex->edges.push_back(edge);
		}
	}
}
