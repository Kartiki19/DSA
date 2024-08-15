#ifndef PARKINGSPOT_H
#define PARKINGSPOT_H

#include "Vehicle.h"

class Level;

class ParkingSpot{
    private:
        int row;
        int spotNumber;
        VehicleSize spotSize;
    
        Level& level;
        Vehicle* vehicle;
    
    public:
        ParkingSpot(Level& level, int row, int spotNumber, VehicleSize size);

        int getRow() const { return row; }
        int getSpotNumber() const {return spotNumber; }
        VehicleSize getSpotSize() const { return spotSize; }
    
        bool isAvailable() const;
        bool canFitVehicle(const Vehicle* vehicle) const;
        bool park(Vehicle* vehicle);
        void removeVehicle();
};

#endif
