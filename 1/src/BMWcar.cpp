#include<iostream>
#include "Car.cpp"

class BMWcar:public Car{

    protected:
    std::string inscription;

    public:
    BMWcar(const std::string &ins,const std::string &color ,const int &nr ,const  int &w,const std::string &wh , const std::string &tr,const std::string &f)
    :Car(color,nr,w,wh,tr,f),
    inscription(ins){
        
        std::cout<<"BMW constructor"<<std::endl;
    }
    BMWcar(const BMWcar &b):Car(b){
        this->inscription = b.inscription;
        std::cout<<"copy constructor BMW"<<std::endl;
    }

    void getNrOfDoors(){
        std::cout<<"Number of doors BMW: "<<this->nrOfDoors<<std::endl;
    }
    void startTheEngine(){
        Car::startTheEngine();
        std::cout<<"BMW is that monster. Have a fast driving !"<<std::endl;
    }
    void closeTheDoors(){
        Car::closeTheDoors();
        std::cout<<"Welcome to BMW !"<<std::endl;
    }
    virtual ~BMWcar(){
        std::cout<<"Destructor bmw"<<std::endl;
    }
};