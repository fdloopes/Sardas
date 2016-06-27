/*
 * File: kruskal.hpp
 * Author: Felipe Lopes
 * Created on 25 de Junho de 2016, 18:00
 */

#ifndef KRUSKAL_HPP
#define KRUSKAL_HPP

using namespace std;


class kruskal
{
public:
    int n;      // number of vertices in the graph.
    int noe;    // number of edges in the graph
    float weight[100*99];   // stores the actual values of all weights.
    float w;            // Store the sum of the weights.
    int graphEdge[100][3]; // graph of edges

    int sets[101][900]; // Array that represents the subsets.
    int top[101];   // Store the total size of each subset.

    kruskal();
    void sortEdges();  // Ordering edges by weight
    void algorithm();   // Kruskal's algorithm
    int findSet(int n);  // vertice research on array of subsets.
};
#endif