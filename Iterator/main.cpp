#include <iostream>
#include <vector>

class INumberIterator{
public:
    ~INumberIterator(){};
    virtual int next() = 0;
    virtual bool isFinished() = 0;
};

class ForwardsIterator: public INumberIterator{
public:
    ForwardsIterator(std::vector<int>& numbers) : currentPosition(0), numbers(numbers) {

    }

    int next() override {
        int current = numbers.at(currentPosition);
        
        currentPosition += 1;
        return current;
    }

    bool isFinished() override {
        return currentPosition >= static_cast<int>(numbers.size());
    }

private:
    int currentPosition;
    std::vector<int>& numbers;
};

class BackwardsIterator: public INumberIterator{
public:
    BackwardsIterator(std::vector<int>& numbers) : currentPosition(numbers.size() - 1), numbers(numbers) {

    }

    int next() override {
        int current = numbers.at(currentPosition);
        
        currentPosition -= 1;
        return current;
    }

    bool isFinished() override {
        return currentPosition < 0;
    }

private:
    int currentPosition;
    std::vector<int>& numbers;
};

class NumberCollection {
public:
    NumberCollection(std::vector<int>& numbers): numbers(numbers){

    }

    INumberIterator* getForwardsIterator(){
        return new ForwardsIterator(numbers);
    }

    INumberIterator* getBackwardsIterator(){
        return new BackwardsIterator(numbers);
    }


private:
    std::vector<int>& numbers;
};

int main(){
    std::vector<int> numbers;

    for (int i = 0; i < 100; ++i){
        numbers.push_back(i);
    }

    NumberCollection coll(numbers);

    INumberIterator* forw = coll.getForwardsIterator();
    INumberIterator* back = coll.getBackwardsIterator();

    while (!forw->isFinished()){
        std::cout << forw->next() << std::endl;
    }

    while (!back->isFinished()){
        std::cout << back->next() << std::endl;
    }

    delete forw;
    delete back;
}