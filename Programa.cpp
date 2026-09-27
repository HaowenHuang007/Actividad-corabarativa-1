//
// Created by Alejandro on 27/09/2026.
//

#include "Programa.h"

#include <iostream>
#include <limits>

int Programa::leerEntero(const std::string& mensaje)
{
    int valor;

    while (true)
    {
        std::cout << mensaje;

        if (std::cin >> valor)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return valor;
        }

        std::cout << "Entrada no valida. Escribe un numero.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::string Programa::leerTexto(const std::string& mensaje)
{
    std::string texto;
    std::cout << mensaje;
    std::getline(std::cin, texto);
    return texto;
}

void Programa::mostrarMenu()
{
    std::cout << "\n====================================\n";
    std::cout << "     SISTEMA DE BIBLIOTECA\n";
    std::cout << "====================================\n";
    std::cout << "1. Comprobar libros disponibles\n";
    std::cout << "2. Ver catalogo completo y estados\n";
    std::cout << "3. Ver historial de un usuario\n";
    std::cout << "4. Comprobar si un usuario tiene un libro\n";
    std::cout << "5. Sacar un libro\n";
    std::cout << "6. Devolver un libro\n";
    std::cout << "0. Salir\n";
}

bool Programa::buscarLibro(
    const Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros,
    int identificador,
    int& posicion) const
{
    for (int i = 0; i < libros.tamano(); i++)
    {
        Libro libro;
        libros.obtener(i, libro);

        if (libro.getIdentificador() == identificador)
        {
            posicion = i;
            return true;
        }
    }

    return false;
}

bool Programa::buscarUsuario(
    const Pila<Usuario, MAX_USUARIOS_REGISTRADOS>& usuarios,
    const std::string& dni,
    int& posicion) const
{
    for (int i = 0; i < usuarios.tamano(); i++)
    {
        Usuario usuario;
        usuarios.obtener(i, usuario);

        if (usuario.getDni() == dni)
        {
            posicion = i;
            return true;
        }
    }

    return false;
}

bool Programa::obtenerLibro(
    const Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros,
    int identificador,
    Libro& libro,
    int& posicion) const
{
    if (!buscarLibro(libros, identificador, posicion))
    {
        return false;
    }

    return libros.obtener(posicion, libro);
}

bool Programa::obtenerUsuario(
    const Pila<Usuario, MAX_USUARIOS_REGISTRADOS>& usuarios,
    const std::string& dni,
    Usuario& usuario,
    int& posicion) const
{
    if (!buscarUsuario(usuarios, dni, posicion))
    {
        return false;
    }

    return usuarios.obtener(posicion, usuario);
}

void Programa::mostrarLibrosDisponibles(
    const Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros) const
{
    bool hayDisponibles = false;

    std::cout << "\n--- Libros disponibles ---\n";

    for (int i = 0; i < libros.tamano(); i++)
    {
        Libro libro;
        libros.obtener(i, libro);

        if (libro.estaDisponible())
        {
            hayDisponibles = true;
            std::cout << "ID: " << libro.getIdentificador()
                      << " | " << libro.getTitulo()
                      << " | Categoria: " << libro.getCategoria() << "\n";
        }
    }

    if (!hayDisponibles)
    {
        std::cout << "No hay libros disponibles en este momento.\n";
    }
}

void Programa::mostrarTodosLosLibros(
    const Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros) const
{
    std::cout << "\n--- Catalogo de la biblioteca ---\n";

    for (int i = 0; i < libros.tamano(); i++)
    {
        Libro libro;
        libros.obtener(i, libro);

        std::cout << "ID: " << libro.getIdentificador()
                  << " | " << libro.getTitulo()
                  << " | Categoria: " << libro.getCategoria()
                  << " | Estado: ";

        if (libro.estaDisponible())
        {
            std::cout << "Disponible";
        }
        else
        {
            std::cout << "Prestado a " << libro.getDniPrestamo();
        }

        std::cout << "\n";
    }
}

void Programa::mostrarHistorialUsuario(
    const Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros,
    const Pila<Usuario, MAX_USUARIOS_REGISTRADOS>& usuarios,
    const std::string& dni) const
{
    Usuario usuario;
    int posicionUsuario;

    if (!obtenerUsuario(usuarios, dni, usuario, posicionUsuario))
    {
        std::cout << "No existe ningun usuario con ese DNI.\n";
        return;
    }

    std::cout << "\n--- Historial de " << usuario.getNombre() << " "
              << usuario.getApellidos() << " ---\n";

    std::cout << "Libros prestados actualmente: ";
    if (usuario.getCantidadLibrosActuales() == 0)
    {
        std::cout << "ninguno\n";
    }
    else
    {
        std::cout << "\n";
        for (int i = 0; i < usuario.getCantidadLibrosActuales(); i++)
        {
            int identificadorLibro;
            usuario.obtenerLibroActual(i, identificadorLibro);
            Libro libro;
            int posicionLibro;

            if (obtenerLibro(libros, identificadorLibro, libro, posicionLibro))
            {
                std::cout << "  - " << libro.getTitulo() << " (ID "
                          << libro.getIdentificador() << ")\n";
            }
        }
    }

    std::cout << "Historial de libros devueltos: ";
    if (usuario.getCantidadHistorial() == 0)
    {
        std::cout << "ninguno\n";
    }
    else
    {
        std::cout << "\n";
        for (int i = 0; i < usuario.getCantidadHistorial(); i++)
        {
            int identificadorLibro;
            usuario.obtenerLibroHistorial(i, identificadorLibro);
            Libro libro;
            int posicionLibro;

            if (obtenerLibro(libros, identificadorLibro, libro, posicionLibro))
            {
                std::cout << "  - " << libro.getTitulo() << " (ID "
                          << libro.getIdentificador() << ")\n";
            }
        }
    }
}

void Programa::comprobarLibroDeUsuario(
    const Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros,
    const Pila<Usuario, MAX_USUARIOS_REGISTRADOS>& usuarios,
    const std::string& dni,
    int identificadorLibro) const
{
    Usuario usuario;
    Libro libro;
    int posicionUsuario;
    int posicionLibro;

    if (!obtenerUsuario(usuarios, dni, usuario, posicionUsuario))
    {
        std::cout << "No existe ningun usuario con ese DNI.\n";
        return;
    }

    if (!obtenerLibro(libros, identificadorLibro, libro, posicionLibro))
    {
        std::cout << "No existe ningun libro con ese ID.\n";
        return;
    }

    if (usuario.tieneLibro(identificadorLibro))
    {
        std::cout << "El usuario tiene actualmente el libro: "
                  << libro.getTitulo() << ".\n";
    }
    else
    {
        std::cout << "El usuario no tiene actualmente el libro: "
                  << libro.getTitulo() << ".\n";
    }
}

bool Programa::prestarLibro(
    Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros,
    Pila<Usuario, MAX_USUARIOS_REGISTRADOS>& usuarios,
    int identificadorLibro,
    const std::string& dni,
    std::string& mensaje)
{
    Libro libro;
    Usuario usuario;
    int posicionLibro;
    int posicionUsuario;

    if (!obtenerLibro(libros, identificadorLibro, libro, posicionLibro))
    {
        mensaje = "No existe ningun libro con ese ID.";
        return false;
    }

    if (!obtenerUsuario(usuarios, dni, usuario, posicionUsuario))
    {
        mensaje = "No existe ningun usuario con ese DNI.";
        return false;
    }

    if (!libro.estaDisponible())
    {
        mensaje = "El libro no esta disponible. Lo tiene el DNI " + libro.getDniPrestamo() + ".";
        return false;
    }

    if (!usuario.agregarLibroActual(identificadorLibro))
    {
        mensaje = "El usuario ya tiene el libro o ha alcanzado el maximo de 5 prestamos.";
        return false;
    }

    libro.prestar(dni);
    libros.reemplazar(posicionLibro, libro);
    usuarios.reemplazar(posicionUsuario, usuario);
    mensaje = "Prestamo realizado correctamente.";
    return true;
}

bool Programa::devolverLibro(
    Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros,
    Pila<Usuario, MAX_USUARIOS_REGISTRADOS>& usuarios,
    int identificadorLibro,
    const std::string& dni,
    std::string& mensaje)
{
    Libro libro;
    Usuario usuario;
    int posicionLibro;
    int posicionUsuario;

    if (!obtenerLibro(libros, identificadorLibro, libro, posicionLibro))
    {
        mensaje = "No existe ningun libro con ese ID.";
        return false;
    }

    if (!obtenerUsuario(usuarios, dni, usuario, posicionUsuario))
    {
        mensaje = "No existe ningun usuario con ese DNI.";
        return false;
    }

    if (libro.estaDisponible())
    {
        mensaje = "El libro ya esta disponible; no hay ningun prestamo que devolver.";
        return false;
    }

    if (libro.getDniPrestamo() != dni || !usuario.tieneLibro(identificadorLibro))
    {
        mensaje = "Ese libro no esta prestado al usuario indicado.";
        return false;
    }

    if (!usuario.registrarDevolucion(identificadorLibro))
    {
        mensaje = "No se puede registrar la devolucion porque el historial esta lleno.";
        return false;
    }

    libro.devolver();
    libros.reemplazar(posicionLibro, libro);
    usuarios.reemplazar(posicionUsuario, usuario);
    mensaje = "Devolucion realizada correctamente.";
    return true;
}

int Programa::ejecutarPrograma(
    Pila<Libro, MAX_LIBROS_REGISTRADOS>& libros,
    Pila<Usuario, MAX_USUARIOS_REGISTRADOS>& usuarios)
{
    int opcion;

    do
    {
        mostrarMenu();
        opcion = leerEntero("Elige una opcion: ");

        switch (opcion)
        {
        case 1:
            mostrarLibrosDisponibles(libros);
            break;

        case 2:
            mostrarTodosLosLibros(libros);
            break;

        case 3:
        {
            std::string dni = leerTexto("DNI del usuario: ");
            mostrarHistorialUsuario(libros, usuarios, dni);
            break;
        }

        case 4:
        {
            std::string dni = leerTexto("DNI del usuario: ");
            int identificador = leerEntero("ID del libro: ");
            comprobarLibroDeUsuario(libros, usuarios, dni, identificador);
            break;
        }

        case 5:
        {
            int identificador = leerEntero("ID del libro que quieres sacar: ");
            std::string dni = leerTexto("DNI del usuario: ");
            std::string mensaje;
            prestarLibro(libros, usuarios, identificador, dni, mensaje);
            std::cout << mensaje << "\n";
            break;
        }

        case 6:
        {
            int identificador = leerEntero("ID del libro que quieres devolver: ");
            std::string dni = leerTexto("DNI del usuario: ");
            std::string mensaje;
            devolverLibro(libros, usuarios, identificador, dni, mensaje);
            std::cout << mensaje << "\n";
            break;
        }

        case 0:
            std::cout << "Programa finalizado.\n";
            break;

        default:
            std::cout << "Opcion no valida.\n";
            break;
        }
    } while (opcion != 0);

    return 0;
}
