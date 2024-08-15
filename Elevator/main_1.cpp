#include <queue>
#include <iostream>
#include <unistd.h>
#include <climits>
using namespace std;

enum Direction {
    UP,
    DOWN,
    IDLE
};

enum Location {
    INSIDE,
    OUTSIDE
};

class Request {
    private:
        int sourceFloor;
        int destinationFloor;
        Direction direction;
        Location location;

    public: 
        Request(int srcFloor) : sourceFloor(srcFloor) {}

        Direction getDirection() { return direction; }
        int getSourceFloor() { return sourceFloor; }
        
        void createRequest(Direction dir, int destFloor) {
            direction = dir;
            destinationFloor = destFloor;
        }
};

class Elevator {
    private:
        int currentFloor;
        Direction direction;
        priority_queue<pair<int, Request>, vector<pair<int, Request>>, greater<pair<int, Request>>> upQueue;
        priority_queue<pair<int, Request>> downQueue;

    public:
        Elevator(int current_floor) {
            currentFloor = current_floor;
            direction = Direction::IDLE;
        }

        int getCurrentFloor() { return currentFloor; }

        void callElevator(Request request) {
            if(request.getDirection() == Direction::UP)
                upQueue.push({request.getSourceFloor(), request});
            else    
                downQueue.push({request.getSourceFloor(), request});
        }

        void processRequests() {
            cout << "\nElevator is at " << currentFloor << " floor" << endl;
            if(direction == Direction::UP && !upQueue.empty())
                processUpRequest();
            else if(direction == Direction::DOWN && !downQueue.empty())
                processDownRequest();
            else {
                int upRequestFloor = (upQueue.empty()) ? INT_MAX : upQueue.top().first;
                int downRequestFloor = (downQueue.empty()) ? INT_MAX : downQueue.top().first;
                if(abs(currentFloor - upRequestFloor) < abs(currentFloor - downRequestFloor)) {
                    direction = Direction::UP;
                    processUpRequest();
                } else {
                    direction = Direction::DOWN;
                    processDownRequest();
                }
            }
        }

        void processUpRequest() {
            if(!upQueue.empty()) {
                Request currentRequest = upQueue.top().second;
                int sourceFloor = upQueue.top().first;
                upQueue.pop();
                
                cout << "\n Elevator requested at floor " << sourceFloor << endl;
                if(sourceFloor < currentFloor) cout << "Elevator going down! " << endl;
                else cout << "Elevator is going up !" << endl;
                sleep(2);
                currentFloor = sourceFloor;
                cout << "\n Elevator opening door at floor " << currentFloor << endl;
            }
        }

        void processDownRequest() {
            if(!downQueue.empty()) {
                Request currentRequest = downQueue.top().second;
                int sourceFloor = downQueue.top().first;
                downQueue.pop();
                
                cout << "\n Elevator requested at floor " << sourceFloor << endl;
                if(sourceFloor < currentFloor) cout << "Elevator going down! " << endl;
                else cout << "Elevator is going up !" << endl;
                sleep(2);
                currentFloor = sourceFloor;
                cout << "\n Elevator opening door at floor " << currentFloor << endl;
            }
        }

        void run() {
            while(!upQueue.empty() || !downQueue.empty()) processRequests();
            cout << "\n Finished all requests ! Elevator is at " << currentFloor << "th floor" << endl;
            direction = Direction::IDLE;
        }
};

int main() {
    Elevator elevator(0);
    Request request_1(3);
    request_1.createRequest(Direction::UP, 5);

    Request request_2(10);
    request_2.createRequest(Direction::DOWN, 2);

    Request request_3(7);
    request_3.createRequest(Direction::DOWN, 1);
    
    Request request_4(4);
    request_4.createRequest(Direction::UP, 9);
    
    Request request_5(6);
    request_5.createRequest(Direction::UP, 10);

    elevator.callElevator(request_1);
    elevator.callElevator(request_2);
    elevator.callElevator(request_3);
    elevator.callElevator(request_4);
    elevator.callElevator(request_5);

    elevator.run();
    return 0;
}
