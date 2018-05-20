#ifndef LABORATORIO_H
#define LABORATORIO_H

#include <vector>

#include "Amuebles.h"
#include "Acomputo.h"
#include "Aprestamo.h"

class Laboratorio
{
private:

    vector<Amuebles>   listaArticulosMuebles;
    vector<Acomputo>   listaArticulosComputo;
    vector<Aprestamo>   listaArticulosPrestamo;



public:
    Laboratorio();
    ~Laboratorio();

    void agregarArticuloMueble(Amuebles articulo);
    void agregarArticuloComputo(Acomputo articulo);
    void agregarArticuloPrestamo(Aprestamo articulo);
    bool buscarArticuloMuebles(Amuebles articulo);
    bool buscarArticuloComputo(Acomputo articulo);
    bool buscarArticuloPrestamo(Aprestamo articulo);


};

#endif
