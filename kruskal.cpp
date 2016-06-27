/*
 * File: kruskal.cpp
 * Author: Felipe Lopes
 * Created on 25 de Junho de 2016, 18:00
 */


#include <iostream>
#include <fstream>
#include "kruskal.hpp"

using namespace std;


kruskal::kruskal(){
    // Constructor this class

}

// Algorithm for sorting of edges by weight
void kruskal::sortEdges()
{
    for(int i=1;i<this->noe;i++){
        for(int j=0;j<this->noe-i;j++){
            if(this->weight[j] > this->weight[j+1]){
                int aux = this->graphEdge[j][0];
                
                    this->graphEdge[j][0]=this->graphEdge[j+1][0];
                    this->graphEdge[j+1][0]= aux;

                    aux=this->graphEdge[j][1];
                    this->graphEdge[j][1]=this->graphEdge[j+1][1];
                    this->graphEdge[j+1][1]=aux;

                double aux2 = graphEdge[j][2];
                    this->graphEdge[j][2]=this->graphEdge[j+1][2];
                    this->graphEdge[j+1][2]=aux2;

                    aux2 = this->weight[j];
                    this->weight[j] = this->weight[j+1];
                    this->weight[j+1] = aux2;
            }
        }
    }

}

void kruskal::algorithm()
{
    // Initializes an array of subsets for each vertice.
    // Initializes each subset
    for(int i=1;i<=this->n;i++)
    {
        sets[i][1]=i;
        top[i]=1;
    }


    for(int i=1;i<=this->noe;i++)
    {
        // Search the vertice's position in the subset, if you do not find returns -1
        int p1=findSet(this->graphEdge[i][0]); 
        int p2=findSet(this->graphEdge[i][1]);
        if(p1 != p2) // If the return position is the same, so add this edge will generate a cycle.
        {
            this->w += this->weight[i];
            // loop to connect vertices in a subset
            for(int j=1;j<=this->top[p2];j++){
                this->top[p1]++;
                this->sets[p1][top[p1]]=sets[p2][j];
            }
            this->top[p2]=0; // positioned in the first column and go at least once in the for.
        }
        else
        {
           // Generates a cycle, so no added.         
        }
    }
}


// Traverses the array of subsets to find the vertice passed by parameter.
int kruskal::findSet(int n){
    for(int i=1;i<=this->noe;i++)
    {
        for(int j=1;j<=this->top[i];j++){
            if(n == this->sets[i][j]){
               return i;    // Returns the position at which the vertice was found.
           }
        }
    }
    return -1;  // If you don't find the vertice of parameter returns error.
}