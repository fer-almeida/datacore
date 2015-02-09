/* 
 * File:   main.cpp
 * Author: Fernando Almeida <fernando.almeida@me.com>
 *
 * Created on February 9, 2015, 1:34 PM
 */

#include <cstdlib>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

class Chronometer {
public:
    //Constructors and Destructors
    Chronometer() : tm(0), stt(0) {
        Chronometer_counter++;
        idx = Chronometer_counter;
    }
    
    ~Chronometer() {
        Chronometer_counter--;
    }
    
    //Methods
    void start(void) {
        switch(stt) {
            case 0 : // if Stopped
                stt = 1;
                thread = std::thread (&Chronometer::c_start, this);
                break;
            case 1 : // if Running
                // Do nothing!
                break;
            case 2 : // if Paused
                stt = 1;
                break;
        }
        
        return;
    }
    void stop(void) {
        stt = 0;
        thread.join();
        return;
    }
    void pause(void) {
        if(stt == 1) stt = 2;
        return;
    }
    void reset(void) {
        tm = 0;
        return;
    }
    int gettimer(void) {
        return tm;
    }
    int status(void) {
        return stt;
    }
    int index(void) {
        return idx;
    }
private:
    std::thread thread;
    
    int stt; // 0 - STOPPED | 1 - RUNNING |  2 - PAUSED
    int tm;
    int idx;
    
    static int Chronometer_counter;
    
    void c_start(void) {
        while(true) {
            if(stt == 0) break;
            
            if(stt == 1) {
                ++tm;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }
        }
    }
};

int Chronometer::Chronometer_counter = 0;

/*
 * 
 */
int main(int argc, char** argv) {
    Chronometer my_timer1;
    Chronometer my_timer2;
    
    cout << "Index: Chonometer(" << my_timer1.index() << ").timer: " << my_timer1.gettimer() << endl;
    cout << "Index: Chonometer(" << my_timer2.index() << ").timer: " << my_timer2.gettimer() << endl;
    
    cout << endl;
    
    my_timer1.start();
    
    while(my_timer1.gettimer() < 20) {
        if(my_timer1.gettimer() == 3) my_timer2.start(); // Start timer2 when timer1 reaches 3s
        
        if((my_timer2.gettimer() > 3) && (my_timer2.gettimer() < 17)) // Pause between 3s and 17s of timer2
            my_timer1.pause();
        else
            my_timer1.start();
        
        //if(my_timer2.gettimer() == 6) my_timer2.reset();
        
        cout <<    "#1 T: " << my_timer1.gettimer() << " S: " << (my_timer1.status() == 1 ? 'R' : (my_timer1.status() == 2 ? 'P' : 'S'));
        cout << " | #2 T: " << my_timer2.gettimer() << " S: " << (my_timer2.status() == 1 ? 'R' : (my_timer2.status() == 2 ? 'P' : 'S')) << "\r";
    }
    
    my_timer1.stop();
    my_timer2.stop();
       
    cout << "\nEND!" << endl;
    
    return 0;
}