#include <iostream>

struct Road{
    int     initialized = 0;
    int     countryCode;
    bool    hasRained;
};

class RoadValidator {
public:
    virtual ~RoadValidator(){}
    virtual RoadValidator *setNext(RoadValidator *nextValidator) = 0;
    virtual std::string validate(Road* road) = 0;
};

class BaseValidator: public RoadValidator { // Implement common logic
public:
    virtual ~BaseValidator(){
        delete next;
    }

    RoadValidator *setNext(RoadValidator *nextValidator) {
        next = nextValidator;
        return next;
    }

    std::string validate(Road* road) override {
        if (this->next)
            return (this->next->validate(road));
        return ("Success\n");
    }

protected:
    RoadValidator*  next = nullptr;
};

class NotEmptyValidator: public BaseValidator {
public:
    std::string validate(Road* road) override {
        std::cout << "Checking if empty" << std::endl;
        if (!(road->initialized))
            return "Please configure the road before validating (road->initialized == 0)\n";
        return BaseValidator::validate(road);
    }
};

class  PotholeValidator: public BaseValidator{
public:
    std::string validate(Road* road) override {
        std::cout << "Checking if your country has potholes" << std::endl;
        if ((road->countryCode == 351))
            return "Danger: You live in Portugal\n";
        return BaseValidator::validate(road);
    }
};

class  HasRainedValidator: public BaseValidator{
public:
    std::string validate(Road* road) override {
        std::cout << "Checking if it has rained" << std::endl;
        if ((road->hasRained))
            return "Road is Wet!!\n";
        return BaseValidator::validate(road);
    }
};

int main(){
    Road goodRoad;
    goodRoad.countryCode = 352;
    goodRoad.hasRained = 0;
    goodRoad.initialized = 1;

    Road badRoadCountry;
    badRoadCountry.countryCode = 351;
    badRoadCountry.hasRained = 0;
    badRoadCountry.initialized = 1;

    Road badRoadRain;
    badRoadRain.countryCode = 352;
    badRoadRain.hasRained = 1;
    badRoadRain.initialized = 1;

    Road badRoadInit;
    badRoadInit.countryCode = 352;
    badRoadInit.hasRained = 0;
    badRoadInit.initialized = 0;

    RoadValidator* roadVal = new BaseValidator;
    roadVal->setNext(new PotholeValidator)
            ->setNext(new HasRainedValidator)
            ->setNext(new NotEmptyValidator);
    
    std::cout << roadVal->validate(&goodRoad) << std::endl;
    std::cout << roadVal->validate(&badRoadCountry) << std::endl;
    std::cout << roadVal->validate(&badRoadRain) << std::endl;
    std::cout << roadVal->validate(&badRoadInit) << std::endl;

    delete roadVal;
}