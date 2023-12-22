// Timer.cpp

/*#include "Timer.h"
#include <chrono>
#include <thread>

using namespace std;

Timer::Timer(int seconds) {
    endTime = chrono::steady_clock::now() + chrono::seconds(seconds);
}

void Timer::start() {
    this_thread::sleep_until(endTime);
}

bool Timer::expired() {
    return chrono::steady_clock::now() >= endTime;
}
*/