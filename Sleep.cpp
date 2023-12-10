// Sleep.cpp
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "Sleep.h"

void mySleep(int seconds)
{
#ifdef _WIN32
    Sleep(seconds * 1000); // Sleep takes milliseconds on Windows
#else
    sleep(seconds); // Sleep takes seconds on Unix-based systems
#endif
}
