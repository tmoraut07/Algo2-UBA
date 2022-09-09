#include <iostream>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    Fecha(int mes, int dia);
    int mes();
    int dia();
    void incrementar_dia();

    //#if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha o);
    //#endif

  private:
    int mes_;
    int dia_;
};
Fecha::Fecha(int mes, int dia) : mes_(mes), dia_(dia){};

int Fecha::mes(){
    return mes_;
}

int Fecha::dia(){
    return dia_;
}

void Fecha::incrementar_dia(){
    dia_++;
    if(dia_ > dias_en_mes(mes_)){
        dia_ = 1;
        mes_++;
    }if (mes_ > 12){
        mes_ = 1;
    }
}

ostream& operator<<(ostream& os, Fecha f){
    os << f.dia() << "/" << f.mes();
}

bool Fecha::operator==(Fecha o) {
    return (mes_ == o.mes() and
            dia_ == o.dia());
}

#if EJ >= 9
//bool Fecha::operator==(Fecha o) {
  //  bool igual_dia = this->dia() == o.dia();
    // Completar iguadad (ej 9)
    //return igual_dia;
//}
#endif

// Ejercicio 11, 12

// Clase Horario
class Horario {
    public:
        Horario(uint hora, uint min);

        uint hora();

        uint min();

        bool operator==(Horario o);

        bool operator<(Horario h);


private:

        uint h_;

        uint m_;
};
Horario::Horario(uint hora, uint min) : h_(hora), m_(min){};

uint Horario::hora(){
    return h_;
}

uint Horario::min(){
    return m_;
}
ostream& operator<<(ostream& os, Horario h){
    os << h.hora() << ":" << h.min();
}

bool Horario::operator==(Horario o) {
    return (h_ == o.hora() and
            m_ == o.min());
}

bool Horario::operator<(Horario h) {
    return(h_ < h.hora() or
            (h_ == h.hora() and m_ < h.min()));
}

// Ejercicio 13
class Recordatorio{
    public:

        Recordatorio(Fecha fecha, Horario hora, string mensaje);

        Fecha fecha();

        Horario hora();

        string mensaje();

    private:

    Fecha f_;

    Horario h_;

    string m_;

};

Recordatorio::Recordatorio(Fecha fecha, Horario hora, string mensaje) : m_(mensaje), f_(fecha), h_(hora) {}

Fecha Recordatorio::fecha(){
    return f_;
}

Horario Recordatorio::hora() {
    return h_;
}

string Recordatorio::mensaje() {
    return m_;
}

ostream& operator<<(ostream& os, Recordatorio r){
    os << r.mensaje() << " @ " << r.fecha() << " " << r.hora();
}

// Ejercicio 14

// Clase Agenda

class Agenda{
    public:
        Agenda(Fecha fecha_inicial);

        Fecha fecha_inicial();



};


