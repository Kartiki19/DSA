#include<iostream>
using namespace std;

class Calculator{
    private:
        double value;
    public:
        Calculator(double value = 0) : value(value) {}

        Calculator operator+(Calculator other){
            return Calculator(this->value + other.value);
        }

        Calculator operator-(Calculator other){
            return Calculator(this->value - other.value);
        }

        Calculator operator/(Calculator other){
            if(other.value == 0) throw runtime_error("Division by zero");
            return Calculator(this->value/other.value);
        }

        friend ostream& operator<< ( ostream& os, Calculator cal){
            os << cal.value;
            return os;
        }
};

int main(){
    try{
        Calculator num1(6.0);
        Calculator num2(8.0);
        Calculator num3(1.0);

        Calculator result = num1 + num2 - num1 / num3;

        cout << " Result is " << result << endl;
    }
    catch(exception e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}