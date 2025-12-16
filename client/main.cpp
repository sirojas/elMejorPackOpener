#include "utils.hpp"
using namespace :: std;
bool inicioOk = false;
int main(){
    iniciarPrograma();
    Sleep(10000);
    return 0;
}

void iniciarPrograma(){
    crearHilos();
    
}
void crearHilos(){
    std::thread hiloPantalla(pantalla);
    hiloPantalla.detach();

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

static void gotoxy(short x, short y) {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{x, y});
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
        if(i == 3)
            break;
    } 
    dotsX = 36;
    gotoxy(dotsX,dotsY);
    cout << "Conexion establecida con exito" ;
    Sleep(1000);
}

void clear(){
    cout << "\x1b[2J\x1b[H";
}