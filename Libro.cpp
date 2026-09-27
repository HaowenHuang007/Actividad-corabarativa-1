//
// Created by tihag on 27/09/2026.
//

#include "Libro.h"
#include <iostream>

Libro::Libro()
    :titulo(""), autor(""), categoria(""), disponible(""), dniUsuarioActual(""){}

Libro::Libro(const std::string &titulo, const std::string &autor, const std::string &categoria)
    :titulo(titulo), autor(autor), categoria(categoria),
    disponible(true), dniUsuarioActual(""){}

    std::string Libro::getTitulo() const{return titulo;}
    std::string Libro::getAutor() const{return autor;}
    std::string Libro::getCategoria() const{return categoria;}
    bool Libro::isDisponible() const{return disponible;}
    std::string Libro::getDniUsuarioActual() const{return dniUsuarioActual;}

    bool Libro::prestar(const std::string &dniUsuario) {
    if (!disponible) {
        return false;//ya lo tiene otra persona
    }
    disponible = false;
    dniUsuarioActual = dniUsuario;
    return true;
}

bool  Libro::devolver() {
    if (disponible) {
        return false;//no estaba prestado
    }
    disponible = true;
    dniUsuarioActual = "";
    return true;
}

void Libro::mostrarInfo() const {
    std::cout <<"\"" << titulo << "\" - " << autor
              << " [" << categoria << "] - "
              << (disponible ? "Disponible" : ("Prestado a DNI " + dniUsuarioActual))
              << std::endl;
}
