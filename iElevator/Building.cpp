/* 
 * File:   Building.cpp
 * Author: Fernando Almeida <fernando.almeida@me.com>
 * 
 * Created on February 11, 2015, 12:55 PM
 */

#include "Building.h"

Building::Building() : p_parkingfloors(3), p_businessfloors(25), p_floors(29) {
    
}

Building::Building(const Building& orig) {
}

Building::~Building() {
}

int Building::floors() {
    return p_floors;
}

int Building::parkingfloors() {
    return p_parkingfloors;
}

int Building::parkingfloors(int floors) {
    p_parkingfloors = floors;
    p_floors = p_parkingfloors + p_businessfloors + 1;
    
    return p_parkingfloors;
}

int Building::businessfloors() {
    return p_businessfloors;
}

int Building::businessfloors(int floors) {
    p_businessfloors = floors;
    p_floors = p_parkingfloors + p_businessfloors + 1;
    
    return p_businessfloors;
}