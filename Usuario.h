//
// Created by tihag on 27/09/2026.
//

#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "Libro.h"

class NodoLibro {
public:
    Libro *libro;
    NodoLibro *siguiente;

    NodoLibro(Libro *libro);
};

class Usuario {
private:
    std::string nombre;
    std::string apellidos;
    std::string dni;

    NodoLibro *librosActuales;
    NodoLibro *historial;

    void agregarNodo(NodoLibro *&cabeza, Libro *libro);
    bool eliminarNodo(NodoLibro *&cabeza, Libro *libro);
    void liberarLista(NodoLibro *cabeza);
    void mostrarLista(NodoLibro *cabeza) const;

public:
    Usuario();
    Usuario(const std::string &nombre, const std::string &apellidos, const std::string &dni);
    ~Usuario();

    std::string getNombre() const;
    std::string getApellidos() const;
    std::string getDni() const;

    bool sacarLibro(Libro *libro);
    bool devolverLibro(Libro *libro);
    bool tieneLibro(Libro *libro) const;

    void mostrarLibrosActuales() const;
    void mostrarHistorial() const;
    void mostrarInfo() const;
};

#endif //ACTIVIDADGRUPAL1_USUARIO_H
