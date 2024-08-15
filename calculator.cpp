#include<iostream>
using namespace std;

class Calculator{
    private:
        double a;
        double b;
    
    public:
        Calculator(int a, int b) : a(a), b(b){}
        int add() { return a+b; }
        int sub() {return a-b; }
        int mul() { return a*b; }
        int div() {
            if(b == 0){
                cout << "\n Can not divide by zero !" << endl;
                return -1;
            }
            else return a/b; 
        }
};
class ScientificCalculatpr 
int main(){
    ScientificCalculator sciCalc;
    int choice;
    double a, b;

    do {
        std::cout << "\nCalculator Menu:\n";
        std::cout << "1. Addition\n";
        std::cout << "2. Subtraction\n";
        std::cout << "3. Multiplication\n";
        std::cout << "4. Division\n";
        std::cout << "5. Power\n";
        std::cout << "6. Square Root\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        try {
            switch (choice) {
                case 1:
                    std::cout << "Enter two numbers: ";
                    std::cin >> a >> b;
                    std::cout << "Result: " << sciCalc.add(a, b) << std::endl;
                    break;
                case 2:
                    std::cout << "Enter two numbers: ";
                    std::cin >> a >> b;
                    std::cout << "Result: " << sciCalc.subtract(a, b) << std::endl;
                    break;
                case 3:
                    std::cout << "Enter two numbers: ";
                    std::cin >> a >> b;
                    std::cout << "Result: " << sciCalc.multiply(a, b) << std::endl;
                    break;
                case 4:
                    std::cout << "Enter two numbers: ";
                    std::cin >> a >> b;
                    std::cout << "Result: " << sciCalc.divide(a, b) << std::endl;
                    break;
                case 5:
                    std::cout << "Enter base and exponent: ";
                    std::cin >> a >> b;
                    std::cout << "Result: " << sciCalc.power(a, b) << std::endl;
                    break;
                case 6:
                    std::cout << "Enter a number: ";
                    std::cin >> a;
                    std::cout << "Result: " << sciCalc.squareRoot(a) << std::endl;
                    break;
                case 7:
                    std::cout << "Exiting..." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
            }
        } catch (const std::runtime_error& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    } while (choice != 7);

    return 0;
}