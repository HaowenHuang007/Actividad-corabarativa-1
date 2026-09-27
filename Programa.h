//
// Created by Alejandro on 27/09/2026.
//

#ifndef PRIMERA_ACTIVIDAD_COLABORATIVA_PROGRAMA_H
#define PRIMERA_ACTIVIDAD_COLABORATIVA_PROGRAMA_H
#include <string>

#include "Libro.h"
#include "Pila.h"
#include "Usuario.h"

constexpr int MAX_LIBROS_REGISTRADOS = 20;
constexpr int MAX_USUARIOS_REGISTRADOS = 5;

class Programa
{
private:
    int leerEntero(const std::string& mensaje);
    std::string leerTexto(const std::string& mensaje);
    void mostrarMenu();

    bool buscarLibro(const Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros,
                     int identificador,
                     int& posicion) const;

    bool buscarUsuario(const Pila<Usuario, MAX_USUARIOS_REGISTRADOS>& usuarios,
                       const std::string& dni,
                       int& posicion) const;

    bool obtenerLibro(const Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros,
                      int identificador,
                      Libro& libro,
                      int& posicion) const;

    bool obtenerUsuario(const Pila<Usuario, MAX_USUARIOS_REGISTRADOS>& usuarios,
                        const std::string& dni,
                        Usuario& usuario,
                        int& posicion) const;

    void mostrarLibrosDisponibles(
        const Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros) const;

    void mostrarTodosLosLibros(
        const Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros) const;

    void mostrarHistorialUsuario(
        const Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros,
        const Pila<Usuario, MAX_USUARIOS_REGISTRADOS>& usuarios,
        const std::string& dni) const;

    void comprobarLibroDeUsuario(
        const Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros,
        const Pila<Usuario, MAX_USUARIOS_REGISTRADOS>& usuarios,
        const std::string& dni,
        int identificadorLibro) const;

    bool prestarLibro(
        Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros,
        Pila<Usuario, MAX_USUARIOS_REGISTRADOS>& usuarios,
        int identificadorLibro,
        const std::string& dni,
        std::string& mensaje);

    bool devolverLibro(
        Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros,
        Pila<Usuario, MAX_USUARIOS_REGISTRADOS>& usuarios,
        int identificadorLibro,
        const std::string& dni,
        std::string& mensaje);

public:
    int ejecutarPrograma(
        Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros,
        Pila<Usuario, MAX_USUARIOS_REGISTRADOS>& usuarios);
};

#endif //PRIMERA_ACTIVIDAD_COLABORATIVA_PROGRAMA_H
