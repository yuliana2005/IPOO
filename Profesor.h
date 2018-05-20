#ifndef PROFESOR_H
#define PROFESOR_H


class Profesor
{
	private:

	string   nomProfesor;
	int      telProfesor;
	string      dirProfesor;
	int      codigoProfesor;
	int      fecha;


	public:
		Profesor();
		~Profesor();
		int       obtenerCodigoProfesor();
		void        darCodigoProfesor(int codigo);
		string       obtenerNombreProfesor();
		void     darNombreProfesor(string nombre);
		string       obtnerTelefonoProfesor();
		void     darTelfonoProfesor(int telefono);
		int       obtenerDireccionProfesor();
		void        darDireccionProfesor(int direccion);



};

#endif
