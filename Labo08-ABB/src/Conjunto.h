#ifndef CONJUNTO_H_
#define CONJUNTO_H_

#include <assert.h>
#include <string>
#include <iostream>

using namespace std;

template <class T>
class Conjunto
{
    public:

        // Constructor. Genera un conjunto vacío.
        Conjunto();

        // Destructor. Debe dejar limpia la memoria.
        ~Conjunto();

        // Inserta un elemento en el conjunto. Si este ya existe,
        // el conjunto no se modifica.
        void insertar(const T&);

        // Decide si un elemento pertenece al conjunto o no.
        bool pertenece(const T&) const;

        // Borra un elemento del conjunto. Si este no existe,
        // el conjunto no se modifica.
        void remover(const T&);

        // Siguiente elemento al recibido por párametro, en orden.
        // Pre: el elemento está en el conjunto y no es el máximo del conjunto.
        const T& siguiente(const T& elem);

        // Devuelve el mínimo elemento del conjunto según <.
        const T& minimo() const;

        // Devuelve el máximo elemento del conjunto según <.
        const T& maximo() const;

        // Devuelve la cantidad de elementos que tiene el conjunto.
        unsigned int cardinal() const;

        // Muestra el conjunto.
        void mostrar(std::ostream&) const;





    private:

        /**
         * Completar con lo que sea necesario...
         **/

        struct Nodo
        {
            T valor;
            Nodo* izq;
            Nodo* der;
            Nodo(const T& v) :
            valor(v), izq(nullptr), der(nullptr){
            }
        };

        // Puntero a la raíz de nuestro árbol.
        Nodo* _raiz;

        int contador = 0;

        Nodo* insertarAux(const T&, Nodo* a);

        T&  minAux(Nodo* a) const;

        T&  maxAux(Nodo* a) const;

        unsigned int _cardinal(int count, Nodo* a) const;

       void destructorAux(Nodo* a);

	void removerAux(Nodo* actual, Nodo* nuevo, Nodo* padre);
};

template<class T>
std::ostream& operator<<(std::ostream& os, const Conjunto<T>& c) {
	 c.mostrar(os);
	 return os;
}

#include "Conjunto.hpp"

#endif // CONJUNTO_H_
