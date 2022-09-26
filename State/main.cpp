#include <iostream>

class IState{
public:
    virtual ~IState(){}

    virtual std::string getDescription() = 0;
    virtual IState* getNextState() = 0;
};

class CarMovingState : public IState {
public:
    CarMovingState(IState* nextState): nextState(nextState){}

    std::string getDescription() override {
        return "Current state: MOVING";
    }

    IState* getNextState() override {
        return nextState;
    }

private:
    IState* nextState = nullptr;
};

class CarStoppedState : public IState {
public:
    CarStoppedState(IState* nextState): nextState(nextState){}

    std::string getDescription() override {
        return "Current state: STOPPED";
    }

    IState* getNextState() override {
        return nextState;
    }

private:
    IState* nextState = nullptr;
};

class CarSpeedingState : public IState {
public:
    CarSpeedingState(IState* nextState): nextState(nextState){}

    std::string getDescription() override {
        return "Current state: SPEEDING";
    }

    IState* getNextState() override {
        return nextState;
    }

private:
    IState* nextState = nullptr;
};

class Car{
public:
    Car(const std::string& name, IState* firstState): carName(name), currentState(firstState)  {

    }

    std::string getDescription(){
        return currentState->getDescription();
    }

    void goToNextState() {
        if (currentState->getNextState())
            currentState = currentState->getNextState();
        else
            std::cout << "no more states" << std::endl;
    }
private:
    std::string carName;
    IState* currentState;
};

int main() {
    CarSpeedingState* speedingState = new CarSpeedingState(nullptr);
    CarMovingState* movingState = new CarMovingState(speedingState);
    CarStoppedState* stoppedState = new CarStoppedState(movingState);

    Car* car = new Car("M5", stoppedState);

    std::cout << car->getDescription() << std::endl;
    car->goToNextState();
    std::cout << car->getDescription() << std::endl;
    car->goToNextState();
    std::cout << car->getDescription() << std::endl;
    car->goToNextState();

    delete speedingState;
    delete movingState;
    delete stoppedState;
    delete car;
}