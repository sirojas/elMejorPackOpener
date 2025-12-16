#include "utils.hpp"
using namespace :: std;
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