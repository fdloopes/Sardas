/*
 * File: vertex.cpp
 * Author: Felipe Lopes
 * Created on 21 de Junho de 2016, 20:09
 */

#include <iostream>
#include "vertex.hpp"

Vertex::Vertex(){ }

//================================
// Sets coordinates X and Y
void Vertex::setX(float x){
	this->x = x;
}

void Vertex::setY(float y){
	this->y = y;
}
// ===============================

//================================
// Gets coordinates X and Y
float Vertex::getX(){
	return this->x;
}

float Vertex::getY(){
	return this->y;
}
// =============================