//
// Created by david on 27/09/2026.
//

#ifndef PRIMERA_ACTIVIDAD_COLABORATIVA_PILA_H
#define PRIMERA_ACTIVIDAD_COLABORATIVA_PILA_H


template <typename T, int N>
class Pila
{
private:
    T elementos[N]; // array donde guardamos los datos, de tamano fijo N
    int cantidad; // cuantos elementos hay metidos ahora mismo en la pila


public:
    // Constructor: cuando se crea la pila, empieza vacia
    Pila() : cantidad(0) {

    }

    // Indica si la pila esta vacia (no tiene ningun elemento)
    bool vacia() const
    {
        return cantidad == 0;
    }
    // Indica si la pila esta llena (ha llegado al tamano maximo N)
    bool llena() const
    {
        return cantidad >= N;
    }

    // Devuelve cuantos elementos hay guardados ahora mismo
    int tamano() const
    {
        return cantidad;
    }

    // Mete un elemento nuevo en la cima de la pila
    // Si la pila ya esta llena, no se puede meter nada mas
    void apilar(const T& elemento)
    {
        if (!llena())
        {
            // guardamos el elemento en la siguiente posicion libre
            elementos[cantidad] = elemento;
            cantidad++;
        }
    }

    // Saca el elemento que esta en la cima (el ultimo que se metio)
    // Si la pila esta vacia, no se puede sacar nada
    void desapilar()
    {
        // no hay nada que sacar
        if (!vacia())
        {
            // simplemente restamos 1 a la cantidad
            // el elemento sigue estando en el array, pero ya no cuenta como valido
            cantidad--;
        }
    }

    // Devuelve el elemento que esta en la cima, sin sacarlo de la pila
    // Si la pila esta vacia, devolvemos un valor "vacio" del tipo T
    T cima() const
    {
        if (vacia())
        {
            return T();
        }

        return elementos[cantidad - 1];
    }

    bool obtener(int posicion, T& elemento) const
    {
        if (posicion < 0 || posicion >= cantidad)
        {
            return false;
        }

        Pila<T, N> copia = *this;

        for (int i = 0; i < posicion; i++)
        {
            copia.desapilar();
        }

        elemento = copia.cima();
        return true;
    }

    bool reemplazar(int posicion, const T& elemento)
    {
        if (posicion < 0 || posicion >= cantidad)
        {
            return false;
        }

        Pila<T, N> temporal;

        for (int i = 0; i < posicion; i++)
        {
            temporal.apilar(cima());
            desapilar();
        }

        desapilar();
        apilar(elemento);

        while (!temporal.vacia())
        {
            apilar(temporal.cima());
            temporal.desapilar();
        }

        return true;
    }
};

#endif //PRIMERA_ACTIVIDAD_COLABORATIVA_PILA_H
