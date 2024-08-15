#include <iostream>
#include <vector>
using namespace std;

class base{
    public:
        virtual void display () = 0;
};

class derived : public base{
    public:
        virtual void display () {
            cout << " Derived Class " << endl;
        }
};

class child : public derived{
    public:
    
};

int main(){
    vector<base*> objects;

    objects.push_back(b);
    for (base* obj : objects) {
        obj->display(); // Calls the appropriate display function based on the dynamic type
    }
    return 0;
}