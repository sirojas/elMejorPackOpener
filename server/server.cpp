#include "server.hpp"
using namespace :: std;
const String& Jugador::nombre() const {
    return nombre_;
}
double Jugador::oro() const{
    return oro_;
}
void Jugador::setNombre(String nombreNuevo){
    nombre_ = nombreNuevo;
}
void Jugador::setOro(double oroNuevo){
    oro_ = oroNuevo;
}
const vec<Carta>& Jugador::cartas() const{
    return cartas_;
}
bool Jugador::agregarCarta(const Carta& carta){
    if(cartas_.size() >= 128){
        cout << "maximo de cartas alcanzado" << endl;
        return false;
    }
    else{
        cartas_.push_back(carta);
        return true;
    }
}

const String& Carta::jugador() const{
    return jugador_;
}
int Carta::media() const{
    return media_;
}
rarezas Carta::rareza() const{
    return rareza_;
}
void Carta::setJugador(String jugadorNuevo){
    jugador_ = jugadorNuevo;
}
void Carta::setMedia(int mediaNueva){
    media_ = mediaNueva;
}
void Carta::setRareza(enum rarezas rarezaNueva){
    rareza_ = rarezaNueva;
}

const vec<Jugador>& Jugadores::jugadores(){
    return jugadores_;
}
bool Jugadores::setJugadores(vec<Jugador> jugadoresNuevos){
    if(jugadoresNuevos.size() >= 10){
        cout << "maximo de jugadores alcanzado"<< endl;
        return false;
    }
    else{
        jugadores_ = jugadoresNuevos;
        return true;
    }
} 
bool Jugadores::agregarJugador(Jugador jugador){
    if(jugadores_.size() >= 10){
        cout << "maximo de jugadores alcanzado" << endl;
        return false;
    }
    else{
        jugadores_.push_back(jugador);
        return true;
    }
}