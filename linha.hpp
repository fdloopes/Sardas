
/*
 * File: linha.hpp
 * Author: Felipe Lopes
 * Created on 22 de Junho de 2016, 16:27
 */


#ifndef LINHA_HPP
#define LINHA_HPP

#include <iostream>
#include <vector>

using namespace std;

class Edge{
protected:
	int coordinate;	// Coordinate of the vertex that connects
	double weight;	// Weight this edge

public:
	Edge();	
	void setCoordinate(int x);
	void setWeight(float w);
	int getCoordinate();
	float getWeight();
};

#endif