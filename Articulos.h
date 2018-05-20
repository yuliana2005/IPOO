#ifndef ARTICULOS_H
#define ARTICULOS_H
#include <string>



using namespace std;

class Articulos
{
	private:
		int         codigo;
		string      nombreArticulo;
	    bool         estado;
	    int valor;

	public:
		Articulos();
		~Articulos();
		void darCodigoArtculo();
		int       obtenerCodArticulo();
		void    darNombreArticulo(string nombre);
		string     obtenerNombreArticulo();
		int        obtenerEstado();
		void       darEstado(int estado);
};

#endif
