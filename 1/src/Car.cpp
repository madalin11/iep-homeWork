#include<iostream>

class Car{

    protected:

    std::string colorCar;
    int nrOfDoors;
    int weight;
    std::string wheels;
    std::string tire;
    std::string fuel;

    public:

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
    };

    Car& operator=(const Car& c)=delete;
    
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

};