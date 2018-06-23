#pragma once
#include "Usuario.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Usuario::Usuario()
{

}

Usuario::~Usuario()
{

}

Usuario::Usuario(int codigo, string nombre, int telefono, string direccion,int multa){

	this-> codigo = codigo;
	this-> nombre = nombre;
	this-> telefono = telefono;
	this-> direccion = direccion;
	this-> valorM = multa;
	this-> tipo = "estudiante";
}
Usuario::Usuario(int codigo, string nombre, int telefono, string direccion){

	this-> codigo = codigo;
	this-> nombre = nombre;
	this-> telefono = telefono;
	this-> direccion = direccion;
	this-> tipo = "profesor";
}
int Usuario::obtenerCodigoUsuario(){

	return codigo;
}

void Usuario::darCodigoUsuario(int codigo){
	this-> codigo = codigo;
}

string Usuario::obtenerNombreUsuario(){
	return nombre;
}

void Usuario::darNombreUsuario(string nombre){
	this-> nombre= nombre;
}

int Usuario::obtenerTelefonosuario(){
	return telefono;
}

void Usuario::darTelefonoUsuario(int telefono){
	this-> telefono = telefono;
}

string Usuario::obtenerDireccionUsuario(){

	return direccion;
}

void Usuario::darDireccionUsuario(string direccion){
	this-> direccion = direccion;
}


int Usuario::obtenerValorMEstudiante()
{
    return valorM;
}

void Usuario::darValorMEstudiante(int valorM)
{
    this->valorM=valorM;
}




