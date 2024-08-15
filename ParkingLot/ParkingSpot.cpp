#include "ParkingSpot.h"
#include "Level.h"
#include "Vehicle.h"

/// Parking lot has multiple levels
/// Each level has multiple rows of spots
/// Can park motorcycle, Car and Bus
/// motocyle spots, compact spots, large spots
/// motorcycle in any space
/// car in compact / large
/// Bus in 5 large sports in a row continuous

ParkingSpot::ParkingSpot(Level& level, int row, int spotNum, VehicleSize sz) : level(level), row(row), spotNumber(spotNum), spotSize(sz), vehicle(nullptr) {}

bool ParkingSpot::isAvailable() const{
    return vehicle == nullptr;
}

bool ParkingSpot::canFitVehicle(const Vehicle* v) const {
    return isAvailable() && v->canFitInSpot(*this);
}

bool ParkingSpot::park(Vehicle* v){
    if(!canFitVehicle(v)){
        return false;
    }
    vehicle = v;
    v->parkInSpot(this);
    return true;
}

void ParkingSpot::removeVehicle(){
    vehicle = nullptr;
    level.spotFreed();
}


