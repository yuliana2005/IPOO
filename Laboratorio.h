#ifndef LABORATORIO_H
#define LABORATORIO_H

#include <vector>

#include "Articulos.h"
#include "PrestamosA.h"
#include "Usuario.h"

class Laboratorio
{
private:



public:

    vector<Articulos>   listaArticulosMuebles;
    vector<Articulos>   listaArticulosComputo;
    vector<Articulos>   listaArticulosPrestamo;
    vector<Usuario>   listaProfesor ;
    vector<Usuario>   listaEstudiante;
    vector<PrestamosA>   listaPrestamos;

    Laboratorio();
    ~Laboratorio();

    void llenarArticulos();
    void llenarUsuario();
    void llenarPrestamos();
    void guardarInformacion();
    vector<string> split_istringstream(string str);//esto es auxiliar

    void agregarArticuloMueble(Articulos articulo);
    void agregarArticuloComputo(Articulos articulo);
    void agregarArticuloPrestamo(Articulos articulo);
    void agregarProfesor(Usuario profesor);
    void agregarEstudiante(Usuario estudiante);
    void agregarPrestamo(PrestamosA prestamo);

    bool buscarArticulo(int articulo);
    Articulos obtenerArticulo(int articulo);

    bool buscarProfesor(int codigo);
    Usuario obtenerProfesor(int codigo);
    bool buscarEstudiante(int codigo);
    Usuario obtenerEstudiante(int codigo);

    void articulosActivos();
    void articulosInactivos();
    void consultarMultaEstudiante(int codigo);

    void devolverPrestamo(int estudiante, int codArticulo);
    void mostrarPrestamos();

    void modificarEstudiante(Usuario Usuario);
    void modificarProfesor(Usuario Usuario);
    void modificarArticulo(Articulos articulo);




};

#endif
