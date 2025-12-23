#ifndef CLIENTE_H
#define CLIENTE_H

#include "C:\Users\Simón\Desktop\elMejorPackOpener\elMejorPackOpener\utils.hpp"


enum acciones{FIN};
extern bool inicioOk;
extern SOCKET conexion;
extern String usuario;

//posible clientes.h
void iniciarPrograma();
void crearHilos();
void pantalla();
void pantallaCargaInicio();
void crearConexion();
//------------------------


#endif // CLIENTE_H