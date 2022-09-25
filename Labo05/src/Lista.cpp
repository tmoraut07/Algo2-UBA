#include "Lista.h"

Lista::Lista() : _primero(nullptr), _ultimo(nullptr){}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}


void Lista::destruirNodos(){
    Nodo* actual = _primero;
    while(actual != nullptr){
        Nodo* siguiente = actual->sig;
        delete actual;
        actual = siguiente;
    }
    _primero = nullptr;
    _ultimo = nullptr;
}

Lista::~Lista() {
    destruirNodos();
}


Lista& Lista::operator=(const Lista& aCopiar) {
    destruirNodos();
    Nodo* actual = aCopiar._primero;
    while(actual != nullptr){
        agregarAtras(actual->valor);
        actual = actual->sig;
    }
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    Nodo* nuevo = new Nodo(elem, _primero, nullptr);
    if (_primero == nullptr){
        _ultimo = nuevo;
    }
    else {
        _primero->ant = nuevo;
    }
    _primero = nuevo;
}


void Lista::agregarAtras(const int& elem) {
    Nodo* nuevo = new Nodo(elem, nullptr, _ultimo);
    if(_primero == nullptr){
        agregarAdelante(elem);
        delete nuevo;
    }else {
        _ultimo->sig = nuevo;
        nuevo->ant = _ultimo;
        _ultimo->sig = nuevo;
        _ultimo = nuevo;
    }
}


void Lista::eliminar(Nat i){
    Nodo* actual = _primero;
    if(i == 0){
        if (actual->sig == nullptr){
            _primero = nullptr;
            _ultimo = nullptr;
        }
        else {
            _primero = actual->sig;
        }
    } else if (actual == _ultimo){
        _ultimo = actual->ant;
    } else {
        for(int j = 0; j < i && actual->sig != nullptr; j++){
            actual = actual->sig;
        }
        actual->ant->sig = actual->sig;
    } delete actual;
}


int Lista::longitud() const {
    Nodo* actual = _primero;
    int contador = 0;
    while (actual != nullptr){
        contador++;
        actual = actual->sig;
    }
    return contador;
}

const int& Lista::iesimo(Nat i) const {
    Nodo* actual = _primero;
    for(int j = 0; j < i; j++){
        actual = actual->sig;
    }
    return actual->valor;
}

int& Lista::iesimo(Nat i) {
    Nodo* actual = _primero;
    for(int j = 0; j < i; j++){
        actual = actual->sig;
    }
    return actual->valor;
}

void Lista::mostrar(ostream& o) {
    // Completar
}
