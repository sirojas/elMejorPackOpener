#ifndef SERVER_H
#define SERVER_H
#include "C:\Users\Simón\Desktop\elMejorPackOpener\elMejorPackOpener\utils.hpp"

using String = std::string;
template <typename T>
using vec = std::vector<T>;
using FStream = std::fstream;
using UnorderedMap = std::unordered_map<String,Jugador>;

extern FStream archivoMaestro;
extern Jugadores jugadores;


class Jugador{
    public:
        Jugador(String nombre = "", double oro = 0.0 , vec<Carta> cartas = {});
        const String& nombre() const;
        double oro() const;
        void setNombre(String nombreNuevo);
        void setOro(double oroNuevo);
        const vec<Carta>& cartas() const;
        bool agregarCarta(const Carta& carta);
    private:
        String nombre_;
        double oro_;
        vec<Carta> cartas_;
};

class Jugadores{
    public: 
        Jugadores(UnorderedMap jugadores);
        const UnorderedMap& jugadores()const;
        bool setJugadores(UnorderedMap jugadoresNuevos);
        bool agregarJugador(Jugador jugador);
        int cantidadJugadores()const;
    private:
        UnorderedMap jugadores_;
};

void iniciarServidor();
void pantallaInicio();
void recuperarInfo();
void iniciarConexiones();
void leerStringU8(std::string& out);
void leerUnJugador(string& nombre, double& oro, vec<Carta>& cartas);
Carta leerUnaCarta();
#endif // SERVER_H