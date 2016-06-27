/*
 * File: vertex.cpp
 * Author: Felipe Lopes
 * Created on 21 de Junho de 2016, 20:09
 */


#include <iostream>
#include <vector>
#include "vertex.hpp"

Vertex::Vertex(){ }

//================================
// Sets coordenate
void Vertex::setX(float x){
	this->x = x;
}

void Vertex::setY(float y){
	this->y = y;
}
// ===============================

//================================
// Gets coordenate
float Vertex::getX(){
	return this->x;
}

float Vertex::getY(){
	return this->y;
}
// =============================