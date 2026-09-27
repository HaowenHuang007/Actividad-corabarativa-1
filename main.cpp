//
// Created by Haowen on 27/09/2026.
//
#include "main.h"

void cargarDatosIniciales(
    Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros,
    Pila<Usuario, MAX_USUARIOS_REGISTRADOS>& usuarios)
{
    libros.apilar(Libro(1, "El principito", "Aventuras"));
    libros.apilar(Libro(2, "Viaje al centro de la Tierra", "Aventuras"));
    libros.apilar(Libro(3, "La isla del tesoro", "Aventuras"));
    libros.apilar(Libro(4, "Orgullo y prejuicio", "Romanticismo"));
    libros.apilar(Libro(5, "Romeo y Julieta", "Romanticismo"));
    libros.apilar(Libro(6, "Cien anos de soledad", "Drama"));
    libros.apilar(Libro(7, "La casa de los espiritus", "Drama"));
    libros.apilar(Libro(8, "Hamlet", "Drama"));
    libros.apilar(Libro(9, "El nombre de la rosa", "Misterio"));
    libros.apilar(Libro(10, "Asesinato en el Orient Express", "Misterio"));
    libros.apilar(Libro(11, "El hobbit", "Fantasia"));
    libros.apilar(Libro(12, "Harry Potter y la piedra filosofal", "Fantasia"));
    libros.apilar(Libro(13, "La historia interminable", "Fantasia"));
    libros.apilar(Libro(14, "1984", "Ciencia ficcion"));
    libros.apilar(Libro(15, "Fahrenheit 451", "Ciencia ficcion"));
    libros.apilar(Libro(16, "Yo, robot", "Ciencia ficcion"));
    libros.apilar(Libro(17, "Mortadelo y Filemon", "Comedia"));
    libros.apilar(Libro(18, "Tres sombreros de copa", "Comedia"));
    libros.apilar(Libro(19, "El diario de Greg", "Comedia"));
    libros.apilar(Libro(20, "Breve historia del tiempo", "Divulgacion"));

    usuarios.apilar(Usuario("Ana", "Garcia Lopez", "11111111A"));
    usuarios.apilar(Usuario("Bruno", "Martin Perez", "22222222B"));
    usuarios.apilar(Usuario("Carla", "Sanchez Ruiz", "33333333C"));
    usuarios.apilar(Usuario("Diego", "Fernandez Diaz", "44444444D"));
    usuarios.apilar(Usuario("Elena", "Gomez Torres", "55555555E"));
}

int main()
{
    Pila<Libro, MAX_LIBROS_REGISTRADOS> libros;
    Pila<Usuario, MAX_USUARIOS_REGISTRADOS> usuarios;
    Programa programa;

    cargarDatosIniciales(libros, usuarios);
    return programa.ejecutarPrograma(libros, usuarios);
}
