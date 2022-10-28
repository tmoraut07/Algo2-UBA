template <typename T>
string_map<T>::string_map() : raiz(new Nodo()), _size(0){

}

// -------------------------------------------------------------------

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

// ----------------------------------------------------------------

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    // COMPLETAR
}

// -----------------------------------------------------------------

template <typename T>
string_map<T>::~string_map(){
    // COMPLETAR
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
	int apariciones = 0;
	for(int i = 0; i < clave.size()-1;i++){
		//char j = clave[i];
		if(actual->siguientes[int(clave[i])] != nullptr){
			actual = actual->siguientes[int(clave[i])];
		}
	}
	if(actual->definicion != nullptr){
		apariciones ++;
	} return apariciones;
}

// -----------------------------------------------------------------

template <typename T>
const T& string_map<T>::at(const string& clave) const {

}

//------------------------------------------------------------------

template <typename T>
T& string_map<T>::at(const string& clave) {
    // COMPLETAR
}

// -----------------------------------------

template <typename T>
void string_map<T>::insert(const pair<string, T>& p){
	Nodo* actual = raiz;
	string clave = p.first;
	T* def = new T(p.second);
	int i = 0;
	while(i < clave.size()-1){
		if(actual->siguientes[int(clave[i])] != nullptr){
			actual = actual->siguientes[int(clave[i])];
			i++;
		} else {
			actual->siguientes[int(clave[i])] = new Nodo();
			actual = actual->siguientes[int(clave[i])];
			i++;
		}
	} if(actual->definicion == nullptr){
		_size ++;
	}
	actual->definicion = def;
}

// ------------------------------------------------

template <typename T>
void string_map<T>::erase(const string& clave) {
    Nodo* ultimoUtil = raiz;


}

template <typename T>
int string_map<T>::size() const{
    // COMPLETAR
}

template <typename T>
bool string_map<T>::empty() const{
	return size() == 0;
}