//
// Created by ACER NITRO on 27/09/2026.
//

#ifndef ACTIVIDADGRUPAL1_USUARIO_H
#define ACTIVIDADGRUPAL1_USUARIO_H
#include <string>

class Usuario {
private:
    //Crearemos estas constantes estaticas
    //que definen los límites de las pilas.
    static const int MAX_LIBROS_ACTUALES = 5;
    static const int MAX_HISTORIAL = 50;

    //Atributos de Usuario
    std::string nombre;
    std::string apellidos;
    std::string dni;

    //Usando la Pila para gestionar
    // los identificadores de los libros de la libreria
    Pila<int, MAX_LIBROS_ACTUALES> librosActuales; //libros que el usuario tiene prestados ahora mismo
    Pila<int, MAX_HISTORIAL> historialLibros;      //registro histórico de libros devueltos

public:
    //contrusctores
    Usuario(); //constructor por defecto
    Usuario(const std::string& nombre, const std::string& apellidos, const std::string& dni); //y constructor parametrizado

    //Aqui tenemos los getters (constantes porq no modifican el objeto)
    const std::string& getNombre() const;
    const std::string& getApellidos() const;
    const std::string& getDni() const;

    //Los metodos de gestion de los libros
    bool tieneLibro(int identificadorLibro) const; //Comprueba si un usuario tiene prestado un libro en especifico
    bool agregarLibroActual(int identificadorLibro); //Presta un libro al usuario
    bool registrarDevolucion(int identificadorLibro); //Devuelve el prestado y lo pasa al historial

    //Con estos metodos accedemos a los datos de la pila (simulando un acceso por indice)
    int getCantidadLibrosActuales() const;
    bool obtenerLibroActual(int posicion, int& identificadorLibro) const;
    int getCantidadHistorial() const;
    bool obtenerLibroHistorial(int posicion, int& identificadorLibro) const;

};


#endif //ACTIVIDADGRUPAL1_USUARIO_H