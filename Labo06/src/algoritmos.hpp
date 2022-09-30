#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>

using namespace std;


//ejercicios 1 y 8
template<class Contenedor>
typename Contenedor::value_type minimo(const Contenedor& c){
    auto minimo = c.begin();
    for(auto it = c.begin(); it != c.end(); it++){
        if(*it < *minimo){
            minimo = it;
        }
    } return *minimo;
}


//ejercicio 2
template<class Contenedor>
typename Contenedor::value_type promedio(const Contenedor& c){
    auto suma = 0;
    int size = 0;
    for(auto x : c){
        suma = suma + x;
        size++;
    } return  double(suma) / double(size);
}


//ejercicio 3
template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator& desde, const Iterator& hasta){
    auto min = desde;
    for(auto it = desde; it != hasta; it++){
        if (*it < *min){
            min = it;
        }
    } return *min;
}


template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator& desde, const Iterator& hasta){
    auto suma = 0;
    int size = 0;
    for(auto it = desde; it != hasta; it++){
        suma = suma + *it;
        size++;
    } return double(suma) / double(size);
}


//ejercicio 4
template<class Contenedor>
void filtrar(Contenedor &c, const typename Contenedor::value_type& elem){
    auto it = c.begin();
    while (it != c.end()){
        if (*it == elem){
            it = c.erase(it);
        } else {
            it++;
        }
    }
}


//ejercicio 5
template<class Contenedor>
bool ordenado(Contenedor &c){
    bool res = true;
    auto anterior = *c.begin();
    for (auto x : c){
        if ( x < anterior){
            res = false;
        }
    } return res;
}


//ejercicio 6
template<class Contenedor>
std::pair<Contenedor, Contenedor>
split(const Contenedor & c,
      const typename Contenedor::value_type& elem){
    Contenedor menores;
    Contenedor mayores;

    auto it1 = menores.begin();
    auto it2 = mayores.begin();

    for(auto it : c){
    if(it < elem){
        it1 = menores.insert(it1, it);
        it1++;
    } else {
        it2 = mayores.insert(it2, it);
        it2++;
    }
 } return make_pair(menores, mayores);
}


//ejercicio 7
template <class Contenedor>
void merge(const Contenedor& c1, const Contenedor & c2, Contenedor & res){
    auto fin = res.end();
    auto it1 = c1.begin();
    auto it2 = c2.begin();

    while(it1 != c1.end() && it2 != c2.end()){
        if (*it1 < *it2){
            fin = res.insert(fin, *it1);
            it1++;
        } else {
            fin = res.insert(fin, *it2);
            it2++;
        } fin++;
    }

    if(it2 != c2.end()){
        while(it2 != c2.end()) {
            fin = res.insert(fin, *it2);
            it2++;
            fin++;
        }
    } else {
        while(it1 != c1.end()){
            fin = res.insert(fin, *it1);
            it1++;
            fin++;
        }
    }
}


//ejercicio 8
/*

*/
#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H
