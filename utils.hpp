#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <thread>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <iomanip>
#include <unordered_map>
#include <fstream>
#include <string>
#include <random>
#include <vector>

enum rarezas{COMUN,EPICA,SUPEREPICA,LEGENDARIA};
class Carta{
    public:
        Carta(String jugador, int media,enum rarezas rareza, double valor);
        const String& jugador() const;
        int media() const;
        rarezas rareza() const;
        double valor() const;
        void setJugador(String jugadorNuevo);
        void setMedia(int mediaNueva);
        void setRareza(enum rarezas rarezaNueva);
        void setValor(double valorNuevo);
    private:
        String jugador_;
        int media_;
        enum rarezas rareza_;
        double valor_;
};

void clear();
void gotoxy(short x, short y);
std::unordered_map<std::string, std::string> readConfigKV(const std::string& path);
SOCKET conectar(const char* host, const char* port);
void randomWait(int min,int max);

#endif // UTILS_H