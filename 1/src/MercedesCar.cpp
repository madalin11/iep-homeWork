#include<iostream>
//#include"Car.cpp"
#include"BMWcar.cpp"


class MercedesCar:public BMWcar{
    protected:
    std::string mercedesAI;

    public:
    MercedesCar(const std::string &mAI,const std::string &ins,const std::string &color ,const int &nr ,const  int &w,const std::string &wh , const std::string &tr,const std::string &f)
    :BMWcar(ins,color,nr,w,wh,tr,f),
    mercedesAI(mAI){
        std::cout<<"Mercedes constructor"<<std::endl;
    }
    MercedesCar(const MercedesCar &m):BMWcar(m){
        this->mercedesAI = m.mercedesAI;
        std::cout<<"Copy constructor mercedes !"<<std::endl;
    }
    void closeTheDoors(){
        Car::closeTheDoors();
        std::cout<<"Welcome to Mercedes !"<<std::endl;
    }
    void startTheEngine(){
        Car::startTheEngine();
        std::cout<<"Mercedes is here. Have a wonderful road !"<<std::endl;
    }
    void getNrOfDoors(){

        std::cout<<"Number of doors mercedes: "<<this->nrOfDoors<<std::endl;
    }
    void setMercedesAI(const std::string &newMercedesAI){
        this->mercedesAI = newMercedesAI;
    }
    void getMercedesAI(){
        std::cout<<"Mercedes AI : "<<this->mercedesAI<<std::endl;
    }
    ~MercedesCar(){
        std::cout<<"Destructor Mercedes"<<std::endl;
    }
};