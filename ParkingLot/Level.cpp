#include "Level.h"
#include "ParkingSpot.h"
#include "Vehicle.h"

Level::Level(int floor, int numSpots) : floor(floor), availableSpots(numSpots) {
    for(int i = 0; i < numSpots; ++i){
        VehicleSize size = (i < numSpots / 3) ? VehicleSize::MOTORCYCLE : (i < 2 * numSpots / 3) ? VehicleSize::COMPACT : VehicleSize::LARGE;
        spots.push_back(new ParkingSpot(*this, i/SPOTS_PER_ROW, i, size));
    }
}

bool Level::parkVehicle(Vehicle *vehicle){
    int spotNumber = findAvailableSpots(vehicle);
    if(spotNumber == -1) return false;
    return parkStartingAtSpot(spotNumber, vehicle);
}

bool Level::parkStartingAtSpot(int num, Vehicle* vehicle){
    for(int i = 0; i < vehicle->getSpotsNeeded(); ++i){
        spots[num+i]->park(vehicle);
    }
    availableSpots -= vehicle->getSpotsNeeded();
    return true;
}

int Level::findAvailableSpots(const Vehicle* vehicle) const{
    int spotsNeeded = vehicle->getSpotsNeeded();
    for(int i = 0; i <= spots.size()-spotsNeeded; ++i){
        bool found = true;
        for(int j = 0; j < spotsNeeded; ++j){
            if(!spots[i+j]->canFitVehicle(vehicle)){
                found = false;
                break;
            }
        }
        if(found) return i;
    }
    return -1;
}