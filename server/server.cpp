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



const UnorderedMap& Jugadores::jugadores()const{
    return jugadores_;
}
bool Jugadores::setJugadores(UnorderedMap jugadoresNuevos){
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
        jugadores_[jugador.nombre()] = jugador;
        return true;
    }
}

int Jugadores::cantidadJugadores()const{
    return jugadores_.size();
}