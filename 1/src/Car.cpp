#include <iostream>

class Car {
    private:
    std::string carColor;
    int nrOfDoors;

    public:
    Car(const std::string &color , const int &nr )
    :carColor(color),
    nrOfDoors(nr){}

    virtual ~Car(){
        std::cout<<"Destructor Car"<<std::endl;
    }

    Car& operator=(const Car& c)= delete;

};