#include "C:\Users\Simón\Desktop\elMejorPackOpener\elMejorPackOpener\utils.hpp"
#include "cliente.hpp"
using namespace :: std;

bool inicioOk = false;
SOCKET conexion;
#define MIN 1
#define MAX 3
int main(){
    iniciarPrograma();
    Sleep(10000);
    return 0;
}

void iniciarPrograma(){
    crearHilos();
    



    shutdown(conexion, SD_BOTH);
    closesocket(conexion);
    WSACleanup();
}
void crearHilos(){
    std::thread hiloPantalla(pantalla);
    hiloPantalla.detach();
    std::thread hiloConexion(crearConexion);
    hiloConexion.join();
}
void pantalla(){
    pantallaCargaInicio();
    enum acciones input;
    /*do{
      pedirInput(input);
      switch (input)
      {
      case :
        
        break;
      
      default:
        break;
      }  
    } while (input != FIN);*/
    
}


void pantallaCargaInicio(){
    cout << setfill('-') << setw(70) << "" << endl;
    cout << setfill(' ') << endl;

    cout << "  ____   _    ____ _  __   ___  ____  _____ _   _  _____ ____  " << endl;
    cout << " |  _ \\ / \\  / ___| |/ /  / _ \\|  _ \\| ____| \\ | | ____|  _ \\ " << endl;
    cout << " | |_) / _ \\| |   | ' /  | | | | |_) |  _| |  \\| |  _| | |_) |" << endl;
    cout << " |  __/ ___ \\ |___| . \\  | |_| |  __/| |___| |\\  | |___|  _ < " << endl;
    cout << " |_| /_/   \\_\\____|_|\\_\\  \\___/|_|   |_____|_| \\_|_____|_| \\_\\" << endl;

    cout << endl;
    cout << "   BIENVENIDO AL MEJOR PACK OPENER, CARGANDO   " << endl; 
    cout << endl;

    cout << setfill('-') << setw(70) << "" << endl;
    cout << setfill(' ') << endl;

    const short dotsY = 9;
    short dotsX = 44; 
    int i = 0;
    while(true) {
        int k = i % 4; 
        gotoxy(dotsX, dotsY);
        cout << "   ";                 
        gotoxy(dotsX, dotsY);
        cout << string(k, '.');       
        Sleep(500);
        i++;
        if(inicioOk)
            break;
    } 
    dotsX = 36;
    gotoxy(dotsX,dotsY);
    cout << "Conexion establecida con exito" ;
    Sleep(1000);
}

void crearConexion(){
    auto config = readConfigKV("cliente.config");
    const char* host = config["host"].c_str();
    const char* port = config["port"].c_str();
    conexion = conectar(host,port);
    if(conexion == INVALID_SOCKET){
        cout << "Conexion invalida cerrando programa";
        abort();
    }
    randomWait(MIN,MAX);
    inicioOk = true;
}