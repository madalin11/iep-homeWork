#include<iostream>

class Car{

    protected:
    int nrOfDoors;
    int weight;
    bool isLocked = false;
    std::string wheels;
    std::string tire;
    std::string fuel;

    public:
    std::string colorCar;
    Car(const std::string &color ,const int &nr ,const  int &w,const std::string &wh , const std::string &tr,const std::string &f)
    :colorCar(color),
    nrOfDoors(nr),
    weight(w),
    wheels(wh),
    tire(tr),
    fuel(f){
        std::cout<<"Car created"<<std::endl;
    }
    
   Car(const Car &c){
        std::cout<<"Copy constructor car"<<std::endl;
        this->colorCar = c.colorCar;
        this->fuel=c.fuel;
        this->nrOfDoors = c.nrOfDoors;
        this->tire = c.tire;
        this->weight=c.weight;
        this->wheels=c.wheels;
    }

    Car& operator=(const Car& c){
        std::cout<<"Copy assignment operator car "<<std::endl;
        if(this==&c){
            std::cout<<"Assign to self car"<<std::endl;

            return *this;
        }
        colorCar = c.colorCar;
        fuel=c.fuel;
        nrOfDoors = c.nrOfDoors;
        tire = c.tire;
        weight=c.weight;
        wheels=c.wheels;

        return *this;
    }
    Car& operator+=(const Car& c){
        std::cout<<"Add assignment operator car"<<std::endl;
        colorCar = c.colorCar;
        fuel=c.fuel;
        nrOfDoors += c.nrOfDoors;
        tire = c.tire;
        weight+=c.weight;
        wheels=c.wheels;

        return *this;
    }
    
    virtual void closeTheDoors(){
        std::cout<<"The doors was closed !"<<std::endl;
    } 

    void getNrOfDoors(){

        std::cout<<"Number of doors car : "<<this->nrOfDoors<<std::endl;
    }

    void setColor(const std::string &color){
        this->colorCar = color;
    }
    void getColor(){
        std::cout<<"Color is : "<<this->colorCar<<std::endl;
    }
    virtual void startTheEngine(){
        std::cout<<"The engine has been started !"<<std::endl;
    }
    ~Car(){
        std::cout<<"Desctructor car !"<<std::endl;
    }
    void setIsLocked(bool isLocked){
        this->isLocked=isLocked;
    }

    void askResource(){
        if(this->isLocked){
            std::cout<<"Acces denied ! "<<std::endl;
        }else{
            std::cout<<"You have acces ! "<<std::endl;
        }
    }

};