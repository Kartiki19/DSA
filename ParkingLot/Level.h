#ifndef LEVEL_H
#define LEVEL_H

#include "ParkingSpot.h"
#include "Vehicle.h"
#include<vector>
using namespace std;
class Level{
    private:
        int floor;
        vector<ParkingSpot*> spots;
        int availableSpots;
        static const int SPOTS_PER_ROW = 10;

    public:
        Level(int floor, int numSpots);
        int availableSpotsCount() const {return availableSpots;}
        bool parkVehicle(Vehicle *vehicle);
        void spotFreed() {availableSpots++;}
        static int getSpotsPerRow() {return SPOTS_PER_ROW;}

    private:
        bool parkStartingAtSpot(int num, Vehicle* vehicle);
        int findAvailableSpots(const Vehicle* vehicle) const;
};

#endif
