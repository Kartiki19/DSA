#include "Vehicle.h"
#include "ParkingSpot.h"

/// Vehicle Class
Vehicle::Vehicle(int spots, VehicleSize size) : spotsNeeded(spots), size(size) {}

void Vehicle::parkInSpot(ParkingSpot* spot){
    parkingSpots.push_back(spot);
}

void Vehicle::clearSpots(){
    for(ParkingSpot* spot: parkingSpots){
        spot->removeVehicle();
    }
    parkingSpots.clear();
}

/// Motorcycle Class
Motorcycle::Motorcycle() : Vehicle(1, VehicleSize::MOTORCYCLE) {}

bool Motorcycle::canFitInSpot(const ParkingSpot& spot) const {
    return true; // Motorcycle can fit in any spot
}

/// Car Class
Car::Car() : Vehicle(1, VehicleSize::COMPACT) {}

bool Car::canFitInSpot(const ParkingSpot& spot) const {
    return (spot.getSpotSize() == VehicleSize::COMPACT || spot.getSpotSize() == VehicleSize::LARGE);
}

/// Bus Class
Bus::Bus() : Vehicle(5, VehicleSize::LARGE) {}

bool Bus::canFitInSpot(const ParkingSpot& spot) const {
    return (spot.getSpotSize() == VehicleSize::LARGE);
}
