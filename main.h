//
// Created by Haowen on 27/09/2026.
//

#ifndef PRIMERA_ACTIVIDAD_COLABORATIVA_MAIN_H
#define PRIMERA_ACTIVIDAD_COLABORATIVA_MAIN_H
#include "Libro.h"
#include "Pila.h"
#include "Programa.h"
#include "Usuario.h"

void cargarDatosIniciales(
    Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros,
    Pila<Usuario, MAX_USUARIOS_REGISTRADOS>& usuarios);

#endif //PRIMERA_ACTIVIDAD_COLABORATIVA_MAIN_H
