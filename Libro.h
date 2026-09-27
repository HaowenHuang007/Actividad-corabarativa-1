//
// Created by tihag on 27/09/2026.
//

#ifndef ACTIVIDADGRUPAL1_LIBRO_H
#define ACTIVIDADGRUPAL1_LIBRO_H

#include <string>

class Libro {
private:
    std::string titulo;
    std::string autor;
    std::string categoria; //accion, aventuras, drama...
    bool disponible;
    std::string dniUsuarioActual;//DNI de quien lo tiene prestado

public:
    Libro();
    Libro(const std::string &titulo, const std::string &autor, const std::string &categoria);

    //Getters
    std::string getTitulo()const;
    std::string getAutor()const;
    std::string getCategoria()const;
    bool isDisponible()const;
    std::string getDniUsuarioActual()const;

    //Acciones sobre el libro

    bool prestar(const std::string &dniUsuario);
    bool devolver();

    void mostrarInfo()const;
};


#endif //ACTIVIDADGRUPAL1_LIBRO_H
