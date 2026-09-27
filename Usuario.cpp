//
// Created by tihag on 27/09/2026.
//

#include "Usuario.h"
#include <iostream>

NodoLibro::NodoLibro(Libro *libro) : libro(libro), siguiente(nullptr) {}

Usuario::Usuario()
    :nombre(""), apellidos(""), dni(""), librosActuales(nullptr), historial(nullptr) {}

Usuario::Usuario(const std::string &nombre, const std::string &apellidos, const std::string &dni)
    : nombre(nombre), apellidos(apellidos), dni(dni),
      librosActuales(nullptr), historial(nullptr) {}

Usuario::~Usuario() {
    liberarLista(librosActuales);
    liberarLista(historial);
}


std::string Usuario::getNombre() const {return nombre;}
std::string Usuario::getApellidos() const {return apellidos;}
std::string Usuario::getDni() const {return dni;}

//Añade un nodo al final de la lista indicada
void Usuario::agregarNodo(NodoLibro *&cabeza, Libro *libro) {
    NodoLibro *nuevo = new NodoLibro(libro);
    if (cabeza == nullptr) {
        cabeza = nuevo;
        return;
    }
    NodoLibro *actual = cabeza;
    while (actual->siguiente != nullptr) {
        actual = actual->siguiente;
    }
    actual->siguiente = nuevo;
}

// Elimina de la lista el nodo que apunta a "libro"; devuelve false si no estaba
bool Usuario::eliminarNodo(NodoLibro *&cabeza, Libro *libro) {
    NodoLibro *actual = cabeza;
    NodoLibro *anterior = nullptr;

    while (actual != nullptr) {
        if (actual->libro == libro) {
            if (anterior == nullptr) {
                cabeza = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            delete actual;
            return true;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    return false;
}

void Usuario::liberarLista(NodoLibro *cabeza) {
    NodoLibro *actual = cabeza;
    while (actual != nullptr) {
        NodoLibro *siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

void Usuario::mostrarLista(NodoLibro *cabeza) const {
    NodoLibro *actual = cabeza;
    if (actual == nullptr) {
        std::cout << "  (vacio)" << std::endl;
        return;
    }
    while (actual != nullptr) {
        std::cout << "  - ";
        actual->libro->mostrarInfo();
        actual = actual->siguiente;
    }
}

// El usuario saca un libro: se lo asigna el propio Libro y se apunta
// en la lista de libros actuales y en el historial
bool Usuario::sacarLibro(Libro *libro) {
    if (!libro->prestar(dni)) {
        return false; // el libro no estaba disponible
    }
    agregarNodo(librosActuales, libro);
    agregarNodo(historial, libro);
    return true;
}

// El usuario devuelve un libro: se libera en el propio Libro y se quita
// de la lista de libros actuales (el historial se mantiene)
bool Usuario::devolverLibro(Libro *libro) {
    if (!tieneLibro(libro)) {
        return false;
    }
    libro->devolver();
    eliminarNodo(librosActuales, libro);
    return true;
}

bool Usuario::tieneLibro(Libro *libro) const {
    NodoLibro *actual = librosActuales;
    while (actual != nullptr) {
        if (actual->libro == libro) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

void Usuario::mostrarLibrosActuales() const {
    std::cout << "Libros actuales de " << nombre << " " << apellidos << ":" << std::endl;
    mostrarLista(librosActuales);
}

void Usuario::mostrarHistorial() const {
    std::cout << "Historial de " << nombre << " " << apellidos << ":" << std::endl;
    mostrarLista(historial);
}

void Usuario::mostrarInfo() const {
    std::cout << nombre << " " << apellidos << " (DNI: " << dni << ")" << std::endl;
}

