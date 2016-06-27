
/*
 * File: edge.cpp
 * Author: Felipe Lopes
 * Created on 22 de Junho de 2016, 16:31
 */


#include <iostream>
#include <vector>
#include "linha.hpp"

Edge::Edge(){ }

//===============================
// Sets: Coordenate 
void Edge::setCoordinate(int x){
	this->coordinate = x;
}

void Edge::setWeight(float w){
	this->weight = w;
}

// Retorna peso da aresta
float Edge::getWeight(){
	return this->weight;
}

// Retorna coordenada que faz ligação
int Edge::getCoordenate(){
	return this->coordinate;
}
