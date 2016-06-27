
/*
 * File: linha.hpp
 * Author: Felipe Lopes
 * Created on 22 de Junho de 2016, 16:27
 */


#ifndef LINHA_HPP
#define LINHA_HPP

#include <iostream>
#include <string.h>
#include <fstream>
#include <list>
#include <vector>

using namespace std;

class Linha{
protected:
	int coordenada;
	double weight;

public:
	Linha();
	void setCoordenada(int x);
	void setWeight(float w);
	int getCoordenada();
	float getWeight();
};

#endif