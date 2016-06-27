/*
 * File: sarda.cpp
 * Author: Felipe Lopes
 * Created on 21 de Junho de 2016, 20:09
 */


#include <iostream>
#include <string.h>
#include <fstream>
#include <list>
#include <vector>
#include "sarda.hpp"
#include "linha.hpp"

Sarda::Sarda(){ }

void Sarda::setX(float x){
	this->x = x;
}

void Sarda::setY(float y){
	this->y = y;
}

void Sarda::setW(float w){
	this->w = w;
}

float Sarda::getW(){
	return this->w;
}

float Sarda::getX(){
	return this->x;
}

float Sarda::getY(){
	return this->y;
}

int Sarda::getLigacao(){
	return this->verticeMenorCusto;
}

void Sarda::setLigacao(int vertice){
	this->verticeMenorCusto = vertice;
}