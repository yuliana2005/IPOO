#ifndef ESTUDIANTES_H
#define ESTUDIANTES_H


class Estudiantes
{
	private:

	int       codigo;
	string    nombre;
	int       telefono;
	string    direccion;
	int       valorM;


	public:
		Estudiantes();
		~Estudiantes();

		int       obtenerCodigoEstudiante();
		void      darCodigoEstudiante(int codigo);
		string    obtenerNombreEstudiante();
		void      darNombreEstudiante(string nombre);
		string    obtnerTelefonoEstudiante();
		void      darTelfonoEstudiante(int telefono);
		int       obtenerDireccionEstudiante();
		void      darDireccionEstudiante(int direccion);
		int       obtenerValorMEstudiante();
		void      darValorMEstudiante(int valorM);



};

#endif
