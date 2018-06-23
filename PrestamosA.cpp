#pragma once
#include "PrestamosA.h"
#include "Usuario.h"
#include "Articulos.h"

#include "Usuario.cpp"
#include "Articulos.cpp"
#include <cstdlib>
#include <iostream>

using namespace std;

PrestamosA::PrestamosA() {
}

PrestamosA::~PrestamosA() {
}

PrestamosA::PrestamosA(Usuario estudiante, Usuario profesor, Articulos articulo, int tiempo) {
	this->estudiante = estudiante;
	this->profesor = profesor;
	this->articulo = articulo;
	this->tiempo=tiempo;
}

Usuario PrestamosA::obtenerEstudiante() {
	return estudiante;
}

void PrestamosA::darEstudiante(Usuario estudiante) {
	this->estudiante = estudiante;
}

Usuario PrestamosA::obtenerProfesor() {
	return profesor;
}

void PrestamosA::darProfesor(Usuario profesor) {
	this->profesor = profesor;
}

int PrestamosA::obtenerTiempo() {
	return tiempo;
}

void PrestamosA::darTiempo(int tiempo) {
	this->tiempo = tiempo;
}

Articulos PrestamosA::obtenerArticulos() {
	return articulo;
}

void PrestamosA::darArticulos(Articulos articulo) {
	this->articulo = articulo;
}
