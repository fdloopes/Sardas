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

void makeSet(vector<Vertex>  vertice, Vertex *vertex); // add edges to the vertice

int main(int argc, char **argv){
	float x; // Store coordinate X
	float y; // Store coordinate Y
	kruskal kruskal;	// kruskal object
	vector<Vertex>  vertices; // Vector of vertex

    if(argc !=2){ 
		cout << "\nForma de uso: c:\nome_programa nome_arquivo " << endl; 
        exit(1);          
    } 
	
	FILE *arq;
	// Opening of the file passed by parameter
	arq = fopen(argv[1], "r");
	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
		fscanf(arq,"%d\n",&kruskal.n);	// Capture the total number of vertices
		vertices.resize(kruskal.n); // Resizes the vector for total number of vertices
   
		for(int i = 0; i < kruskal.n;i++){	// Loop for reading vertices from the input file
			if((fscanf(arq,"%f %fn", &x, &y))!=EOF){
				vertices[i].setX(x);	// coordinate X
				vertices[i].setY(y);	// coordinate y
			}
		}

	}

	// =====================================================

	// =====================================================

	for(int i=0; i < kruskal.n; i++){
		makeSet(vertices,&vertices[i]); // Creates a complete graph, each vertice has a vector of edges (with weights) for all other vertices
	}
	
	// =====================================================

	// loop that passes the connection between vertices to the graph edges. 
	for(int i=0;i<kruskal.n;i++){
	    for(int j = 0;j<kruskal.n;j++){
		    if(vertices[i].edges[j].getWeight()!=0){
		               	kruskal.graphEdge[kruskal.noe][0]=(int)i+1;
		                kruskal.graphEdge[kruskal.noe][1]=(int)vertices[i].edges[j].getCoordinate()+1;
		                kruskal.graphEdge[kruskal.noe][2]=(int)vertices[i].edges[j].getWeight();
		                kruskal.weight[kruskal.noe] = vertices[i].edges[j].getWeight();
		       			kruskal.noe+=1;
		       	}
	        }
       	}

    // =====================================================

	    kruskal.sortEdges(); // Sorts edges by weight.
	   	kruskal.algorithm(); // Kruskal's algorithm for finding shortest path

	   	cout.precision(5);
	  	cout << endl << kruskal.w << endl<<endl; // Total minimum length of edges

		return 0;
}

// Creates a complete graph, each vertice has a vector of edges (with weights) for all other vertices
// ================================================================================
void makeSet(vector<Vertex> vertice,Vertex *vertex){
	float w;
	Edge edge;
	for(int i = 0 ; i < vertice.size(); i++){
		if( (vertice[i].getX() != vertex->getX()) || vertice[i].getY() != vertex->getY())  {
			// Weight calculation between two coordinates. Pythagoras theorem.
			w = pow(vertex->getX() - vertice[i].getX(),2) + pow((vertex->getY() - vertice[i].getY()),2);
			if(w < 0)
				w *= -1;
			w = sqrt(w);
			// ==============================================================

			edge.setCoordinate(i);	// Coordinate of vertice edge connection
			edge.setWeight(w);		// Weight of edge
			if(edge.getWeight() > 0)
				vertex->edges.push_back(edge); // Add edge to the vector contained in vertice
		}
	}
}
