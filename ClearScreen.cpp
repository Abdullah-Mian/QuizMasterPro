// ClearScreen.cpp
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#elif defined(__linux__)
#include <cstdlib>
#endif

#include "ClearScreen.h"

void clearScreen() {
#ifdef _WIN32
    system("cls");
#elif defined(__linux__)
    system("clear");
#endif
}