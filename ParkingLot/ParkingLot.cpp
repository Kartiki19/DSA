#include "ParkingLot.h"

ParkingLot::ParkingLot(){
    for(int i = 0; i < NUM_LEVELS; ++i){
        levels.push_back(new Level(i, NUM_LEVELS * Level::getSpotsPerRow()));
    }
}

bool ParkingLot::parkVehicle(Vehicle *vehicle){
    for(Level* level : levels){
        if(level->parkVehicle(vehicle)) return true;
    }
    return false;
}