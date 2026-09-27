//
// Created by david on 27/09/2026.
//

#ifndef PILA_H
#define PILA_H

template <typename T, int N>
class Pila {

private:
    T elementos[N];   // array donde guardamos los datos, de tamano fijo N
    int cantidad;      // cuantos elementos hay metidos ahora mismo en la pila

public:

    // Constructor: cuando se crea la pila, empieza vacia
    Pila() {
        cantidad = 0;
    }

    // Indica si la pila esta vacia (no tiene ningun elemento)
    bool vacia() {
        if (cantidad == 0) {
            return true;
        }
        return false;
    }

    // Indica si la pila esta llena (ha llegado al tamano maximo N)
    bool llena() {
        if (cantidad == N) {
            return true;
        }
        return false;
    }

    // Devuelve cuantos elementos hay guardados ahora mismo
    int tamano() {
        return cantidad;
    }

    // Mete un elemento nuevo en la cima de la pila
    // Si la pila ya esta llena, no se puede meter nada mas
    bool apilar(T elemento) {
        if (llena()) {
            // no hay hueco, no se puede apilar
            return false;
        }

        // guardamos el elemento en la siguiente posicion libre
        elementos[cantidad] = elemento;
        cantidad = cantidad + 1;

        return true;
    }

    // Saca el elemento que esta en la cima (el ultimo que se metio)
    // Si la pila esta vacia, no se puede sacar nada
    bool desapilar() {
        if (vacia()) {
            // no hay nada que sacar
            return false;
        }

        // simplemente restamos 1 a la cantidad
        // el elemento sigue estando en el array, pero ya no cuenta como valido
        cantidad = cantidad - 1;

        return true;
    }

    // Devuelve el elemento que esta en la cima, sin sacarlo de la pila
    // Si la pila esta vacia, devolvemos un valor "vacio" del tipo T
    T cima() {
        if (vacia()) {
            return T();
        }

        return elementos[cantidad - 1];
    }

};

#endif
