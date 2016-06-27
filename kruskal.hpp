/*
 * File: kruskal.hpp
 * Author: Felipe Lopes
 * Created on 25 de Junho de 2016, 20:39
 */

#ifndef KRUSKAL_HPP
#define KRUSKAL_HPP

using namespace std;


class kruskal
{
public:
    int n;      //numero de arestas no grafo
    int noe;    //numero de arestas no grafo
    float weight[100*99];   // armazena os valores reais de todos pesos
    float w;            // Armazena o somatório dos pesos
    int graph_edge[100][3]; // grafo de arestas

    int sets[900][900]; // Matriz que representa as subarvores
    int top[100];   // Armazena o total de ligações que cada subarvore possui

    kruskal();
    void sortEdges();  // Ordena arestas
    void algorithm();   // Algoritmo de kruskal
    int findNode(int n);   // Busca nó na subarvore
};
#endif