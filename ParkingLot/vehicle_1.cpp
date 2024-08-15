
#include<vector>
#include<iostream>
using namespace std;

enum class VehicleSize{
    MOTORCYCLE,
    COMPACT,
    LARGE
};
class Level;
class Vehicle;
class ParkingSpot;

class Level{
    private:
        int floor;
        vector<ParkingSpot*> spots;
        int availableSpots;
        static const int SPOTS_PER_ROW = 10;

    public:
        Level(int floor, int numSpots) : floor(floor), availableSpots(numSpots) {
            for(int i = 0; i < numSpots; ++i){
                VehicleSize size = (i < numSpots / 3) ? VehicleSize::MOTORCYCLE : (i < 2 * numSpots / 3) ? VehicleSize::COMPACT : VehicleSize::LARGE;
                spots.push_back(new ParkingSpot(*this, i/SPOTS_PER_ROW, i, size));
            }
        }

        int availableSpotsCount() const {return availableSpots;}
        bool parkVehicle(Vehicle *vehicle){
            int spotNumber = findAvailableSpots(vehicle);
            if(spotNumber == -1) return false;
            return parkStartingAtSpot(spotNumber, vehicle);
        }
        void spotFreed() {availableSpots++;}
        static int getSpotsPerRow() {return SPOTS_PER_ROW;}

    private:
        bool parkStartingAtSpot(int num, Vehicle* vehicle){
            for(int i = 0; i < vehicle->getSpotsNeeded(); ++i){
                spots[num+i]->park(vehicle);
            }
            availableSpots -= vehicle->getSpotsNeeded();
            return true;
        }
        int findAvailableSpots(const Vehicle* vehicle) const{
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
};

class ParkingLot{
    private:
        vector<Level*> levels;
        static const int NUM_LEVELS = 5;

    public:
        ParkingLot(){
            for(int i = 0; i < NUM_LEVELS; ++i){
                levels.push_back(new Level(i, NUM_LEVELS * Level::getSpotsPerRow()));
        }
        bool parkVehicle(Vehicle *vehicle){
            for(Level* level : levels){
                if(level->parkVehicle(vehicle)) return true;
            }
            return false;
        }
};



class ParkingSpot{
    private:
        int row;
        int spotNumber;
        VehicleSize spotSize;
    
        Level& level;
        Vehicle* vehicle;
    
    public:
        ParkingSpot(Level& lev, int r, int spotNum, VehicleSize size)
            : level(lev), row(r), spotNumber(spotNum), spotSize(size), vehicle(nullptr) {}


        int getRow() const { return row; }
        int getSpotNumber() const {return spotNumber; }
        VehicleSize getSpotSize() const { return spotSize; }
    
        bool isAvailable() const
        {
            return vehicle == nullptr;
        }
        
        bool canFitVehicle(const Vehicle* v) {
            return isAvailable() && v->canFitInSpot(*this);
        }

        bool park(Vehicle* v){
            if(!canFitVehicle(v)){
                return false;
            }
            vehicle = v;
            v->parkInSpot(this);
            return true;
        }

        void removeVehicle() {
            vehicle = nullptr;
            level.spotFreed();
        }
};

class Vehicle{
    protected:
        vector<ParkingSpot*> parkingSpots;
        int spotsNeeded;
        VehicleSize size;

    public:
        Vehicle(int spots, VehicleSize size) : spotsNeeded(spots), size(size) {}
        int getSpotsNeeded() const 
        { 
                return spotsNeeded; 
        }

        VehicleSize getVehicleSize() const 
        { 
            return size; 
        }
        
        void parkInSpot(ParkingSpot* spot){
          parkingSpots.push_back(spot);
        }

        void clearSpots(){
            for(ParkingSpot* spot: parkingSpots){
                spot->removeVehicle();
            }
            parkingSpots.clear();
        }

        virtual bool canFitInSpot(const ParkingSpot& spot) const = 0;
        virtual ~Vehicle() = default;
};

class Motorcycle : public Vehicle{
    public:
        Motorcycle(): Vehicle(1, VehicleSize::MOTORCYCLE) {}
        bool canFitInSpot(const ParkingSpot& spot) const overridec {
            return true; // Motorcycle can fit in any spot
        }
};

class Car : public Vehicle{
    public:
        Car(): Vehicle(1, VehicleSize::COMPACT) {}
        bool canFitInSpot(const ParkingSpot& spot) const override{
              return (spot.getSpotSize() == VehicleSize::COMPACT || spot.getSpotSize() == VehicleSize::LARGE);
        }
};

class Bus : public Vehicle{
    public:
        Bus() : Vehicle(5, VehicleSize::LARGE) {}
        bool canFitInSpot(const ParkingSpot& spot) const override {
            return (spot.getSpotSize() == VehicleSize::LARGE);
        }
};

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
