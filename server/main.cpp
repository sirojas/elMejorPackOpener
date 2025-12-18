#include "C:\Users\Simón\Desktop\elMejorPackOpener\elMejorPackOpener\utils.hpp"
#include "server.hpp"
using namespace :: std;
using std::fstream;
fstream archivoMaestro;


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
     archivoMaestro.open("jugadores.bin", ios::in | ios::out | ios::binary);
    if (!archivoMaestro){
        std::ofstream create("jugadores.bin", ios::binary);
        create.close();
        archivoMaestro.open("jugadores.bin", ios::in | ios::out | ios::binary);
    }

}
void iniciarConexiones(){

}