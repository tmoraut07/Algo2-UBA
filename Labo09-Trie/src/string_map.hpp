template <typename T>
string_map<T>::string_map() : raiz(new Nodo(nullptr)), _size(0){}

// -------------------------------------------------------------------

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() {
    *this = aCopiar; 
} // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

// ----------------------------------------------------------------

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    Nodo* n = copiar(d.raiz, nullptr);
    int tam = d._size;
    this->raiz = n;
    this->_size = tam;
}
template<typename T>
typename string_map<T>::Nodo *string_map<T>::copiar(string_map::Nodo *aCopiar,string_map::Nodo* padre){
    T* ndef = aCopiar->definicion != nullptr ? new T(*aCopiar->definicion) : nullptr;
    Nodo* n = new Nodo(ndef, padre);
    n->siguientes = aCopiar->siguientes;
    for(int i = 0; i < 256; i++){
        if(n->siguientes[i] != nullptr)
            n->siguientes[i] = copiar(n->siguientes[i], n);
    }
    return n;
}
// -----------------------------------------------------------------

template <typename T>
string_map<T>::~string_map(){
    destruccion(raiz);
}

template<typename T>
void string_map<T>::destruccion(string_map::Nodo* actual) {
    if(actual != nullptr){
        delete actual->definicion;
        for(int i = 0; i < 256; i++){
            destruccion(actual->siguientes[i]);
        }
        delete actual;
    }
}

// ---------------------------------------------------------------
template <typename T>
T& string_map<T>::operator[](const string& clave){
    // COMPLETAR
}

// ----------------------------------------------------------------

template <typename T>
int string_map<T>::count(const string& clave) const{
	Nodo* actual = raiz;
	int i = 0;
    while(i < clave.size()){
		if(actual->siguientes[int(clave[i])] == nullptr){
			return 0;
		}
        actual = actual->siguientes[int(clave[i])];
        i++;
	}
    if(actual->definicion != nullptr){
        return 1;
    }
}

// -----------------------------------------------------------------

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    Nodo* actual = raiz;
    for(int i = 0; i < clave.size(); i++){
        int pos = int(clave[i]);
        actual = actual->siguientes[pos];
    }
    return *actual->definicion;
}

//------------------------------------------------------------------

template <typename T>
T& string_map<T>::at(const string& clave) {
    Nodo* actual = raiz;
    int i = 0;
    while (i < clave.size()){
        int pos = int(clave[i]);
        if (actual->siguientes[pos] == nullptr){
            actual->siguientes[pos] =  new Nodo(actual);
        }
        actual = actual->siguientes[pos];
        i++;
    }

    if (actual->definicion == nullptr)
        actual->definicion = new T();

    return *actual->definicion;
}

// -------------------------------------------------------------------

template <typename T>
void string_map<T>::insert(const pair<string, T>& p) {
    Nodo *actual = raiz;
    string clave = p.first;
    T* def = new T(p.second);
    int i = 0;
    while (i < clave.size()) {
        int pos = int(clave[i]);
        if (actual->siguientes[pos] == nullptr) {
            actual->siguientes[pos] = new Nodo(actual);
        }
            actual = actual->siguientes[pos];
        i++;
    }
    if (actual->definicion == nullptr) {
        _size++;
    }
    else{
        delete actual->definicion;
    }
    actual->definicion = def;
}

// ------------------------------------------------

template <typename T>
void string_map<T>::erase(const string& clave) {
    Nodo* actual = raiz;
    int i = 0;
    while(i < clave.size()){
        int pos = int(clave[i]);
        actual = actual->siguientes[pos];
        i++;
    }
    delete actual->definicion;
    actual->definicion = nullptr;

    while(actual->padre != nullptr){
        bool inutil = nodoInutil(actual);
        Nodo* par = actual->padre;
        if(inutil){
            for(int j = 0; j < 256; j++){
                if(actual->padre->siguientes[j] == actual)
                    actual->padre->siguientes[j] = nullptr;
            }
            delete actual;
        }
        actual = par;
    }
}


template<typename T>
bool string_map<T>::nodoInutil(string_map::Nodo* actual){
    Nodo* hijo;
    int hijos = 0;
    for(int j = 0; j < 256; j++){
        if(actual->siguientes[j] != nullptr){
            hijos++;
            hijo = actual->siguientes[j];
        }
    }
    if(hijos > 1){
        return false;
    }
    return(hijos == 0 && actual->definicion == nullptr) || (hijos == 1 && nodoInutil(hijo));
}

//---------------------------------------------------------------------


template <typename T>
int string_map<T>::size() const{
    return _size;
}

template <typename T>
bool string_map<T>::empty() const {
    return size() == 0;
}