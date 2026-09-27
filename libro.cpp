//
// Created by Alejandro on 27/09/2026.
//

#include "libro.h"
Libro::Libro()
    : identificador(0), titulo(""), categoria(""), disponible(true), dniPrestamo("")
{
}

Libro::Libro(int identificador, const std::string& titulo, const std::string& categoria)
    : identificador(identificador), titulo(titulo), categoria(categoria), disponible(true), dniPrestamo("")
{
}

int Libro::getIdentificador() const
{
    return identificador;
}

const std::string& Libro::getTitulo() const
{
    return titulo;
}

const std::string& Libro::getCategoria() const
{
    return categoria;
}

bool Libro::estaDisponible() const
{
    return disponible;
}

const std::string& Libro::getDniPrestamo() const
{
    return dniPrestamo;
}

void Libro::prestar(const std::string& dni)
{
    disponible = false;
    dniPrestamo = dni;
}

void Libro::devolver()
{
    disponible = true;
    dniPrestamo = "";
}