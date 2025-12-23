#ifndef SERVER_H
#define SERVER_H
#include "C:\Users\Simón\Desktop\elMejorPackOpener\elMejorPackOpener\utils.hpp"

using String = std::string;
template <typename T>
using vec = std::vector<T>;
using FStream = std::fstream;

extern FStream archivoMaestro;
extern SOCKET socketEscucha;


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
using UnorderedMap = std::unordered_map<String,Jugador>;

class Jugadores{
    public: 
    Jugadores(UnorderedMap jugadores);
    Jugadores() {jugadores_.reserve(10);}
    const UnorderedMap& jugadores()const;
    bool setJugadores(UnorderedMap jugadoresNuevos);
    bool agregarJugador(Jugador jugador);
    int cantidadJugadores()const;
    private:
    UnorderedMap jugadores_;
};
extern Jugadores jugadores;

void iniciarServidor();
void pantallaInicio();
void recuperarInfo();
void iniciarConexiones();
void leerStringU8(std::string& out);
void leerUnJugador(String& nombre, double& oro, vec<Carta>& cartas);
void gestionarServer(SOCKET socket, String usuario);
bool iniciarListener(const char* port);
bool aceptarConexion(SOCKET& socketNuevo);
String handshake(SOCKET socket);
void cerrarListener();
Carta leerUnaCarta();
#endif // SERVER_H