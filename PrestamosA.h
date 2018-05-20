#ifndef PRESTAMOSA_H
#define PRESTAMOSA_H

#include <Laboratorio.h>
#include <Estudiantes.h>
#include <Profesor.h>

class PrestamosA
{
	private:

	Estudiantes estudiante;
	Profesor profesor;
	float tiempo;
	Articulos articulo;




	public:
		PrestamosA();
		~PrestamosA();

		Estudiantes obtenerEstudiante();
		void darEstudiante(Estudiante estudiante);
		Profesor obtenerProfesor();
		void darProfesor(Profesor profesor);
		float obtenerTiempo();
		void darTiempo(float tiempo);
		Articulos obtenerArticulos();
		void darArticulos(Articulos articulo);


};

#endif
