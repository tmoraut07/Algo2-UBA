
template <class T>
Conjunto<T>::Conjunto() : _raiz(nullptr){
}

//--------------------------------------


template <class T>
Conjunto<T>::~Conjunto() { 
    // Completar
}

//-----------------------------------------------


template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    Nodo* actual = _raiz;
    while(actual != nullptr && (actual->valor) != clave){
        if(clave < actual->valor){
            actual = actual->izq;
        }
        else{
            actual = actual->der;
        }
    }
    return (actual != nullptr);
}

//------------------------------------------


template <class T>
void Conjunto<T>::insertar(const T& clave) {
    _raiz = insertarAux(clave, _raiz);
    contador++;
}

//------------------------------------


template <class T>
typename Conjunto<T>::Nodo* Conjunto<T>::insertarAux(const T& clave, Nodo* a){
    if(a == nullptr){
        return new Nodo(clave);
    }
    else if(clave < a->valor){
        a->izq = insertarAux(clave, a->izq);
        return a;
    }
    else{
        a->der = insertarAux(clave, a->der);
        return a;
    }
}

//---------------------------------------------


template <class T>
void Conjunto<T>::remover(const T& clave) {
    Nodo* actual = _raiz;
    Nodo* padre;

    while(actual->valor != clave){
        padre = actual;
        if(actual->valor < clave){
            actual = actual->izq;
        } else
        {
            actual = actual->der;
        }
    }

    if(actual->izq == nullptr && actual->der == nullptr){
        if(actual == padre->der){
            padre->der = nullptr;
            delete actual;
        }
        else{
            padre->izq = nullptr;
            delete actual;
        }
    }

    else{
        if(actual->der == nullptr && actual->izq != nullptr){

        }
    }

}

//-------------------------------------------------


template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    vector<Nodo*> ancestros;
    Nodo* actual = _raiz;
    Nodo* sig;

    while(actual->valor != clave){
        ancestros.push_back(actual);
        if(actual->valor < clave){
            actual = actual->izq;
        } else {
            actual = actual->der;
        }
    }

    if(actual->der != nullptr) {
        sig = _raiz->der;
        while (sig->izq != nullptr) {
            sig = sig->izq;
        }
        return sig->valor;
    }

    else{
        if (ancestros[ancestros.size()-1]->izq == actual){
            return ancestros[ancestros.size()-1];
        }
        else{
            while(ancestros[ancestros.size()-1]->izq != actual){
                actual = ancestros[ancestros.size()-1];
                ancestros.pop_back();
            }
            return ancestros[ancestros.size()-1];
        }
    }

}

//------------------------------------------------


template <class T>
const T& Conjunto<T>::minimo() const {
    Nodo* actual = _raiz;
    while(actual->izq != nullptr){
        actual = actual-> izq;
    }
    return actual->valor;
}

//-----------------------------------------


template <class T>
const T& Conjunto<T>::maximo() const {
    Nodo* actual = _raiz;
    while(actual->der != nullptr){
        actual = actual-> der;
    }
    return actual->valor;
}

//----------------------------------------


template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return contador;
}

//------------------------------------------


template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

