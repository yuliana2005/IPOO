#ifndef Acomputo_H
#define Acomputo_H
#include <string>

#include "Articulos.h"

using namespace std;

class Acomputo : public Articulos
{
	public:
		Acomputo();
		~Acomputo();
		void depreciacion(int tiempo);
};

#endif
