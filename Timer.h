// Timer.h

#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <thread>

class Timer {
public:
    Timer(int seconds);
    void start();
    bool expired();

private:
    std::chrono::time_point<std::chrono::steady_clock> endTime;
};

#endif // TIMER_H
