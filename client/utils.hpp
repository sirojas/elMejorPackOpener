#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <thread>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <iomanip>
#include <unordered_map>

enum acciones{FIN};

extern bool inicioOk;
extern char* host;
extern char* port;

void iniciarPrograma();
void iniciaryleerConfig();
void crearHilos();
void pantalla();
void pantallaCargaInicio();
void clear();
void crearConexion();

#endif // UTILS_H