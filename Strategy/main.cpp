#include <iostream>

class INoise {
public:
    virtual ~INoise(){}
    virtual void drive() = 0;
};

class EletricCarNoise: public INoise {
public:
    void drive() override {
        std::cout << "vrmmmm" << std::endl;
    }
};

class NonEletricCarNoise: public INoise {
public:
    void drive() override {
        std::cout << "VRMMMMMM" << std::endl;
    }
};

class Car {
public:
    Car(INoise* noise): noise(noise) {

    }

    ~Car(){
    }

    void drive(){
        noise->drive();
    }

private:
    INoise* noise;
};

int main(){
    EletricCarNoise* eCarNoise = new EletricCarNoise();
    NonEletricCarNoise* nonCarNoise = new NonEletricCarNoise();
    Car* iX = new Car(eCarNoise);
    Car* i3 = new Car(eCarNoise);
    Car* M5 = new Car (nonCarNoise);

    iX->drive();
    i3->drive();
    M5->drive();

    delete eCarNoise;
    delete nonCarNoise;
    delete iX;
    delete i3;
    delete M5;
}