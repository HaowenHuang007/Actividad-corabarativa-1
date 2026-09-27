//
// Created by Alejandro on 27/09/2026.
//

#ifndef PRIMERA_ACTIVIDAD_COLABORATIVA_PROGRAMA_H
#define PRIMERA_ACTIVIDAD_COLABORATIVA_PROGRAMA_H
#include <string>

#include "Libro.h"
#include "Pila.h"
#include "Usuario.h"

constexpr int MAX_LIBROS_REGISTRADOS = 20; // Capacidad máx de libros que puede almacenar la pila
constexpr int MAX_USUARIOS_REGISTRADOS = 5; // Capacidad máx de usuarios que puede almacenar la pila

class Programa
{
private:
    int leerEntero(const std::string& mensaje); // Pide y valida un entero por teclado
    std::string leerTexto(const std::string& mensaje); // Pide y valida un texto por teclado
    void mostrarMenu(); // Imprime las opciones del menú principal

    bool buscarLibro(const Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros,
                     int identificador,
                     int& posicion) const; // Localiza la posición de un libro por su identificador

    bool buscarUsuario(const Pila<Usuario, MAX_USUARIOS_REGISTRADOS>& usuarios,
                       const std::string& dni,
                       int& posicion) const; // Localiza la posición de un usuario por su DNI

    bool obtenerLibro(const Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros,
                      int identificador,
                      Libro& libro,
                      int& posicion) const; // Busca un libro y además devuelve una copia de sus datos

    bool obtenerUsuario(const Pila<Usuario, MAX_USUARIOS_REGISTRADOS>& usuarios,
                        const std::string& dni,
                        Usuario& usuario,
                        int& posicion) const; // Busca un usuario y además devuelve una copia de sus datos

    void mostrarLibrosDisponibles(
        const Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros) const; // Imprime solo los libros que no están prestados

    void mostrarTodosLosLibros(
        const Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros) const; // Imprime TODOS los libros, prestados o no

    void mostrarHistorialUsuario(
        const Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros,
        const Pila<Usuario, MAX_USUARIOS_REGISTRADOS>& usuarios,
        const std::string& dni) const; // Muestra los libros prestados a un usuario concreto

    void comprobarLibroDeUsuario(
        const Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros,
        const Pila<Usuario, MAX_USUARIOS_REGISTRADOS>& usuarios,
        const std::string& dni,
        int identificadorLibro) const; // Comprueba si un libro en concreto está prestado a ese usuario

    bool prestarLibro(
        Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros,
        Pila<Usuario, MAX_USUARIOS_REGISTRADOS>& usuarios,
        int identificadorLibro,
        const std::string& dni,
        std::string& mensaje); // Marca un libro como prestado a un usuario, si es posible

    bool devolverLibro(
        Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros,
        Pila<Usuario, MAX_USUARIOS_REGISTRADOS>& usuarios,
        int identificadorLibro,
        const std::string& dni,
        std::string& mensaje); // Marca un libro prestado como devuelto, si es posible

public:
    int ejecutarPrograma(
        Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros,
        Pila<Usuario, MAX_USUARIOS_REGISTRADOS>& usuarios); // Bucle principal: muestra el menú y ejecuta la opción elegida
};

#endif //PRIMERA_ACTIVIDAD_COLABORATIVA_PROGRAMA_H