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
 // Construtor da classe   
}


void kruskal::sort_edges()
{
    for(int i=1;i<noe;i++){
        for(int j=0;j<noe-i;j++){
            if(this->weight[j] > this->weight[j+1]){
                int aux = graph_edge[j][0];
                
                    graph_edge[j][0]=graph_edge[j+1][0];
                    graph_edge[j+1][0]= aux;

                    aux=graph_edge[j][1];
                    graph_edge[j][1]=graph_edge[j+1][1];
                    graph_edge[j+1][1]=aux;

                double aux2 = graph_edge[j][2];
                    graph_edge[j][2]=graph_edge[j+1][2];
                    graph_edge[j+1][2]=aux2;

                    aux2 = this->weight[j];
                    this->weight[j] = this->weight[j+1];
                    this->weight[j+1] = aux2;
            }
        }
    }

}



void kruskal::algorithm()
{
    // ->make a set for each node
    for(int i=1;i<=n;i++)
    {
        sets[i][1]=i;
        top[i]=1;
    }

    cout<<"\nThe algorithm starts ::\n\n";

    for(int i=1;i<=noe;i++)
    {
    int p1=find_node(graph_edge[i][0]);
    int p2=find_node(graph_edge[i][1]);
        if(p1 != p2)
        {
            cout<<"The edge included in the tree is ::"
            <<" < "<<graph_edge[i][0]<<" , "
            <<graph_edge[i][1]<<" > "<<endl<<endl;
                
            w += (float)weight[i];
            // Mix the two sets
            // Laço que une as duas subarvores
            for(int j=1;j<=top[p2];j++){
                top[p1]++;
                cout << "top[p1]: "<< top[p1] <<endl;
                sets[p1][top[p1]]=sets[p2][j];
            }
            top[p2]=0;
        }
        else
        {
           // Gera um ciclo, por isso é removido //         }
        }
    }
}

int kruskal::find_node(int n){
    n++;
    for(int i=1;i<=noe;i++)
    {
        for(int j=1;j<=top[i];j++){
            cout << "Sets["<< i<< "]"<< "["<<j<< "]: " << sets[i][j] << endl;
            cout << "Valor de n: " << n << endl;
           if(n == sets[i][j]){
               return i;
           }
        }
    }
    return -1;
}