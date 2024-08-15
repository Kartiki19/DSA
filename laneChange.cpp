#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// Definitions of the functions here (from above)
struct ControlInput {
    double steering_angle;
    double acceleration;
};

struct Vehicle {
    double x, y, velocity;
};

bool is_safe_to_change_lane(const Vehicle& current_vehicle, const vector<Vehicle>& nearby_vehicles, const string& lane_change_direction) {
    double safe_distance = 10.0; // Define a safe distance threshold

    for (const auto& vehicle : nearby_vehicles) {
        if (lane_change_direction == "left") {
            if (vehicle.x < current_vehicle.x && abs(vehicle.y - current_vehicle.y) < safe_distance) {
                return false;
            }
        } else if (lane_change_direction == "right") {
            if (vehicle.x > current_vehicle.x && abs(vehicle.y - current_vehicle.y) < safe_distance) {
                return false;
            }
        }
    }
    return true;
}

vector<Vehicle> identify_relevant_vehicles(const Vehicle& current_vehicle, const vector<Vehicle>& all_vehicles) {
    vector<Vehicle> relevant_vehicles;
    double detection_range = 50.0; // Define the detection range

    for (const auto& vehicle : all_vehicles) {
        if (abs(vehicle.y - current_vehicle.y) <= detection_range) {
            relevant_vehicles.push_back(vehicle);
        }
    }
    return relevant_vehicles;
}

ControlInput compute_conservative_control_input(const Vehicle& current_vehicle, const string& lane_change_direction) {
    ControlInput control_input = {0, 0};

    if (lane_change_direction == "left") {
        control_input.steering_angle = -5.0; // Turn left conservatively
    } else if (lane_change_direction == "right") {
        control_input.steering_angle = 5.0; // Turn right conservatively
    }

    control_input.acceleration = -1.0; // Slightly reduce speed for safety

    return control_input;
}

int main() {
    // Define the current vehicle
    Vehicle current_vehicle = {0.0, 0.0, 10.0};

    // Define all nearby vehicles
    vector<Vehicle> all_vehicles = {
        {10.0, 2.0, 8.0},
        {-5.0, 1.0, 12.0},
        {15.0, -3.0, 11.0}
    };

    // Identify relevant vehicles
    vector<Vehicle> relevant_vehicles = identify_relevant_vehicles(current_vehicle, all_vehicles);

    // Check if it is safe to change lane
    string lane_change_direction = "right";
    if (is_safe_to_change_lane(current_vehicle, relevant_vehicles, lane_change_direction)) {
        ControlInput control_input = compute_conservative_control_input(current_vehicle, lane_change_direction);
        cout << "Lane change control input: "
                  << "Steering angle: " << control_input.steering_angle
                  << ", Acceleration: " << control_input.acceleration
                  << endl;
    } else {
        cout << "Lane change not safe." << endl;
    }

    return 0;
}
