#pragma once
#include "Laboratorio.h"

#include "Articulos.cpp"
#include "PrestamosA.cpp"
#include "Usuario.cpp"

#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <sstream>
#include<iostream>
#include <algorithm>

using namespace std;

Laboratorio::Laboratorio()
{
    this->listaArticulosMuebles = vector<Articulos>();
    this->listaArticulosComputo = vector<Articulos>();
    this->listaArticulosPrestamo = vector<Articulos>();
    this->listaProfesor  = vector<Usuario>();
    this->listaEstudiante = vector<Usuario>();
    this->listaPrestamos = vector<PrestamosA>();
    llenarArticulos();
    llenarUsuario();
    llenarPrestamos();

}

void Laboratorio::llenarArticulos()
{
    ifstream llenar("laboratorio.txt",ifstream::in);
    string linea;
    Articulos articulo;
    vector<string> lectura;
    while (getline(llenar,linea))
    {
        lectura = split_istringstream(linea);
        int codigo = atoi(lectura[0].c_str());
        string nombre = lectura[1];
        bool estado = !(lectura[2] == "0");
        int tipo = atoi(lectura[3].c_str());
        articulo = Articulos(codigo,nombre,estado,tipo);
        if(lectura[3]== "1") /**1 muebles 3 pestamo 2 computo*/
        {
            agregarArticuloMueble(articulo);
        }
        else if(lectura[3]== "2")
        {
            agregarArticuloComputo(articulo);
        }
        else
        {
            agregarArticuloPrestamo(articulo);
        }
    }
    llenar.close();
}
void Laboratorio::llenarUsuario()
{

    ifstream llenar ("usuario.txt",ifstream::in);
    Usuario usuario;
    string linea;
    vector<string> lectura;
    while (getline(llenar,linea))
    {

        lectura = split_istringstream(linea);

        if(lectura[0] == "estudiante")
        {
            int codigo= atoi(lectura[1].c_str());
            string nombre=lectura[2];
            int telefono=atoi(lectura[3].c_str());
            string direccion=lectura[4];
            int multa=atoi(lectura[5].c_str());
            usuario = Usuario(codigo, nombre, telefono,direccion,multa);
            agregarEstudiante(usuario);
        }
        else
        {
            int codigo= atoi(lectura[1].c_str());
            string nombre=lectura[2];
            int telefono=atoi(lectura[3].c_str());
            string direccion=lectura[4];
            usuario = Usuario(codigo, nombre, telefono,direccion);
            agregarProfesor(usuario);
        }
    }
    llenar.close();
}
void Laboratorio::llenarPrestamos()
{
    ifstream llenar ("prestamo.txt",ifstream::in);
    PrestamosA prestamo;
    string linea;
    vector<string> lectura;
    while (getline(llenar,linea))
    {
        lectura = split_istringstream(linea);
        Usuario estudiante = obtenerEstudiante(atoi(lectura[0].c_str()));
        Usuario profesor = obtenerProfesor(atoi(lectura[1].c_str()));
        Articulos articulo = obtenerArticulo(atoi(lectura[2].c_str()));
        int tiempo=atoi(lectura[3].c_str());

        prestamo =PrestamosA(estudiante,profesor,articulo,tiempo);
        agregarPrestamo(prestamo);

    }
    llenar.close();
}
Laboratorio::~Laboratorio()
{
}

vector<string> Laboratorio::split_istringstream(string str)
{
    vector<string> resultado;
    istringstream isstream(str);
    string palabra;
    while(isstream >> palabra)
    {
        resultado.push_back(palabra);
    }
    return resultado;
}


void Laboratorio::agregarArticuloMueble(Articulos articulo)
{
    listaArticulosMuebles.insert(listaArticulosMuebles.end(),articulo);
}

void Laboratorio::agregarArticuloComputo(Articulos articulo)
{
    listaArticulosComputo.insert(listaArticulosComputo.end(),articulo);
}

void Laboratorio::agregarArticuloPrestamo(Articulos articulo)
{
    listaArticulosPrestamo.insert(listaArticulosPrestamo.end(),articulo);
}

void Laboratorio::agregarProfesor(Usuario profesor)
{
    listaProfesor.insert(listaProfesor.end(),profesor);
}

void Laboratorio::agregarEstudiante(Usuario estudiante)
{
    listaEstudiante.insert(listaEstudiante.end(),estudiante);
}

void Laboratorio::agregarPrestamo(PrestamosA prestamo)
{
    listaPrestamos.insert(listaPrestamos.end(),prestamo);
}

bool Laboratorio::buscarArticulo(int articulo)
{
    for (int i = 0; i < listaArticulosComputo.size(); i++)
    {
        if (listaArticulosComputo[i].obtenerCodArticulo() == articulo)
        {
            return true;
        }
    }
    for (int i = 0; i < listaArticulosPrestamo.size(); i++)
    {
        if (listaArticulosPrestamo[i].obtenerCodArticulo() == articulo)
        {
            return true;
        }
    }
    for (int i = 0; i < listaArticulosMuebles.size(); i++)
    {
        if (listaArticulosMuebles[i].obtenerCodArticulo() == articulo)
        {
            return true;
        }
    }
}
Articulos Laboratorio::obtenerArticulo(int articulo)
{
    for (int i = 0; i < listaArticulosComputo.size(); i++)
    {
        if (listaArticulosComputo[i].obtenerCodArticulo() == articulo)
        {
            return listaArticulosComputo[i];
        }
    }
    for (int i = 0; i < listaArticulosPrestamo.size(); i++)
    {
        if (listaArticulosPrestamo[i].obtenerCodArticulo() == articulo)
        {
            return listaArticulosPrestamo[i];
        }
    }
    for (int i = 0; i < listaArticulosMuebles.size(); i++)
    {
        if (listaArticulosMuebles[i].obtenerCodArticulo() == articulo)
        {
            return listaArticulosMuebles[i];
        }
    }
}

Usuario Laboratorio::obtenerProfesor(int codigo)
{
    for (int i = 0; i < listaProfesor.size(); i++)
    {
        if (listaProfesor[i].obtenerCodigoUsuario() == codigo)
        {
            return listaProfesor[i];
        }
    }
}
bool Laboratorio::buscarProfesor(int codigo)
{
    for (int i = 0; i < listaProfesor.size(); i++)
    {
        if (listaProfesor[i].obtenerCodigoUsuario() == codigo)
        {
            return true;
        }
    }
    return false;
}

Usuario Laboratorio::obtenerEstudiante(int codigo)
{
    for (int i = 0; i < listaEstudiante.size(); i++)
    {
        if (listaEstudiante[i].obtenerCodigoUsuario() == codigo)
        {
            return listaEstudiante[i];
        }
    }
}

bool Laboratorio::buscarEstudiante(int codigo)
{
    for (int i = 0; i < listaEstudiante.size(); i++)
    {
        if (listaEstudiante[i].obtenerCodigoUsuario() == codigo)
        {
            return true;
        }
    }
    return false;
}


void Laboratorio::articulosActivos()
{
    for(int i=0; i<listaArticulosComputo.size(); i++)
    {
        if(listaArticulosComputo[i].obtenerEstado()==true)
        {
            cout<< "codigo articulo computo =" <<  listaArticulosComputo[i].obtenerCodArticulo()
                << " nombre articulo = " << listaArticulosComputo[i].obtenerNombreArticulo()<<endl;
        }

    }

    for(int i=0; i<listaArticulosPrestamo.size(); i++)
    {
        if(listaArticulosPrestamo[i].obtenerEstado()==true)
        {
            cout<< "codigo articulo computo =" <<  listaArticulosPrestamo[i].obtenerCodArticulo()
                << " nombre articulo = " << listaArticulosPrestamo[i].obtenerNombreArticulo()<<endl;
        }

    }

    for(int i=0; i<listaArticulosMuebles.size(); i++)
    {
        if(listaArticulosMuebles[i].obtenerEstado()==true)
        {
            cout<< "codigo articulo mueble =" <<  listaArticulosMuebles[i].obtenerCodArticulo()
                << " nombre articulo = " << listaArticulosMuebles[i].obtenerNombreArticulo()<<endl;
        }

    }
}
void Laboratorio::articulosInactivos()
{
    for(int i=0; i<listaArticulosComputo.size(); i++)
    {
        if(listaArticulosComputo[i].obtenerEstado()==false)
        {
            cout<< "codigo articulo computo =" <<  listaArticulosComputo[i].obtenerCodArticulo()
                << " nombre articulo = " << listaArticulosComputo[i].obtenerNombreArticulo()<<endl;
        }

    }

    for(int i=0; i<listaArticulosPrestamo.size(); i++)
    {
        if(listaArticulosPrestamo[i].obtenerEstado()==false)
        {
            cout<< "codigo articulo computo =" <<  listaArticulosPrestamo[i].obtenerCodArticulo()
                << " nombre articulo = " << listaArticulosPrestamo[i].obtenerNombreArticulo()<<endl;
        }

    }

    for(int i=0; i<listaArticulosMuebles.size(); i++)
    {
        if(listaArticulosMuebles[i].obtenerEstado()==false)
        {
            cout<< "codigo articulo mueble =" <<  listaArticulosMuebles[i].obtenerCodArticulo()
                << " nombre articulo = " << listaArticulosMuebles[i].obtenerNombreArticulo()<<endl;
        }

    }
}
void Laboratorio::devolverPrestamo(int estudiante, int codArticulo)
{
    for(int i=0; i<listaPrestamos.size(); i++)
    {
        if((listaPrestamos[i].obtenerEstudiante().obtenerCodigoUsuario()==estudiante)
                && (listaPrestamos[i].obtenerArticulos().obtenerCodArticulo()== codArticulo))
        {
            int demora;
            cout << "ingrese tiempo de demora para entregar articulo  ";
            cin >> demora;
            if(listaPrestamos[i].obtenerTiempo() < demora)
            {
                int multa= abs(listaPrestamos[i].obtenerTiempo() - demora)* 200;
                Usuario est = listaPrestamos[i].obtenerEstudiante();
                est.darValorMEstudiante(multa);
                modificarEstudiante(est);
                Articulos art =listaPrestamos[i].obtenerArticulos();
                art.depreciacion(listaPrestamos[i].obtenerTiempo() + demora);
                modificarArticulo(art);

            }
            vector<PrestamosA>::iterator a = listaPrestamos.begin()+i;
            listaPrestamos.erase(a);
        }

    }

}
void Laboratorio::mostrarPrestamos()
{
    for(int i=0; i<listaPrestamos.size(); i++)
    {

        cout<< "articulo = " << listaPrestamos[i].obtenerArticulos().obtenerCodArticulo() << "  " << listaPrestamos[i].obtenerArticulos().obtenerNombreArticulo()
            << " esudiante = " << listaPrestamos[i].obtenerEstudiante().obtenerCodigoUsuario() << "  " << listaPrestamos[i].obtenerEstudiante().obtenerNombreUsuario()
            << " tiempo = "<< listaPrestamos[i].obtenerTiempo()<<endl;
    }
}


void Laboratorio::modificarEstudiante(Usuario estudiante)
{
    for (int i = 0; i < listaEstudiante.size(); i++)
    {
        if (listaEstudiante[i].obtenerCodigoUsuario() == estudiante.obtenerCodigoUsuario())
        {
            vector<Usuario>::iterator a = listaEstudiante.begin()+i;
            listaEstudiante.erase(a);
            agregarEstudiante(estudiante);
        }
    }

}

void Laboratorio::modificarProfesor(Usuario profesor)
{
    for (int i = 0; i < listaProfesor.size(); i++)
    {
        if (listaProfesor[i].obtenerCodigoUsuario() == profesor.obtenerCodigoUsuario())
        {
            vector<Usuario>::iterator a = listaProfesor.begin()+i;
            listaProfesor.erase(a);
            agregarEstudiante(profesor);
        }
    }
}


void Laboratorio::modificarArticulo(Articulos articulo)
{
    for (int i = 0; i < listaArticulosComputo.size(); i++)
    {
        if (listaArticulosComputo[i].obtenerCodArticulo() == articulo.obtenerCodArticulo())
        {
            vector<Articulos>::iterator a = listaArticulosComputo.begin()+i;
            listaArticulosComputo.erase(a);
            agregarArticuloComputo(articulo);
        }
    }
    for (int i = 0; i < listaArticulosPrestamo.size(); i++)
    {
        if (listaArticulosPrestamo[i].obtenerCodArticulo() == articulo.obtenerCodArticulo())
        {
            vector<Articulos>::iterator a = listaArticulosPrestamo.begin()+i;
            listaArticulosPrestamo.erase(a);
            agregarArticuloPrestamo(articulo);
        }
    }
    for (int i = 0; i < listaArticulosMuebles.size(); i++)
    {
        if (listaArticulosMuebles[i].obtenerCodArticulo() == articulo.obtenerCodArticulo())
        {
            vector<Articulos>::iterator a = listaArticulosMuebles.begin()+i;
            listaArticulosMuebles.erase(a);
            agregarArticuloMueble(articulo);
        }
    }
}

void Laboratorio::consultarMultaEstudiante(int codigo)
{
    cout << obtenerEstudiante(codigo).obtenerValorMEstudiante()<<endl;
}


void Laboratorio::guardarInformacion()
{
    ofstream archivo;
    archivo.open("laboratorio.txt", ios::out);
    for(int i=0; i<listaArticulosComputo.size(); i++)
    {
        archivo << listaArticulosComputo[i].obtenerCodArticulo() << " "
                << listaArticulosComputo[i].obtenerNombreArticulo() << " "
                << listaArticulosComputo[i].obtenerEstado() << " "
                << listaArticulosComputo[i].obtenerTipo() << " "
                <<endl;
    }
    for(int i=0; i<listaArticulosPrestamo.size(); i++)
    {
        archivo << listaArticulosPrestamo[i].obtenerCodArticulo() << " "
                << listaArticulosPrestamo[i].obtenerNombreArticulo() << " "
                << listaArticulosPrestamo[i].obtenerEstado() << " "
                << listaArticulosPrestamo[i].obtenerTipo() << " "
                <<endl;
    }
    for(int i=0; i<listaArticulosMuebles.size(); i++)
    {
        archivo << listaArticulosMuebles[i].obtenerCodArticulo() << " "
                << listaArticulosMuebles[i].obtenerNombreArticulo() << " "
                << listaArticulosMuebles[i].obtenerEstado() << " "
                << listaArticulosMuebles[i].obtenerTipo() << " "
                <<endl;
    }
    archivo.close();

    archivo.open("usuario.txt",ios::out);
    for(int i=0; i<listaEstudiante.size(); i++)
    {
        archivo << "estudiante "
                << listaEstudiante[i].obtenerCodigoUsuario() << " "
                << listaEstudiante[i].obtenerNombreUsuario() << " "
                << listaEstudiante[i].obtenerTelefonosuario() << " "
                << listaEstudiante[i].obtenerDireccionUsuario() << " "
                << listaEstudiante[i].obtenerValorMEstudiante() << " "
                <<endl;
    }
    for(int i=0; i<listaProfesor.size(); i++)
    {
        archivo <<"profesor "
                << listaProfesor[i].obtenerCodigoUsuario() << " "
                << listaProfesor[i].obtenerNombreUsuario() << " "
                << listaProfesor[i].obtenerTelefonosuario() << " "
                << listaProfesor[i].obtenerDireccionUsuario() << " "
                <<endl;
    }

    archivo.close();

    archivo.open("prestamo.txt",ios::out);

    for(int i=0; i<listaPrestamos.size(); i++)
    {
        archivo << listaPrestamos[i].obtenerEstudiante().obtenerCodigoUsuario() << " "
                << listaPrestamos[i].obtenerProfesor().obtenerCodigoUsuario() << " "
                << listaPrestamos[i].obtenerArticulos().obtenerCodArticulo() << " "
                << listaPrestamos[i].obtenerTiempo() << " "
                <<endl;
    }

    archivo.close();
}

