#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Airline {
    public:
        Airline(const string& name, double basePrice, const string& classType)
            : name(name), basePrice(basePrice), classType(classType) {}

        virtual ~Airline() {}

        virtual double calculateOperationCost() const = 0;
        virtual double calculateTicketPrice() const = 0;

        string getName() const { return name; }

    protected:
        string name;
        double basePrice;
    string classType;
};

class UnitedAirline : public Airline {
    public:
        UnitedAirline(double basePrice, const string& classType)
            : Airline("United", basePrice, classType) {}

        double calculateOperationCost() const override {
            // Specific operation cost calculation for United
            return basePrice * 1.2;
        }

        double calculateTicketPrice() const override {
            // Specific ticket price calculation for United
            if (classType == "Economy") return basePrice * 1.5;
            return basePrice * 1.7;
        }
};

class SouthwestAirline : public Airline {
    public:
        SouthwestAirline(double basePrice, const string& classType)
            : Airline("Southwest", basePrice, classType) {}

        double calculateOperationCost() const override {
            // Specific operation cost calculation for Southwest
            return basePrice * 1.1;
        }

        double calculateTicketPrice() const override {
            // Specific ticket price calculation for Southwest
            if (classType == "Business") return basePrice * 1.8;
            return basePrice * 2.0;
        }
};

class AmericanAirline : public Airline {
    public:
        AmericanAirline(double basePrice, const string& classType)
            : Airline("American", basePrice, classType) {}

        double calculateOperationCost() const override {
            // Specific operation cost calculation for American
            return basePrice * 1.3;
        }

        double calculateTicketPrice() const override {
            // Specific ticket price calculation for American
            if (classType == "Premium") return basePrice * 2.0;
            return basePrice * 2.2;
        }
};


class AirlineFactory {
public:
    static unique_ptr<Airline> createAirline(const string& airlineName, double basePrice, const string& classType) {
        if (airlineName == "United") {
            return make_unique<UnitedAirline>(basePrice, classType);
        } else if (airlineName == "Southwest") {
            return make_unique<SouthwestAirline>(basePrice, classType);
        } else if (airlineName == "American") {
            return make_unique<AmericanAirline>(basePrice, classType);
        } else {
            throw invalid_argument("Unknown airline");
        }
    }
};


int main() {
    vector<string> airlineList = {"United 150.0 Economy", "Southwest 150.0 Business", "American 150.0 Premium"};

    for (const auto& airlineData : airlineList) {
        istringstream iss(airlineData);
        string name, classType;
        double basePrice;
        iss >> name >> basePrice >> classType;

        try {
            auto airline = AirlineFactory::createAirline(name, basePrice, classType);
            cout << "Airline: " << airline->getName() << "\n";
            cout << "Operation Cost: " << airline->calculateOperationCost() << "\n";
            cout << "Ticket Price: " << airline->calculateTicketPrice() << "\n";
        } catch (const invalid_argument& e) {
            cerr << e.what() << '\n';
        }
    }

    return 0;
}
