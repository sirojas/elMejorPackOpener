#include "C:\Users\Simón\Desktop\elMejorPackOpener\elMejorPackOpener\utils.hpp"
#include "server.hpp"
using namespace :: std;
using std::fstream;
using std::thread;
fstream archivoMaestro;
Jugadores jugadores;
SOCKET socketEscucha = INVALID_SOCKET;

int main(){
    iniciarServidor();
    

    
    return 0;
}
void iniciarServidor(){
    pantallaInicio();
    recuperarInfo();
    iniciarListener("7777");
    thread conexiones(iniciarConexiones);
    conexiones.join();    //join por ahora cuando haya funcion para cerrar el server es detach
}
void pantallaInicio(){
    cout << setfill('-') << setw(70) << "" << endl;
    cout << setfill(' ') << endl;

    cout << "  ____   _    ____ _  __   ___  ____  _____ _   _  _____ ____  " << endl;
    cout << " |  _ \\ / \\  / ___| |/ /  / _ \\|  _ \\| ____| \\ | | ____|  _ \\ " << endl;
    cout << " | |_) / _ \\| |   | ' /  | | | | |_) |  _| |  \\| |  _| | |_) |" << endl;
    cout << " |  __/ ___ \\ |___| . \\  | |_| |  __/| |___| |\\  | |___|  _ < " << endl;
    cout << " |_| /_/   \\_\\____|_|\\_\\  \\___/|_|   |_____|_| \\_|_____|_| \\_\\" << endl;

    cout << endl;
    cout << "   INICIANDO SERVIDOR DEL PACK OPENER, CARGANDO   " << endl; 
    cout << endl;

    cout << setfill('-') << setw(70) << "" << endl;
    cout << setfill(' ') << endl;

    const short dotsY = 9;
    short dotsX = 47; 
    for(int i = 0; i < 7; i++){
        int k = i % 4; 
        gotoxy(dotsX, dotsY);
        cout << "   ";                 
        gotoxy(dotsX, dotsY);
        cout << string(k, '.');       
        Sleep(500);
    }
    gotoxy(0,12);
    cout <<  "Servidor iniciado con exito" ;
    Sleep(1000);
}
void recuperarInfo(){
    //abrir el archivo binario mapeado por nombre de jugador, que contiene oro y cartas[128]
    // el archivo consta de un uint8 que dice cuantos jugadores hay, y los jugadores serializados
     archivoMaestro.open("jugadores.bin", ios::in | ios::out | ios::binary);
    if (!archivoMaestro){
        std::ofstream create("jugadores.bin", ios::binary);
        create.close();
        archivoMaestro.open("jugadores.bin", ios::in | ios::out | ios::binary);
    }
    uint8_t cantidad;
    if(!archivoMaestro.read((char*)&cantidad,sizeof(cantidad)))
        cantidad = 0;
    String nombre;
    double oro;
    vec<Carta> cartas;
    for(int i = 0; i < cantidad; i++){
        leerUnJugador(nombre,oro,cartas);
        Jugador player(nombre,oro,move(cartas));
        jugadores.agregarJugador(player);
        cartas.clear();
    }
    cout << "Informacion recuperada con exito, cantidad de jugadores que hay: " << jugadores.cantidadJugadores() << endl;
}
void leerStringU8(std::string& out) {
    uint8_t len = 0;
    archivoMaestro.read(reinterpret_cast<char*>(&len), sizeof(len));

    out.resize(len);
    if (len > 0) {
        archivoMaestro.read(out.data(), len);
    }
}

Carta leerUnaCarta(){
    //Carta(String jugador, int media,enum rarezas rareza, double valor);
    string jugador;
    int32_t media;
    enum rarezas rareza;
    double valor;
    leerStringU8(jugador);
    archivoMaestro.read((char*)&media,sizeof(media));
    archivoMaestro.read((char*)&rareza,sizeof(rareza));
    archivoMaestro.read((char*)&valor,sizeof(valor));
    return Carta(jugador,media,rareza,valor);
}

void leerUnJugador(string& nombre, double& oro, vec<Carta>& cartas){
    uint8_t cantidadCartas;
    leerStringU8(nombre);
    archivoMaestro.read((char*)&oro,sizeof(oro));
    archivoMaestro.read((char*)&cantidadCartas,sizeof(cantidadCartas));
    cartas.clear();
    cartas.reserve(cantidadCartas);
    for(int i = 0; i < cantidadCartas; i++){
        cartas.push_back(leerUnaCarta());
    }
}
bool iniciarListener(const char* port) {
    WSADATA wsa{};
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        std::cerr << "WSAStartup fallo: " << WSAGetLastError() << "\n";
        return false;
    }

    addrinfo hints{};
    hints.ai_family   = AF_INET;        
    hints.ai_socktype = SOCK_STREAM;    
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags    = AI_PASSIVE;     

    addrinfo* res = nullptr;
    if (getaddrinfo(nullptr, port, &hints, &res) != 0) {
        std::cerr << "getaddrinfo fallo: " << WSAGetLastError() << "\n";
        WSACleanup();
        return false;
    }

    socketEscucha = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (socketEscucha == INVALID_SOCKET) {
        std::cerr << "socket fallo: " << WSAGetLastError() << "\n";
        freeaddrinfo(res);
        WSACleanup();
        return false;
    }

    
    int yes = 1;
    setsockopt(socketEscucha, SOL_SOCKET, SO_REUSEADDR, (const char*)&yes, sizeof(yes));

    if (bind(socketEscucha, res->ai_addr, (int)res->ai_addrlen) == SOCKET_ERROR) {
        std::cerr << "bind fallo: " << WSAGetLastError() << "\n";
        closesocket(socketEscucha);
        socketEscucha = INVALID_SOCKET;
        freeaddrinfo(res);
        WSACleanup();
        return false;
    }

    freeaddrinfo(res);

    if (listen(socketEscucha, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "listen fallo: " << WSAGetLastError() << "\n";
        closesocket(socketEscucha);
        socketEscucha = INVALID_SOCKET;
        WSACleanup();
        return false;
    }

    std::cout << "Listener listo en puerto " << port << "\n";
    return true;
}
void iniciarConexiones(){
    SOCKET socketNuevo;
    string usuario;
    while(true){
        if(!aceptarConexion(socketNuevo)) continue;
        usuario = handshake(socketNuevo);
        thread acciones(gestionarServer,socketNuevo,usuario);
        acciones.detach();
    }
}

bool aceptarConexion(SOCKET& socketNuevo) {
    socketNuevo = accept(socketEscucha, nullptr, nullptr);

    if (socketNuevo == INVALID_SOCKET) {
        std::cerr << "accept fallo: " << WSAGetLastError() << "\n";
        return false;
    }
    return true;
}


void cerrarListener() {
    if (socketEscucha != INVALID_SOCKET) {
        closesocket(socketEscucha);
        socketEscucha = INVALID_SOCKET;
    }
    WSACleanup();
}
string handshake(SOCKET socket){
    string usuario;
    recvString(socket,usuario);
    return usuario;
}
void gestionarServer(SOCKET socket,string usuario){

}
void guardarInfo(){
    
}