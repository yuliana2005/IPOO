#ifndef ARTICULOS_H
#define ARTICULOS_H
#include <string>
#include "Usuario.h"


using namespace std;

class Articulos
{
	private:
		int         codigo;
		string      nombreArticulo;
	    bool         estado;
	    int tipo; //1 muebles 3 pestamo 2 computo
	    int tiempo;

	public:
		Articulos();
		~Articulos();
		Articulos(int codigo, string nombreArticulo, bool estado, int tipo);
		void darCodigoArticulo(int codigo);
		int       obtenerCodArticulo();
		void    darNombreArticulo(string nombre);
		string     obtenerNombreArticulo();
		int        obtenerEstado();
		int obtenerTipo();
		void darTipo(int tipo);
		int depreciacion(int tiempo);
		void       darEstado(bool estado);
		int obtenerTiempo();
		void darTiempo(int tiempo);
		void darEncargado(Usuario profesor);
};

#endif
