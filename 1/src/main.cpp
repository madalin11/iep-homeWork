#include <iostream>
//#include "Car.cpp"
#include "MercedesCar.cpp"
#include<memory>



using namespace std;
Car* CreateCarInstance(){
    return (new Car("blue", 5,23,"aliaj","continental","petrol"));
}
void lock(Car &c){
    std::cout<<"Locking "<<std::endl;
    c.setIsLocked(true);
}
void unlock(Car &c){
    std::cout<<"Unlocking "<<std::endl;
    c.setIsLocked(false);
}

class Lock{
    private:
    Car &lockPtr;

    public:
    Lock(Car &ptr):
    lockPtr(ptr){
        lock(lockPtr);
    }
    ~Lock(){
        unlock(lockPtr);
    }
};
int main()
{   
    std::cout<<"ana"<<std::endl;

    BMWcar b1("BMW","red",5,1700,"aliaj","Continental","gas");
    {
        Car *c1= new BMWcar("BMW","white",4,1500,"aliaj","Continental","diesel");
        c1->getColor();
        c1->setColor("green");
        c1->getColor();
        c1->startTheEngine();
        c1->getNrOfDoors();
        *c1+=b1;
        c1->getNrOfDoors();
        delete c1;  
    }
    BMWcar b3(b1);
    MercedesCar *m1= new MercedesCar("Autonom driving 3.0","Mercedes","blue",4,1900,"aliaj","Continental","petrol");
    
    m1->getNrOfDoors();
    b1.closeTheDoors();
    m1->closeTheDoors();
    
    m1->startTheEngine();
    BMWcar b4(b1);
    BMWcar b5(b1);
    b5.getNrOfDoors();
    b5=b5;
    b5=b4=b1;
    b5.getNrOfDoors();
    b5+=b4+=b1;
    b5.getNrOfDoors();
    b5.getColor();
    b5.colorCar="dark";
    b4 = b5;
    b4.getColor();
    MercedesCar m3(*m1);

    delete m1;

    std::cout<<"   auto "<<std::endl;
    {
        auto_ptr<Car> car1(CreateCarInstance());
        car1->getColor();
        auto_ptr<Car> car2(car1);
        car2->getColor();

        //car1->getColor();
    }

    std::cout<<"  unique"<<std::endl;
    {
        unique_ptr<Car> car3(CreateCarInstance());
        car3->getNrOfDoors();
        unique_ptr<Car> car4 = move(car3);


    }
    std::cout<<"  shared"<<std::endl;
    {
        shared_ptr<Car> sharedCar(CreateCarInstance());
        sharedCar->getNrOfDoors();
        std::cout<<"sharedCar count = " <<sharedCar.use_count()<<std::endl;
        shared_ptr<Car> sharedCar2(sharedCar);
        std::cout<<"sharedCar count = " <<sharedCar.use_count()<<std::endl;
        sharedCar2->getColor();
        sharedCar2->setColor("white");
        sharedCar->getColor();

        shared_ptr<Car> sharedCar3=move(sharedCar);
        std::cout<<"sharedCar count = " <<sharedCar.use_count()<<std::endl;
        std::cout<<"sharedCar3 count = " <<sharedCar3.use_count()<<std::endl;
        sharedCar3->setColor("rosu");
        sharedCar3->getColor();

        sharedCar2->getColor();

        std::cout<<"    weak"<<std::endl;
        weak_ptr<Car> weakCar(sharedCar3);
        std::cout<<"sharedCar3 count = " <<sharedCar3.use_count()<<std::endl;


        
    }

    Car CarP("black",23,45,"aliaj","continental","benzina");
    Lock *locked = new Lock(CarP);
    CarP.askResource();
    delete locked;
    CarP.askResource();

    return 0;
}

