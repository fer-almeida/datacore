/* 
 * File:   main.cpp
 * Author: Fernando Almeida <fernando.almeida@me.com>
 *
 * Created on February 11, 2015, 8:54 AM
 */

#include <cstdlib>
#include <iostream>
#include "Elevator.h"
#include "Building.h"

void elevatorstatus(Elevator *elevator);

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int from = 0;
    int to = 0;
    
    Elevator elevator1;
    Elevator elevator2;
    elevatorstatus(&elevator1);
    elevatorstatus(&elevator2);
    
    elevator1.on();
    elevator2.on();
    elevator1.base(4);
    elevator2.base(0);
    
    while(1) {
        /*
        cout << "Where are you now? ";
        cin >> from;
        cout << "Where are you going? ";
        cin >> to;
        
        if(from == to) {
            cout << "You are already on " << to << endl;
            continue;
        }
        else
            cout << "From " << from << " To " << to << endl;
                
        if(elevator1.currentfloor() == from) {
            elevator1.gotofloor(to);
            while(elevator1.currentfloor() != to) {
                cout << "E#" << elevator1.index() << "F" << elevator1.currentfloor() << "\r";
            }
            
            cout << endl;
        } else {
            elevator1.gotofloor(from);
            while(elevator1.currentfloor() != from) {
                cout << "E#" << elevator1.index() << "F" << elevator1.currentfloor() << "\r";
            }
            
            elevatorstatus(&elevator1);
            
            elevator1.gotofloor(to);
            while(elevator1.currentfloor() != to) {
                cout << "E#" << elevator1.index() << "F" << elevator1.currentfloor() << "\r";
            }
            
            cout << endl;
        }
         */
        
        elevatorstatus(&elevator1);
        elevatorstatus(&elevator2);
    }

    elevator1.off();
    elevator2.off();

    return 0;
}

void elevatorstatus(Elevator *elevator) {
    cout << "\rE#" << elevator->index() << " | Current Floor: " << elevator->currentfloor() << " | Status: " << (elevator->status() == ELEVATOR_ON ? "On" : "Off") << " | Movement: " << (elevator->movement() == GOING_UP ? "Going Up" : (elevator->movement() == STOPPED ? "Stopped" : "Going Down")) << " | Door: " << (elevator->door() == OPENED ? "Opened" : "Closed") << " | Base: " << elevator->base() << "\r";
    
    return;
}