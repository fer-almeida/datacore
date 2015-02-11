/* 
 * File:   main.cpp
 * Author: Fernando Almeida <fernando.almeida@me.com>
 *
 * Created on February 11, 2015, 8:54 AM
 */

#include <cstdlib>
#include <iostream>
#include "Elevator.h"

void elevatorstatus(Elevator *elevator);

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Elevator elevator1;
    Elevator elevator2;
    
    elevatorstatus(&elevator1);
    elevatorstatus(&elevator2);
    
    elevator1.on();
    elevator2.on();

    elevator1.gotofloor(5);
    elevator2.gotofloor(3);
    
    while(elevator1.currentfloor() < 5) {
        cout << "1 - F" << elevator1.currentfloor() << " 2 - F" << elevator2.currentfloor() << "\r";
    }
    cout << "1 - F" << elevator1.currentfloor() << " 2 - F" << elevator2.currentfloor() << "\r";
    cout << endl;
    
    elevator1.gotofloor(0);
    while(elevator1.currentfloor() > 0) {
        cout << "1 - F" << elevator1.currentfloor() << " 2 - F" << elevator2.currentfloor() << "\r";
    }
    cout << "1 - F" << elevator1.currentfloor() << " 2 - F" << elevator2.currentfloor() << "\r";
    cout << endl;
    
    elevator1.off();
    elevator2.off();

    return 0;
}

void elevatorstatus(Elevator *elevator) {
    cout << "\nElevator #" << elevator->index() << endl;
    cout << "Current Floor: " << elevator->currentfloor() << endl;
    cout << "Status: " << (elevator->status() == ELEVATOR_ON ? "On" : "Off") << endl;
    cout << "Movement: " << (elevator->movement() == GOING_UP ? "Going Up" : (elevator->movement() == STOPPED ? "Stopped" : "Going Down")) << endl;
    cout << "Door: " << (elevator->door() == OPENED ? "Opened" : "Closed") << endl;
    
    return;
}

void draw(){
    cout << "===========================";
    cout << "|                         |";
    
    return;
}