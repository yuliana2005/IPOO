#ifndef Aprestamo_H
#define Aprestamo_H
#include <string>

#include "Articulos.h"

using namespace std;

class Aprestamo : public Articulos
{
	public:
		Aprestamo();
		~Aprestamo();
		void depreciacion(int tiempo);
};

#endif
