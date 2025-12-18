#ifndef SERVER_H
#define SERVER_H
#include "C:\Users\Simón\Desktop\elMejorPackOpener\elMejorPackOpener\utils.hpp"

using String = std::string;
template <typename T>
using vec = std::vector<T>;
using FStream = std::fstream;
extern FStream archivoMaestro;

enum rarezas{COMUN,EPICA,SUPEREPICA,LEGENDARIA};
class Carta{
    public:
        Carta(String jugador, int media,enum rarezas rareza);
        const String& jugador() const;
        int media() const;
        rarezas rareza() const;
        void setJugador(String jugadorNuevo);
        void setMedia(int mediaNueva);
        void setRareza(enum rarezas rarezaNueva);
    private:
        String jugador_;
        int media_;
        enum rarezas rareza_;
};

class Jugador{
    public:
        Jugador(String nombre, double oro, vec<Carta> cartas);
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
        Jugadores(vec<Jugador> jugadores);
        const vec<Jugador>& jugadores();
        bool setJugadores(vec<Jugador> jugadoresNuevos);
        bool agregarJugador(Jugador jugador);
    private:
        vec<Jugador> jugadores_;
};

void iniciarServidor();
void pantallaInicio();
void recuperarInfo();
void iniciarConexiones();

#endif // SERVER_H