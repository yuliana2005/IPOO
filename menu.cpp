#pragma once
#include "Articulos.h"
#include "Laboratorio.h"
#include "PrestamosA.h"
#include "Usuario.h"

#include "Articulos.cpp"
#include "Laboratorio.cpp"
#include "PrestamosA.cpp"
#include "Usuario.cpp"

#include "menu.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Menu::Menu()
{
    this->labo = Laboratorio();
}

Menu::~Menu()
{
    // dtor
}

void Menu::visualizar()
{
    int opc = -1;
    while (opc != 0)
    {
        system ("cls");
        cout <<"***************************" << endl;
        cout <<"******UNIVERSIDAD**********" << endl;
        cout <<"***************************" << endl;
        cout <<"** selecione una opcion  **" << endl;
        cout <<"** 1 laboratorio         **" << endl;
        cout <<"** 2 prestamos           **" << endl;
        cout <<"** 3 usuarios            **" << endl;
        cout <<"** 4 Guardar información **" << endl;
        cout <<"***************************" << endl;
        cout <<"***************************" << endl;
        cin >> opc;
        switch (opc)
        {
        case 1:
            submenuLaboratorio();
            break;
        case 2:
            submenuPrestamo();
            break;
        case 3:
            submenuUsuario();
            break;
        case 4:
            labo.guardarInformacion();
            break;
        }
    }
}

void Menu::submenuLaboratorio()
{
    int opcion;
    system ("cls");
    cout <<"**************************************" << endl;
    cout <<"******>>>LABORATORIO<<<***************" << endl;
    cout <<"**************************************" << endl;
    cout <<"** selecione una opcion             **" << endl;
    cout <<"** 1 Registrar articulo             **" << endl;
    cout <<"** 2 Modificar articulo             **" << endl;
    cout <<"** 3 Listado de articulos ACTIVOS   **" << endl;
    cout <<"** 4 Listado de articulos INACTIVOS **" << endl;
    cout <<"**************************************" << endl;
    cout <<"**************************************" << endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
    {
        int codigo;
        cout << "ingrese cod" << endl;
        cin >> codigo;
        string nombreArticulo;
        cout << "ingrese NombreArticulo: " << endl;
        cin >> nombreArticulo;
        int tipo;
        // 1 muebles 3 pestamo 2 computo
        cout << "ingrese Tipo \n 1 muebles 3 pestamo 2 computo: " << endl;
        cin >> tipo;
        int tiempo;
        cout << "ingrese Tiempo: " << endl;
        cin >> tiempo;
        Articulos articuloNuevo = Articulos(codigo, nombreArticulo, 1, tipo);
        if (tipo == 1)
        {
            labo.agregarArticuloMueble(articuloNuevo);
        }
        else if (tipo == 2)
        {
            labo.agregarArticuloComputo(articuloNuevo);
        }
        else if (tipo == 3)
        {
            labo.agregarArticuloPrestamo(articuloNuevo);
        }
    }
    break;

    case 2:
    {
        int codigo;
        cout << "ingrese el codigo de articulo" << endl;
        cin >> codigo;
        if (labo.buscarArticulo(codigo))
        {
            Articulos articulo = labo.obtenerArticulo(codigo);
            int opc;
            system ("cls");
            cout <<"****************************" << endl;
            cout <<"**>>>MODIFICAR ARTICULO<<<**" << endl;
            cout <<"****************************" << endl;
            cout <<"** selecione una opcion   **" << endl;
            cout <<"** 1 Cambiar nombre       **" << endl;
            cout <<"** 2 Cambiar tipo         **" << endl;
            cout <<"** 3 Cambiar tiempo       **" << endl;
            cout <<"** 4 Cambiar Profesor     **" << endl;
            cout <<"** 5 Cambiar estado       **" << endl;
            cout <<"****************************" << endl;
            cout <<"****************************" << endl;
            cin >> opc;
            switch (opc)
            {
            case 1:
            {
                string nombre;
                cout << "ingrese nuevo nombre :";
                cin >> nombre;
                articulo.darNombreArticulo(nombre);
            }
            break;

            case 2:
            {
                int tipo;
                cout << "ingrese Tipo :";
                cin >> tipo;
                articulo.darTipo(tipo);
            }
            break;
            case 3:
            {
                int tiempo;
                cout << "ingrese Tiempo :";
                cin >> tiempo;
                articulo.darTiempo(tiempo);
            }

            break;
            case 4:
            {
                int codigo;
                cout << "ingresar  codigo de Profesor :";
                cin >> codigo;
                articulo.darEncargado(labo.obtenerProfesor(codigo));
            }

            break;
            case 5:
            {
                bool estado;
                cout << "ingresar  estado ACTIVO = 1, INACTIVO = 0 :";
                cin >> estado;
                articulo.darEstado(estado);
            }
            break;
            }
        }
    }
    case 3:
    {
        labo.articulosActivos();
    }
    break;
    case 4:
    {
        labo.articulosInactivos();
    }
    break;
    }
}

void Menu::submenuPrestamo()
{
    int opcion;
    system ("cls");
    cout <<"****************************" << endl;
    cout <<"*****>>>MENU PRESTAMO<<<****" << endl;
    cout <<"****************************" << endl;
    cout <<"** selecione una opcion   **" << endl;
    cout <<"** 1 Registrar prestamo   **" << endl;
    cout <<"** 2 devolver prestamo    **" << endl;
    cout <<"** 3 prestamos            **" << endl;
    cout <<"****************************" << endl;
    cout <<"****************************" << endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
    {
        int estudiante;
        cout << "ingrese estudiante" << endl;
        cin >> estudiante;
        Usuario est = labo.obtenerEstudiante(estudiante);
        int profesor;
        cout << "ingrese Profesor: " << endl;
        cin >> profesor;
        Usuario pro = labo.obtenerProfesor(profesor);
        float tiempo;
        cout << "ingrese Tiempo del Prestamo: " << endl;
        cin >> tiempo;
        Articulos articulo;
        int codArticulo;
        cout << "ingrese articulo: " << endl;
        cin >> codArticulo;
        if (labo.buscarArticulo(codArticulo))
        {
            articulo = labo.obtenerArticulo(codArticulo);
            if (articulo.obtenerEstado())
            {
                PrestamosA prestamo =
                    PrestamosA(est, pro,articulo, tiempo);
                labo.agregarPrestamo(prestamo);
            }
            else
            {
                cout << "EL ARTICULO ESTA INACTIVO" << endl;
            }
        }

        else
        {
            cout << "EL ARTICULO NO EXISTE" << endl;
        }
        break;
    }

    case 2:
    {
        int estudiante;
        cout << "ingrese estudiante" << endl;
        cin >> estudiante;
        int codArticulo;
        cout << "ingrese articulo: " << endl;
        cin >> codArticulo;
        labo.devolverPrestamo(estudiante, codArticulo);

    }
    break;

    case 3:
        labo.mostrarPrestamos();
        break;
    }
}

void Menu::submenuUsuario()
{
    int opcion;
    system ("cls");
    cout <<"************************************" << endl;
    cout <<"*******>>>USUARIOS<<<***************" << endl;
    cout <<"************************************" << endl;
    cout <<"** selecione una opcion           **" << endl;
    cout <<"** 1 Registrar Estudiante         **" << endl;
    cout <<"** 2 Modificar Estudiante         **" << endl;
    cout <<"** 3 Registrar Profesor           **" << endl;
    cout <<"** 4 Modificar Profesor           **" << endl;
    cout <<"** 5 Multa de Estudiante **" << endl;
    cout <<"************+***********************" << endl;
    cout <<"************************************" << endl;
    cin>> opcion;

    switch(opcion)
    {
    case 1:
    {
        int codigoEst;
        cout<<"Ingresar codigo"<<endl;
        cin>>codigoEst;
        string nombre;
        cout<<"Ingresar Nombre: "<<endl;
        cin>>nombre;
        int telefono;
        cout<<"Ingresar Telefono:"<<endl;
        cin>>telefono;
        string direccion;
        cout<<"Ingresar direccion "<<endl;
        cin>>direccion;
        int valorM;
        cout<<"Ingresar valor de la multa"<<endl;
        cin>>valorM;

        Usuario estudiante = Usuario(codigoEst, nombre, telefono, direccion,valorM);
        labo.agregarEstudiante(estudiante);
    }
    break;

    case 2:
    {
        int codigo;
        cout<<"ingrese el codigo de estudiante"<<endl;
        cin>>codigo;
        if(labo.buscarEstudiante(codigo))
        {
            Usuario usuario = labo.obtenerEstudiante(codigo);
            system ("cls");
            cout <<"****************************" << endl;
            cout <<"**>>MODIFICAR ESTUDIANTE<<**" << endl;
            cout <<"****************************" << endl;
            cout <<"** selecione una opcion   **" << endl;
            cout <<"** 1 Cambiar nombre       **" << endl;
            cout <<"** 2 Cambiar telefono     **" << endl;
            cout <<"** 3 Cambiar direccion    **" << endl;
            cout <<"** 4 Cambiar valorM       **" << endl;
            cout <<"****************************" << endl;
            cout <<"****************************" << endl;

            int opc;
            cin>>opc;
            switch(opc)
            {
            case 1:
            {
                string nombre;
                cout << "ingrese nuevo nombre :";
                cin >> nombre;
                usuario.darNombreUsuario(nombre);
            }
            break;

            case 2:
            {
                int telefono;
                cout << "ingrese Telefono :";
                cin >> telefono;
                usuario.darTelefonoUsuario(telefono);
            }
            break;
            case 3:
            {
                string direccion;
                cout << "ingrese Direccion :";
                cin >> direccion;
                usuario.darDireccionUsuario(direccion);
            }

            break;
            case 4:
            {
                int valorM;
                cout << "ingresar  valor de la Multa :";
                cin >> valorM;
                usuario.darValorMEstudiante(valorM);
            }

            break;

            }
        }
    }
    break;

    case 3:
    {
        int codigo;
        cout<<"Ingresar codigo"<<endl;
        cin>>codigo;
        string nombre;
        cout<<"Ingresar Nombre: "<<endl;
        cin>>nombre;
        int telefono;
        cout<<"Ingresar Telefono: "<<endl;
        cin>>telefono;
        string direccion;
        cout<<"Ingresar direccion "<<endl;
        cin>>direccion;
        Usuario profesor = Usuario(codigo, nombre, telefono, direccion);
        labo.agregarProfesor(profesor);
    }
    break;

    case 4:
    {
        int codigo;
        cout<<"ingrese el codigo de Profesor"<<endl;
        cin>>codigo;
        if(labo.buscarProfesor(codigo))
        {
            Usuario usuario = labo.obtenerProfesor(codigo);
            system ("cls");
            cout <<"****************************" << endl;
            cout <<"**>>MODIFICAR PROFRESOR<<***" << endl;
            cout <<"****************************" << endl;
            cout <<"** selecione una opcion     " << endl;
            cout <<"** 1 Cambiar nombre         " << endl;
            cout <<"** 2 Cambiar telefono       " << endl;
            cout <<"** 3 Cambiar direccion      " << endl;
            cout <<"****************************" << endl;
            cout <<"****************************" << endl;

            int opc;
            cin>>opc;
            switch(opc)
            {
            case 1:
            {
                string nombre;
                cout << "ingrese nuevo nombre :";
                cin >> nombre;
                usuario.darNombreUsuario(nombre);
            }
            break;

            case 2:
            {
                int telefono;
                cout << "ingrese Telefono :";
                cin >> telefono;
                usuario.darTelefonoUsuario(telefono);
            }
            break;
            case 3:
            {
                string direccion;
                cout << "ingrese Direccion :";
                cin >> direccion;
                usuario.darDireccionUsuario(direccion);
            }

            break;


            }
        }
    }
    break;
    case 5:
    {
        int codEst;
        cout<<"Ingresar codigo"<<endl;
        cin>>codEst;
        labo.consultarMultaEstudiante(codEst);
        system("pause");
    }
    break;
    }
}




