#ifndef PRESTAMOSA_H
#define PRESTAMOSA_H


#include "Usuario.h"
#include "Articulos.h"

class PrestamosA
{
	private:

	Usuario estudiante;
	Usuario profesor;
	int tiempo;
	Articulos articulo;

	public:
		PrestamosA();
		~PrestamosA();
		PrestamosA(Usuario estudiante, Usuario profesor, Articulos articulo, int tiempo);

		Usuario obtenerEstudiante();
		void darEstudiante(Usuario estudiante);
		Usuario obtenerProfesor();
		void darProfesor(Usuario profesor);
		int obtenerTiempo();
		void darTiempo(int tiempo);
		Articulos obtenerArticulos();
		void darArticulos(Articulos articulo);


};

#endif
