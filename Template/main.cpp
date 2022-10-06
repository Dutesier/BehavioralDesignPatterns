#include <iostream>

class GreetingCardTemplate{
protected:
    virtual std::string intro(const std::string& nameTo){
        return "Dear " + nameTo + ",\n";
    }

    virtual std::string occasion(){
        return "Just writing to say hi, hope all is well.\n";
    }

    virtual std::string closing(const std::string& from){
        return "Sincerely, " + from + "\n";
    }

public:
    std::string generate(const std::string& nameTo, const std::string& from){
        return intro(nameTo) + occasion() + closing(from);
    }
};

class BirthdayClassTemplate: public GreetingCardTemplate{
protected:
    std::string occasion() override {
        return "I'm writing to wish you a happy birthday!\n";
    }
};

class NewYearsCardTemplate: public GreetingCardTemplate{
protected:
    std::string intro(const std::string& nameTo) override {
        return nameTo + "!!!!\n";
    }

    std::string occasion() override {
        return "Happy New Year\n";
    }
};

int main(){
    GreetingCardTemplate gct;
    BirthdayClassTemplate bct;
    NewYearsCardTemplate nyct;

    std::cout << gct.generate("Bob", "Dylan") << std::endl;
    std::cout << bct.generate("Marley", "Bob") << std::endl;
    std::cout << nyct.generate("Bob", "Ross") << std::endl;
}