#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

int main(){
    bool running = true;
    int ms = 0;
    int sec = 0;
    int min = 0;
    int hour = 0;
    while(running){
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        ms+=10;
        if(ms == 1000){
            sec++;
            ms = 0;
        }
        if(sec == 60){
            min++;
            sec = 0;
        }
        if(min == 60){
            hour++;
            min = 0;
        }
        std::cout 
        << std::setfill('0') << std::setw(2) << hour << ":"
        << std::setfill('0') << std::setw(2) << min << ":"
        << std::setfill('0') << std::setw(2) << sec << ":"
        << std::setfill('0') << std::setw(3) << ms
        << "\r" << std::flush;
    }
    
}