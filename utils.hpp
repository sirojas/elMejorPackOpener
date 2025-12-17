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

void clear();
void gotoxy(short x, short y);
std::unordered_map<std::string, std::string> readConfigKV(const std::string& path);
SOCKET conectar(const char* host, const char* port);
void randomWait(int min,int max);

#endif // UTILS_H