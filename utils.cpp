#include "utils.hpp"
using namespace :: std;
using String = std::string;

void gotoxy(short x, short y) {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{x, y});
}
void clear(){
    cout << "\x1b[2J\x1b[H";
}
std::unordered_map<std::string, std::string> readConfigKV(const std::string& path) {
    std::unordered_map<std::string, std::string> cfg;
    std::ifstream f(path);
    std::string line;

    auto trim = [](std::string s){
        auto is_ws = [](unsigned char c){ return c==' '||c=='\t'||c=='\r'||c=='\n'; };
        while (!s.empty() && is_ws((unsigned char)s.front())) s.erase(s.begin());
        while (!s.empty() && is_ws((unsigned char)s.back()))  s.pop_back();
        return s;
    };

    while (std::getline(f, line)) {
        line = trim(line);
        if (line.empty() || line[0] == '#') continue;

        auto eq = line.find('=');
        if (eq == std::string::npos) continue;

        auto key = trim(line.substr(0, eq));
        auto val = trim(line.substr(eq + 1));
        cfg[key] = val;
    }
    return cfg;
}
SOCKET conectar(const char* host, const char* port) {
    WSADATA wsa{};
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        std::cerr << "WSAStartup fallo: " << WSAGetLastError() << "\n";
        return INVALID_SOCKET;
    }

    addrinfo hints{};
    hints.ai_family   = AF_INET;        
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    addrinfo* res = nullptr;
    if (getaddrinfo(host, port, &hints, &res) != 0) {
        std::cerr << "getaddrinfo fallo: " << WSAGetLastError() << "\n";
        WSACleanup();
        return INVALID_SOCKET;
    }

    SOCKET s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (s == INVALID_SOCKET) {
        std::cerr << "socket fallo: " << WSAGetLastError() << "\n";
        freeaddrinfo(res);
        WSACleanup();
        return INVALID_SOCKET;
    }

    if (connect(s, res->ai_addr, (int)res->ai_addrlen) == SOCKET_ERROR) {
        std::cerr << "connect fallo: " << WSAGetLastError() << "\n";
        closesocket(s);
        freeaddrinfo(res);
        WSACleanup();
        return INVALID_SOCKET;
    }

    freeaddrinfo(res);
    return s; 
}
int randomEntre(int a, int b){
    static std::random_device rd;
    static std::mt19937 gen(rd()); 

    std::uniform_int_distribution<int> dist(a, b); 
    return dist(gen);
}
void randomWait(int min,int max){
    int segundos = randomEntre(min,max)*1000;
    Sleep(segundos);
}

const String& Carta::jugador() const{
    return jugador_;
}
int Carta::media() const{
    return media_;
}
rarezas Carta::rareza() const{
    return rareza_;
}
void Carta::setJugador(String jugadorNuevo){
    jugador_ = jugadorNuevo;
}
void Carta::setMedia(int mediaNueva){
    media_ = mediaNueva;
}
void Carta::setRareza(enum rarezas rarezaNueva){
    rareza_ = rarezaNueva;
}
double Carta::valor() const{
    return valor_;
}
void Carta::setValor(double valorNuevo){
    valor_ = valorNuevo;
}