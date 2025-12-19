#include "C:\Users\Simón\Desktop\elMejorPackOpener\elMejorPackOpener\utils.hpp"
#include "server.hpp"
using namespace :: std;
using std::fstream;
fstream archivoMaestro;
Jugadores jugadores;

int main(){
    iniciarServidor();
    iniciarConexiones();

    
    return 0;
}
void iniciarServidor(){
    pantallaInicio();
    recuperarInfo();
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
    cout << "Informacion recuperada con exito, cantidad de jugadores que hay: " << jugadores.cantidadJugadores();
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
void iniciarConexiones(){

}
void guardarInfo(){
    
}