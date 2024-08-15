#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "Level.h"
#include "Vehicle.h"
#include<vector>
using namespace std;

class ParkingLot{
    private:
        vector<Level*> levels;
        static const int NUM_LEVELS = 5;

    public:
        ParkingLot();
        bool parkVehicle(Vehicle* Vehicle);
};
#endif
