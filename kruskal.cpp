/*
 * File: kruskal.cpp
 * Author: Felipe Lopes
 * Created on 25 de Junho de 2016, 20:39
 */


#include <iostream>
#include <fstream>
#include "kruskal.hpp"

using namespace std;


kruskal::kruskal(){
    // Constructor this class

}

void kruskal::sortEdges()
{
    for(int i=1;i<this->noe;i++){
        for(int j=0;j<this->noe-i;j++){
            if(this->weight[j] > this->weight[j+1]){
                int aux = this->graph_edge[j][0];
                
                    this->graph_edge[j][0]=this->graph_edge[j+1][0];
                    this->graph_edge[j+1][0]= aux;

                    aux=this->graph_edge[j][1];
                    this->graph_edge[j][1]=this->graph_edge[j+1][1];
                    this->graph_edge[j+1][1]=aux;

                double aux2 = graph_edge[j][2];
                    this->graph_edge[j][2]=this->graph_edge[j+1][2];
                    this->graph_edge[j+1][2]=aux2;

                    aux2 = this->weight[j];
                    this->weight[j] = this->weight[j+1];
                    this->weight[j+1] = aux2;
            }
        }
    }

}

void kruskal::algorithm()
{
    // inicializa uma matriz para cada nó
    for(int i=1;i<=this->n;i++)
    {
        sets[i][1]=i;
        top[i]=1;
    }

    for(int i=1;i<=this->noe;i++)
    {
        int p1=findNode(this->graph_edge[i][0]);
        int p2=findNode(this->graph_edge[i][1]);
        if(p1 != p2)
        {
            this->w += this->weight[i];
            // Laço que conecta as arestas na matriz
            for(int j=1;j<=this->top[p2];j++){
                this->top[p1]++;
                this->sets[p1][top[p1]]=sets[p2][j];
            }
            this->top[p2]=0; // Zera top[p2]
        }
        else
        {
           // Generates a cycle, so no added. //         
        }
    }
}

int kruskal::findNode(int n){
    for(int i=1;i<=this->noe;i++)
    {
        for(int j=1;j<=this->top[i];j++){
            if(n == this->sets[i][j]){
               return i;
           }
        }
    }
    return -1;
}