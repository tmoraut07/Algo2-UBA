
template <class T>
Conjunto<T>::Conjunto() : _raiz(nullptr){
}

//--------------------------------------


template <class T>
Conjunto<T>::~Conjunto() {
    destructorAux(_raiz);
}
template<class T>
void Conjunto<T>::destructorAux(Nodo* a){
    if (a != nullptr){
        destructorAux(a->izq);
        destructorAux(a->der);
        delete a;
    }
}

//-----------------------------------------------


template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    Nodo* actual = _raiz;
    while(actual != nullptr && actual->valor != clave){
        if(clave < actual->valor){
            actual = actual->izq;
        }
        else {
            actual = actual->der;
        }
    }
    return (actual != nullptr);
}

//------------------------------------------


template <class T>
void Conjunto<T>::insertar(const T& clave) {
    _raiz = insertarAux(clave, _raiz);
}


template <class T>
typename Conjunto<T>::Nodo* Conjunto<T>::insertarAux(const T& clave, Nodo* a){
    if(a == nullptr){
        return new Nodo(clave);
    }
    else if(clave < a->valor){
        a->izq = insertarAux(clave, a->izq);
        return a;
    }
    else if (clave > a->valor){
        a->der = insertarAux(clave, a->der);
        return a;
    } else{
		return a;
	}
}

//---------------------------------------------

template <class T>
void Conjunto<T>::remover(const T& clave) {
    bool menor = false;
    Nodo* padre = nullptr;
    Nodo* act = _raiz;
    while (act != nullptr && act->valor != clave){
        padre = act;
        menor = clave < act->valor;
        act = menor ? act->izq : act->der;
    }

    if (act->valor != clave){ return; }//no esta el nodo que se quiere eliminar

    if (act->izq == nullptr && act->der == nullptr){
        if (act == _raiz){
            //no tiene hijos
            _raiz = nullptr;
        } else{
            if (menor){
                padre->izq = nullptr;
            } else{
                padre->der = nullptr;
            }
        }
        delete act;
    } else{
        if (act->izq != nullptr && act->der != nullptr){
            //caso dos hijos

            //sube el valor minimo del subabrbol derecho a la posicion del nodo eliminado
            T min = minAux(act->der);
            remover(min);
            act->valor = min;
            //contador--;
        } else{
            //caso un solo hijo
            Nodo* hijo = (act->izq != nullptr) ? act->izq : act->der;

            if (act == _raiz){
                _raiz = hijo;
            } else{
                if (menor){
                    padre->izq = hijo;
                } else{
                    padre->der = hijo;
                }
            }
            delete act;

        }
    }
}

//-------------------------------------------------


template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    vector<Nodo*> ancestros;
    Nodo* actual = _raiz;
    //Nodo* sig;

    while(actual != nullptr && actual->valor != clave){
        ancestros.push_back(actual);
        if(actual->valor < clave){
            actual = actual->der;
        } else {
            actual = actual->izq;
        }
    }

    if(actual->der != nullptr) {
        Nodo* aux = actual->der;
        while(aux->izq != nullptr){
            aux = aux->izq;
        }
        return aux->valor;
    }

    else{
        if (ancestros[ancestros.size()-1]->izq == actual){
            return ancestros[ancestros.size()-1]->valor;
        }
        else{
            while(ancestros[ancestros.size()-1]->izq != actual){
                actual = ancestros[ancestros.size()-1];
                ancestros.pop_back();
            }
            return ancestros[ancestros.size()-1]->valor;
        }
    }
}

//------------------------------------------------
template <class T>
T& Conjunto<T>::minAux(Nodo *a) const{
    while(a->izq != nullptr){
        a = a->izq;
    }
    return a->valor;
}



template <class T>
const T& Conjunto<T>::minimo() const {
    Nodo* actual = _raiz;
    while(actual->izq != nullptr){
        actual = actual-> izq;
    }
    return actual->valor;
}

//-----------------------------------------
template<class T>
T& Conjunto<T>::maxAux(Nodo *a) const{
    while(a->der != nullptr){
        a = a->der;
    }
    return a->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    Nodo* actual = _raiz;
    while(actual->der != nullptr){
        actual = actual-> der;
    }
    return actual->valor;
}

//----------------------------------------
template<class T>
unsigned int Conjunto<T>::_cardinal(int count, Nodo *a) const {
    if(a == nullptr) {
        return 0;
    }
    return count + _cardinal(count,a->izq) + _cardinal(count,a->der) + 1;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return _cardinal(0,_raiz);
}

//------------------------------------------


template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

