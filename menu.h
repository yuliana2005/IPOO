#ifndef MENU_H
#define MENU_H

#include "Usuario.h"
#include "Laboratorio.h"

using namespace std;

class Menu
{
    public:
        Menu();
        virtual ~Menu();
				void submenuPrestamo();
				void submenuLaboratorio();
				void submenuUsuario();
				void visualizar();

				Laboratorio labo;

    protected:

    private:
};

#endif // MENU_H
