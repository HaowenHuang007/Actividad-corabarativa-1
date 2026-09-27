//
// Created by ACER NITRO on 27/09/2026.
//

#include "Usuario.h"
//CONSTRCUTORES
Usuario::Usuario() {
    nombre = "";
    apellidos = "";
    dni = "";
    librosActuales();
    historialLibros();
}
Usuario::Usuario(const std::string& nombre, const std::string& apellidos, const std::string& dni) {
    this->nombre = nombre;
    this->apellidos = apellidos;
    this->dni = dni;
}

//Getters
const std::string& Usuario::getNombre() const{
    return nombre;
}

const std::string& Usuario::getApellidos() const{
    return apellidos;
}

const std::string& Usuario::getDni() const{
    return dni;
}

//metodos de gestion de los libros
bool Usuario::tieneLibro(int identificadorLibro) const{
    Pila<int, MAX_LIBROS_ACTUALES> copia = librosActuales;

    while (!copia.vacia()){
        if (copia.cima() == identificadorLibro){
            return true;
        }
        copia.desapilar();
    }

    return false;
}

bool Usuario::agregarLibroActual(int identificadorLibro){
    if (librosActuales.llena() || tieneLibro(identificadorLibro))
    {
        return false;
    }
    librosActuales.apilar(identificadorLibro);
    return true;
}

bool Usuario::registrarDevolucion(int identificadorLibro){
    if (!tieneLibro(identificadorLibro) || historialLibros.llena())
    {
        return false;
    }
    Pila<int, MAX_LIBROS_ACTUALES> temporal;
    bool encontrado = false;

    // Se apartan los libros que estan encima del libro que se quiere devolver.
    while (!librosActuales.vacia()){
        int libro = librosActuales.cima();
        librosActuales.desapilar();

        if (libro == identificadorLibro){
            encontrado = true;
            break;
        }
        temporal.apilar(libro);
    }

    if (!encontrado){
        while (!temporal.vacia()){
            librosActuales.apilar(temporal.cima());
            temporal.desapilar();
        }
        return false;
    }

    // Se restauran los libros que no se han devuelto.
    while (!temporal.vacia()){
        librosActuales.apilar(temporal.cima());
        temporal.desapilar();
    }

    historialLibros.apilar(identificadorLibro);
    return true;
}

//Con estos metodos accedemos a los datos de la pila (simulando un acceso por indice)
int Usuario::getCantidadLibrosActuales() const{
    return librosActuales.tamano();
}


bool Usuario::obtenerLibroActual(int posicion, int& identificadorLibro) const{
    if (posicion < 0 || posicion >= librosActuales.tamano()){
        return false;
    }

    Pila<int, MAX_LIBROS_ACTUALES> copia = librosActuales;
    for (int i = 0; i < posicion; i++){
        copia.desapilar();
    }
    identificadorLibro = copia.cima();
    return true;
}

int Usuario::getCantidadHistorial() const{
    return historialLibros.tamano();
}

bool Usuario::obtenerLibroHistorial(int posicion, int& identificadorLibro) const{
    if (posicion < 0 || posicion >= historialLibros.tamano()){
        return false;
    }

    Pila<int, MAX_HISTORIAL> copia = historialLibros;
    for (int i = 0; i < posicion; i++){
        copia.desapilar();
    }
    identificadorLibro = copia.cima();
    return true;
}