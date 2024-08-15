/// Vehicle.h

#ifndef VEHICLE_H
#define VEHICLE_H
#include<vector>
using namespace std;

enum class VehicleSize{
    MOTORCYCLE,
    COMPACT,
    LARGE
};

class ParkingSpot; /// Forward Declaration

class Vehicle{
    protected:
        vector<ParkingSpot*> parkingSpots;
        //string licensePlate;
        int spotsNeeded;
        VehicleSize size;

    public:
        Vehicle(int spots, VehicleSize size);
        int getSpotsNeeded() const {return spotsNeeded; }
        VehicleSize getVehicleSize() const { return size; }
        void parkInSpot(ParkingSpot* spot);
        void clearSpots();
        virtual bool canFitInSpot(const ParkingSpot& spot) const = 0;
        virtual ~Vehicle() = default;
};

class Motorcycle : public Vehicle{
    public:
        Motorcycle();
        bool canFitInSpot(const ParkingSpot& spot) const override;
};

class Car : public Vehicle{
    public:
        Car();
        bool canFitInSpot(const ParkingSpot& spot) const override;
};

class Bus : public Vehicle{
    public:
        Bus();
        bool canFitInSpot(const ParkingSpot& spot) const override;
};

#endif
