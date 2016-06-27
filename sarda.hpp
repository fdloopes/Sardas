
/*
 * File: sarda.hpp
 * Author: Felipe Lopes
 * Created on 21 de Junho de 2016, 20:00
 */


#ifndef SARDA_HPP
#define SARDA_HPP

#include <iostream>
#include <string.h>
#include <fstream>
#include <list>
#include <vector>
#include "linha.hpp"

using namespace std;

class Sarda{
protected:
	float x;
	float y;
	float w;
	float verticeMenorCusto;

public:
	vector<Linha> arestas;
	Sarda();
	void setX(float x);
	void setY(float y);
	void setW(float w);
	void setLigacao(int vertice);
	int getLigacao();
	float getX();
	float getY();
	float getW();
};

#endif