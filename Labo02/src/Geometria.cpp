#include <iostream>

using namespace std;

using uint = unsigned int;

// Ejercicio 1

class Rectangulo {
    public:
        Rectangulo(uint alto, uint ancho);
        uint alto();
        uint ancho();
        float area();

    private:
        int _alto;
        int _ancho;

};

Rectangulo::Rectangulo(uint alto, uint ancho) : _alto(alto), _ancho(ancho) {};


uint Rectangulo::alto(){
    return _alto;
}
uint Rectangulo::ancho(){
    return _ancho;
}

// Completar definición: area
float Rectangulo::area(){
    return _alto * _ancho;
}
// Ejercicio 2

// Clase Elipse
float PI = 3.14;

class Elipse {
public:
    Elipse(uint a, uint b);

    uint r_a();

    uint r_b();

    float area();

private:
    uint a_;

    uint b_;
};
    Elipse::Elipse(uint a, uint b) : a_(a), b_(b) {};

    uint Elipse::r_a(){
        return a_;
    }
    uint Elipse::r_b(){
        return b_;
    }
    float Elipse::area(){
        return r_a() * r_b() *PI;
    }


// Ejercicio 3

class Cuadrado {
    public:
        Cuadrado(uint lado);
        uint lado();
        float area();

    private:
        Rectangulo _r;
};

Cuadrado::Cuadrado(uint lado): _r(lado, lado) {}

uint Cuadrado::lado() {
    return _r.ancho();
}

float Cuadrado::area() {
    return _r.area();
}

// Ejercicio 4

// Clase Circulo
class Circulo {
public:
    Circulo(uint radio);

    uint radio();

    float area();

private:
    uint r_;
};

Circulo::Circulo(uint radio) : r_(radio) {};

uint Circulo::radio() {
    return r_;
}

float Circulo::area() {
    return PI * r_ * r_;
}

// Ejercicio 5

ostream& operator<<(ostream& os, Rectangulo r) {
    os << "Rect(" << r.alto() << ", " << r.ancho() << ")";
    return os;
}

// ostream Elipse
ostream& operator<<(ostream& os, Elipse e){
    os << "Elipse(" << e.r_a() << ", " << e.r_b() <<")";
    return os;
}

// Ejercicio 6

ostream& operator<<(ostream& os, Cuadrado c){
    os << "Cuad(" << c.lado() << ")";
    return os;
}

ostream& operator<<(ostream& os, Circulo c){
    os << "Circ(" << c.radio() << ")";
    return os;
}