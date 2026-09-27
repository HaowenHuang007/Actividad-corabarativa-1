//
// Created by tihag on 27/09/2026.
//

#ifndef PRIMERA_ACTIVIDAD_COLABORATIVA_LIBRO_H
#define PRIMERA_ACTIVIDAD_COLABORATIVA_LIBRO_H
#include <string>

class Libro
{
private:
    int identificador;
    std::string titulo;
    std::string categoria; //accion, aventuras, drama...
    bool disponible;
    std::string dniPrestamo; //DNI de quien lo tiene prestado

public:
    Libro();
    Libro(int identificador, const std::string& titulo, const std::string& categoria);

    int getIdentificador() const;
    const std::string& getTitulo() const;
    const std::string& getCategoria() const;
    bool estaDisponible() const;
    const std::string& getDniPrestamo() const;
    
    //Acciones sobre el libro

    void prestar(const std::string& dni);
    void devolver();
};

#endif //PRIMERA_ACTIVIDAD_COLABORATIVA_LIBRO_H
