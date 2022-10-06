#include <iostream>
    // write instances of the classes to a database
class IVisitor{
public:
    virtual ~IVisitor(){};
    virtual void handlePerson(const std::string& name, int age) = 0;
    virtual void handleCity(const std::string& name, int areaCode) = 0;
    virtual void handleCar(const std::string& make, const std::string& model) = 0;
};

class DatabaseVisitor: public IVisitor{
public:
    virtual void handlePerson(const std::string& name, int age){
        std::cout << "Some methodology to write a person to a database" <<  name << age << std::endl;
    }
    virtual void handleCity(const std::string& name, int areaCode){
        std::cout << "Some different methodology to write a city to a database" << name << areaCode << std::endl;
    }
    virtual void handleCar(const std::string& make, const std::string& model){
        std::cout << "Some different methodology to write a car to a database" << make << model << std::endl;
    }

};

class FileVisitor: public IVisitor{
public:
    virtual void handlePerson(const std::string& name, int age){
        std::cout << "Some methodology to write a person to a file" << name << age << std::endl;
    }
    virtual void handleCity(const std::string& name, int areaCode){
        std::cout << "Some different methodology to write a city to a file" << name << areaCode << std::endl;
    }
    virtual void handleCar(const std::string& make, const std::string& model){
        std::cout << "Some different methodology to write a car to a file" << make << model << std::endl;
    }

};

class Person {
public:
    Person(const std::string& name, int age): name(name), age(age){

    }
    void accept(IVisitor *v){
        v->handlePerson(name, age);
    }
private:
    const std::string name;
    int age;
};

class City {
public:
    City(const std::string& name, int areaCode): name(name), areaCode(areaCode){

    }
    void accept(IVisitor *v){
        v->handleCity(name, areaCode);
    }
private:
    const std::string name;
    int areaCode;
};

class Car {
public:
    Car(const std::string& make, const std::string& model): make(make), model(model){

    }
    void accept(IVisitor *v){
        v->handleCar(make, model);
    }
private:
    const std::string make;
    const std::string model;
};

int main(){
    Person person("John", 42);
    City city("Lisbon", 1400);
    Car car("BMW", "X5");

    DatabaseVisitor dbVisitor;
    FileVisitor fVisitor;

    person.accept(&dbVisitor);
    person.accept(&fVisitor);
    city.accept(&dbVisitor);
    city.accept(&fVisitor);
    car.accept(&dbVisitor);
    car.accept(&fVisitor);
}