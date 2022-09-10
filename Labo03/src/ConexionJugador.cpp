#include "ConexionJugador.h"

ConexionJugador::ConexionJugador(string ip) : _ip(ip) {}

string ConexionJugador::ip() const {
  return _ip;
}

void ConexionJugador::enviarMensaje(string mensaje) {
  _internet->mensaje(_ip, mensaje);
}
 void ConexionJugador::asignarIp(std::string ip) {
    _ip = ip;
}