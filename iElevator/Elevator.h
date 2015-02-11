/* 
 * File:   Elevator.h
 * Author: Fernando Almeida <fernando.almeida@me.com>
 *
 * Created on February 11, 2015, 8:57 AM
 */

#ifndef ELEVATOR_H
#define	ELEVATOR_H

#include <chrono>
#include <thread>
#include <iostream>

enum Status { ELEVATOR_OFF, ELEVATOR_ON };
enum Movement { GOING_UP, STOPPED, GOING_DOWN };
enum Door { OPENED, CLOSED };

class Elevator {
public:
    // Constructors and Destructors
    Elevator();
    Elevator(const Elevator& orig);
    virtual ~Elevator();
    
    // Read-Only Properties
    int index();
    int currentfloor();
    Status status();
    Movement movement();
    Door door();
    
    // Methods
    int on();
    int off();
    int gotofloor(int floor);
private:
    static int Elevator_counter;
    std::thread thread;
    
    int p_index;
    int p_currentfloor;
    int p_gotofloor;
    Status p_status;
    Movement p_movement;
    Door p_door;
    
    void engine();
};

#endif	/* ELEVATOR_H */

