#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class Airline{
    protected:
        string name;
        double base_price;
        string classType;
    
    public:
        Airline(const string& name, const double& basePrice, const string& classType) : name(name), base_price(basePrice), classType(classType){}
        virtual ~Airline() {}
        virtual double calculateTicket() const = 0;
        string getName() const { return name;}
};

class UnitedAirLine : public Airline{
    public:
        UnitedAirLine(const double& basePrice, const string& classType) : Airline("United", basePrice, classType) {}
        double calculateTicket() const override{
            if(classType == "Economy") return base_price * 1.2;
            else if(classType == "Business") return base_price * 2;
            return base_price;
        }
};

class SouthWestAirLine : public Airline{
    public:
        SouthWestAirLine(const double& basePrice, const string& classType) : Airline("SouthwestAirline", basePrice, classType) {}
        double calculateTicket() const override{
            if(classType == "Economy") return base_price * 1.2;
            else if(classType == "Business") return base_price * 2;
            return base_price;
        }
};

class AirlineFactory{
    public:
        static unique_ptr<Airline> createAirline(const string& airlineName, const double& basePrice, const string& classType){
            if(airlineName == "United") 
                return make_unique<UnitedAirLine>(basePrice,classType);
            else if(airlineName == "SouthwestAirline")
                return make_unique<SouthWestAirLine>(basePrice, classType);
            else{
                throw invalid_argument("Unknown Airline");
            }
        }
};

int main(){
    vector<string> airlineList = {"United 150.0 Economy", "SouthwestAirline 200.0 Business", 
                                    "abcd 500.0 rcb"};

    for(auto it: airlineList){
        istringstream ss(it);
        string name;
        double base;
        string classType;

        ss >> name >> base >> classType;

        try{
            cout<< "\n" << name << "\t" << base << "\t" << classType << endl;
            auto airline = AirlineFactory::createAirline(name, base, classType);
            cout << "\nAirline: " << airline->getName() << endl;
            cout << "Ticket Price: " << airline->calculateTicket() << endl;
        } catch(invalid_argument& e){
            cerr << e.what() << "\n";
        }
    }

    return 0;
}