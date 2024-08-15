#include "ElevatorSystem.h"
#include<vector>
using namespace std;

class Button{
    private:
        bool status;

    public:
        void pressDown();
        virtual bool isPressed() = 0;
};

class HallButton: public Button{
    private:
        Direction buttonSign;
    public:
        bool isPressed(){

        }
};

class ElevatorButton: public Button{
    private:
        int destinationFloorNumber;
    public:
        bool isPressed(){

        }
};

class ElevatorPanel{
    private:
        ElevatorButton openButton;
        ElevatorButton closeButton;
        vector<ElevatorButton> floorButtons;
};

class HallPanel{
    private:
        HallButton up;
        HallButton down;
};

class Display{
    private:
        int floor;
        int capacity;
        Direction direction;
    public:
        void showElevatorDisplay();
        void showHallDisplay();
};

class Door{
    private:
        DoorState state;
    public:
        bool isOpen();
};

class Floor{
    private:
        vector<Display> display;
        vector<HallPanel> panel;
    public:
        bool isBottomMost();
        bool isTopMost();
};

class ElevatorCar{
    private:
        int id;
        Door door;
        ElevatorState state;
        Display elevatorDisplay;
        ElevatorPanel elevatorPanel;

    public:
        void move();
        void stop();
};