/* 
 * File:   Building.h
 * Author: Fernando Almeida <fernando.almeida@me.com>
 *
 * Created on February 11, 2015, 12:55 PM
 */

#ifndef BUILDING_H
#define	BUILDING_H

class Building {
public:
    Building();
    Building(const Building& orig);
    virtual ~Building();
    
    int floors();
    int parkingfloors();
    int parkingfloors(int floors);
    int businessfloors();
    int businessfloors(int floors);
private:
    int p_floors;
    int p_parkingfloors;
    int p_businessfloors;
};

#endif	/* BUILDING_H */

