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
    BMWcar& operator=(const BMWcar& c){
        std::cout<<"Copy assignment operator BMW"<<std::endl;
        if(this==&c){
            std::cout<<"Assign to self Bmw"<<std::endl;

            return *this;
        }
        Car::operator=(c);
        inscription=c.inscription;
        return *this;
    }
    BMWcar& operator+=(const BMWcar& c){
        std::cout<<"ADD operator BMW"<<std::endl;
        Car::operator+=(c);
        inscription=c.inscription;
        return *this;
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
     ~BMWcar(){
        std::cout<<"Destructor bmw"<<std::endl;
    }
};