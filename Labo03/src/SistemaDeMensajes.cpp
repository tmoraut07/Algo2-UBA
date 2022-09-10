#include "SistemaDeMensajes.h"
#include "Proxy.h"
using namespace std;

// Completar...
SistemaDeMensajes::SistemaDeMensajes() : _conns(){
    for(int i = 0; i < 4; i++){
        _conns[i] = nullptr;
    }
};

void SistemaDeMensajes::registrarJugador(int id, string ip) {
    if(_conns[id] == nullptr){
        _conns[id] = new ConexionJugador(ip);
    } else{
        _conns[id]->asignarIp(ip);
    }

}

bool SistemaDeMensajes::registrado(int id) const {
    return (_conns[id] != nullptr);
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje) {
    _conns[id]->enviarMensaje(mensaje);
    }

string SistemaDeMensajes::ipJugador(int id) const {
    return _conns[id]->ip();
}

void SistemaDeMensajes::desregistrarJugador(int id) {
    delete _conns[id];
    _conns[id] = nullptr;
}

Proxy* SistemaDeMensajes::obtenerProxy(int id){
    Proxy* p = new Proxy(_conns[id]);
    _proxys.push_back(p);
    return p;
}

SistemaDeMensajes::~SistemaDeMensajes() {
    for(int i = 0; i < 4; i++) {
        delete _conns[i];
    }
    for(Proxy* p : _proxys){
        delete p;
    }
}
