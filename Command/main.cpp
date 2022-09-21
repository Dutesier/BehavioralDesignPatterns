#include <iostream>

class Car {
public:
    void fullStop(){
        direction = 90;
    }
    void turn(unsigned int degree) {
        degree = degree % 360;
        direction += degree;
    }
private:
    unsigned int direction;
};

class IDirectionCommand{
public:
    virtual ~IDirectionCommand(){};
    virtual void change_direction() = 0;
};

class leftTurn: public IDirectionCommand{
public:
    
private:
    Car* car;

};