/* 
 * File:   Elevator.cpp
 * Author: Fernando Almeida <fernando.almeida@me.com>
 * 
 * Created on February 11, 2015, 8:57 AM
 */

#include "Elevator.h"

using namespace std;

Elevator::Elevator() : p_currentfloor(0), p_gotofloor(0), p_status(ELEVATOR_OFF), p_movement(STOPPED), p_door(OPENED), p_base(0) {
    Elevator_counter++;
    p_index = Elevator_counter;
}

Elevator::Elevator(const Elevator& orig) {
}

Elevator::~Elevator() {
    Elevator_counter--;
}

int Elevator::index() {
    return p_index;
}

int Elevator::currentfloor() {
    return p_currentfloor;
}

Status Elevator::status() {
    return p_status;
}

Movement Elevator::movement() {
    return p_movement;
}

Door Elevator::door() {
    return p_door;
}

int Elevator::on() {
    if(!p_status) {
        p_status = ELEVATOR_ON;
        thread = std::thread (&Elevator::engine, this);
        
        return 0;
    }
    
    return 1;
}

int Elevator::off() {
    if(p_status) {
        p_status = ELEVATOR_OFF;
        thread.join();
        
        return 0;
    }
    
    return 1;
}

int Elevator::gotofloor(int floor) {
    if((floor != p_currentfloor) && (p_status == ELEVATOR_ON)) {
        p_movement = (floor > p_currentfloor ? GOING_UP : GOING_DOWN);
        p_gotofloor = floor;
        return 0;
    }
    
    return 1;
}

void Elevator::engine() {
    while(p_status == ELEVATOR_ON) {
        switch(p_movement) {
            case GOING_DOWN :
            case GOING_UP :
                p_door = CLOSED;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                (p_currentfloor < p_gotofloor ? p_currentfloor++ : p_currentfloor--);
                
                if(p_currentfloor == p_gotofloor) p_movement = STOPPED;
                break;
            case STOPPED :
                p_door = OPENED;
                break;
        }
    }
}

int Elevator::base() {
    return p_base;
}

int Elevator::base(int floor) {
    p_base = floor;
    return p_base;
}

int Elevator::Elevator_counter = 0;