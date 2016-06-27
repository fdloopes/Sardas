
/*
 * File: vertex.hpp
 * Author: Felipe Lopes
 * Created on 21 de Junho de 2016, 20:00
 */


#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>
#include <vector>
#include "edge.hpp"

using namespace std;

class Vertex{
protected:
	float x;	// Armazena coordenada de x
	float y;	// Armazena coordenada de y	

public:
	vector<Edge> edges;
	Vertex();
	void setX(float x);
	void setY(float y);
	float getX();
	float getY();
};

#endif