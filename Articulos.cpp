#pragma once
#include "Articulos.h"
#include <cstdlib>
#include <stdlib.h>
#include <iostream>

using namespace std;

Articulos::Articulos()
{

}

Articulos::~Articulos()
{

}


Articulos::Articulos(int codigo, string nombreArticulo, bool estado, int tipo) {
	this->codigo = codigo;
	this->nombreArticulo = nombreArticulo;
	this->estado = estado;
	this->tipo = tipo;
	if (tipo == 1) {
		this->tiempo = 20;
	} else if (tipo == 2) {
		this->tiempo = 10;
	}

	else if (tipo == 3) {
		this->tiempo = 18;
	}
}


int Articulos::obtenerCodArticulo() {
	return codigo;
}
void Articulos::darCodigoArticulo(int codigo) {
	this->codigo = codigo;
}

string Articulos::obtenerNombreArticulo() {
	return nombreArticulo;
}
void Articulos::darNombreArticulo(string nombreArticulo) {
	this->nombreArticulo = nombreArticulo;
}

int Articulos::obtenerEstado() {
	return estado;
}
void Articulos::darEstado(bool estado) {
	this->estado = estado;
}

int Articulos::obtenerTipo() {
	return tipo;
}
void Articulos::darTipo(int tipo) {
	this->tipo = tipo;
}

int Articulos::obtenerTiempo() {
	return tiempo;
}
void Articulos::darTiempo(int tiempo) {
	this->tiempo = tiempo;
}

int Articulos::depreciacion(int tiempo) {
	int temporal = obtenerTiempo() - tiempo;
	if (temporal <= 0) {
		darEstado(false);
	} else {
		darTiempo(tiempo);
	}
}

void Articulos::darEncargado(Usuario profesor){

}



