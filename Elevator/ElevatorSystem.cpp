#include "ElevatorSystem.h"
#include "Button.cpp"

class ElevatorSystem{
    private:
        ElevatorSystem(){}
        Building Building;
        static ElevatorSystem* system;

    public:
        
        void monitoring();
        void dispatcher();

        static ElevatorSystem* getInstance(){
            if(system == nullptr) system = new ElevatorSystem();
            return system;
        }

};

class Building{
    private:
        vector<Floor> floor;
        vector<ElevatorCar> elevator;
        static Building* building;
    
    public:
        static Building* getInstance(){
            if(building == nullptr) building = new Building();
            return building;
        }
};