#include "ParkingLot.h"
#include "Vehicle.h"
#include <iostream>
using namespace std;

int main(){
    ParkingLot parkingLot;

    Car car1;
    Bus bus1;
    Motorcycle motorcycle1;

    if (parkingLot.parkVehicle(&car1)) {
        std::cout << "Car parked successfully." << std::endl;
    } else {
        std::cout << "Failed to park car." << std::endl;
    }

    if (parkingLot.parkVehicle(&bus1)) {
        std::cout << "Bus parked successfully." << std::endl;
    } else {
        std::cout << "Failed to park bus." << std::endl;
    }

    if (parkingLot.parkVehicle(&motorcycle1)) {
        std::cout << "Motorcycle parked successfully." << std::endl;
    } else {
        std::cout << "Failed to park motorcycle." << std::endl;
    }

    return 0;
}
