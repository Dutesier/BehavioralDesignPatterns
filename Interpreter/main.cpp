#include <iostream>

class IExpression {
public:
    virtual ~IExpression(){};
    virtual int evaluate() = 0;
};

class OperationExpression: public IExpression {
public:
    OperationExpression(const std::string& symbol, IExpression* lhs, IExpression* rhs):
        operatorSymbol(symbol),
        lhs(lhs),
        rhs(rhs){

    }

    int evaluate() override {
        if (operatorSymbol == "+")
            return lhs->evaluate() + rhs->evaluate();
        else if (operatorSymbol == "-")
            return lhs->evaluate() - rhs->evaluate();
        else if (operatorSymbol == "*")
            return lhs->evaluate() * rhs->evaluate();
        else if (operatorSymbol == "/")
            return lhs->evaluate() / rhs->evaluate();
        else {
            std::cout << "Unrecognized Operator " << operatorSymbol << std::endl; 
            return 0;
        }
    }

private:
    std::string     operatorSymbol;
    IExpression*    lhs;
    IExpression*    rhs;

};

class NumberExpression: public IExpression {
public:
    NumberExpression(const std::string& number) :
        numberString(number) {

    }

    int evaluate() override {
        return (std::stoi(numberString));
    }

private:
    std::string numberString;
};


int main() {
    NumberExpression *four = new NumberExpression("4");
    NumberExpression *two = new NumberExpression("2");

    OperationExpression *fourPlusTwo = new OperationExpression("+", four, two);

    std::cout << fourPlusTwo->evaluate() << std::endl;

    NumberExpression *seven = new NumberExpression("7");
    OperationExpression *complex = new OperationExpression("*", seven, fourPlusTwo);

    std::cout << complex->evaluate() << std::endl;

    delete four;
    delete two;
    delete fourPlusTwo;
    delete seven;
    delete complex;
}