//
// Created by Alejandro on 27/09/2026.
//

#ifndef ACTIVIDADGRUPAL1_LIBRO_H
#define ACTIVIDADGRUPAL1_LIBRO_H
#include <string>

class Libro
{
private:
    int identificador;
    std::string titulo;
    std::string categoria;
    bool disponible;
    std::string dniPrestamo;

public:
    Libro();
    Libro(int identificador, const std::string& titulo, const std::string& categoria);

    int getIdentificador() const;
    const std::string& getTitulo() const;
    const std::string& getCategoria() const;
    bool estaDisponible() const;
    const std::string& getDniPrestamo() const;

    void prestar(const std::string& dni);
    void devolver();
};
#endif //ACTIVIDADGRUPAL1_LIBRO_H
