#include <iostream>
#include "Libro.h"
#include "Usuario.h"

int main() {
    Libro libro1("El Quijote", "Miguel de Cervantes", "drama");
    Libro libro2("El senor de los anillos", "J.R.R. Tolkien", "aventuras");

    Usuario usuario1("Ana", "Garcia Lopez", "12345678A");
    Usuario usuario2("Luis", "Martinez Ruiz", "87654321B");

    std::cout << "--- Estado inicial ---" << std::endl;
    libro1.mostrarInfo();
    libro2.mostrarInfo();

    std::cout << std::endl << "--- Ana saca 'El Quijote' ---" << std::endl;
    usuario1.sacarLibro(&libro1);
    libro1.mostrarInfo();

    std::cout << std::endl << "--- Luis intenta sacar 'El Quijote' (ya prestado) ---" << std::endl;
    bool exito = usuario2.sacarLibro(&libro1);
    std::cout << "¿Consiguio sacarlo? " << (exito ? "si" : "no") << std::endl;

    std::cout << std::endl << "--- Luis saca 'El senor de los anillos' ---" << std::endl;
    usuario2.sacarLibro(&libro2);

    std::cout << std::endl << "--- Libros actuales de cada usuario ---" << std::endl;
    usuario1.mostrarLibrosActuales();
    usuario2.mostrarLibrosActuales();

    std::cout << std::endl << "--- Ana devuelve 'El Quijote' ---" << std::endl;
    usuario1.devolverLibro(&libro1);
    libro1.mostrarInfo();
    usuario1.mostrarLibrosActuales();

    std::cout << std::endl << "--- Historial de Ana (se mantiene tras devolver) ---" << std::endl;
    usuario1.mostrarHistorial();

    return 0;
}