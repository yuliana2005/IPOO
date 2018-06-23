#ifndef USUARIO_H
#define USUARIO_H
#include <string>

using namespace std;

class Usuario
{
	private:

	int       codigo;
	string    nombre;
	int       telefono;
	string    direccion;
	int       valorM;
	string tipo;


	public:
		Usuario();
		~Usuario();
		Usuario(int codigo, string nombre, int telefono, string direccion,int multa);
		Usuario(int codigo, string nombre, int telefono, string direccion);
		int       obtenerCodigoUsuario();
		void      darCodigoUsuario(int codigo);
		string    obtenerNombreUsuario();
		void      darNombreUsuario(string nombre);
		int    obtenerTelefonosuario();
		void      darTelefonoUsuario(int telefono);
		string       obtenerDireccionUsuario();
		void      darDireccionUsuario(string direccion);

		void asignarFecha(int fecha);
		struct tm obtenerFecha();

		int       obtenerValorMEstudiante();
		void      darValorMEstudiante(int valorM);


};

#endif
