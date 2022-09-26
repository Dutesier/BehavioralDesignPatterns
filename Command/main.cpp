#include <iostream>

class Car {
public:
    void fullStop(){
        direction = 90;
    }
    void turn(int degree) {
        degree = degree % 360;
        direction += degree;
    }

    void printDirection() const {
        std::cout << "Current direction: " << direction << std::endl;
    }
private:
    unsigned int direction = 90;
};

// Commands
class ICommand{
public:
    virtual ~ICommand(){};
    virtual void execute() = 0;
};

class leftTurnCommand: public ICommand{
public:
    leftTurnCommand(Car *car) : car(car) {}
    void execute(){
        car->turn(15);
    }
private:
    Car* car;
};

class rightTurnCommand: public ICommand{
public:
    rightTurnCommand(Car *car) : car(car) {}
    void execute(){
        car->turn(-15);
    }
private:
    Car* car;
};

class stopCommand: public ICommand {
public:
    stopCommand(Car *car): car(car) {

    }
    void execute() override{
        car->fullStop();
    }
private:
    Car* car;
};

// Inputs
class Input {
public:
    Input(ICommand* command): command(command){}
    void trigger() {
        command->execute();
    }
private:
    ICommand *command;
};



int main() {
    Car *car = new Car;

    ICommand* leftTurn = new leftTurnCommand(car);
    ICommand* rightTurn = new rightTurnCommand(car);
    ICommand* stop = new stopCommand(car);
    Input* turnLeftInput = new Input(leftTurn);
    Input* turnRightInput = new Input(rightTurn);
    Input* emergencyInput = new Input(stop);

    car->printDirection();
    turnLeftInput->trigger();

    car->printDirection();
    for (int turns = 0; turns < 5; ++turns) {
        turnRightInput->trigger();
    }

    car->printDirection();
    emergencyInput->trigger();
    car->printDirection();

    delete leftTurn;
    delete rightTurn,
    delete stop;

    delete turnLeftInput;
    delete turnRightInput;
    delete emergencyInput;

    delete car;
}