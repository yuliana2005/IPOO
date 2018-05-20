#ifndef Amuebles_H
#define Amuebles_H
#include <string>

#include "Articulos.h"

using namespace std;

class Amuebles : public Articulos
{
	public:
		Amuebles();
		~Amuebles();
		void depreciacion(int tiempo);
};

#endif
