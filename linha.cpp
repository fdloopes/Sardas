/*
 * File: linha.cpp
 * Author: Felipe Lopes
 * Created on 22 de Junho de 2016, 16:31
 */


#include <iostream>
#include <string.h>
#include <fstream>
#include <list>
#include <vector>
#include "linha.hpp"

Linha::Linha(){ }

void Linha::setCoordenada(int x){
	this->coordenada = x;
}

void Linha::setWeight(float w){
	this->weight = w;
}

float Linha::getWeight(){
	return this->weight;
}

int Linha::getCoordenada(){
	return this->coordenada;
}
