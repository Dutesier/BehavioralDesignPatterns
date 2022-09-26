#include <iostream>

class IMediator {
public:
    virtual ~IMediator(){}
    virtual void mediate(const std::string& event) = 0;
};

class UIElement {
public:
    UIElement(const std::string& name, bool isVisible, IMediator* mediator):
        name(name), isVisible(isVisible), mediator(mediator){

    }
    
    void setVisibility(bool isVisible){
        this->isVisible = isVisible;
    }

    std::string getDescription() {
        return name + (isVisible ? " is visible" : " is NOT visible");
    }

protected:
    std::string name;
    bool        isVisible;
    IMediator*  mediator;
};

class TextBox: public UIElement {
public:
    TextBox(const std::string& name, bool isVisible, IMediator* mediator): UIElement(name, isVisible, mediator) {}
};

class CheckBox: public UIElement {
public:
    CheckBox(const std::string& name, bool isVisible, IMediator* mediator): UIElement(name, isVisible, mediator) {}
};

class Button: public UIElement {
public:
    Button(const std::string& name, bool isVisible, IMediator* mediator): UIElement(name, isVisible, mediator) {}
    void click(){
        mediator->mediate(name + " is clicked");
    }
};

class UI : public IMediator {
public:
    UI() {
        nameTextBox = new TextBox("Name textbox", true, this);
        canDrive = new CheckBox("Can Drive Checkbox", true, this);
        carModel = new TextBox("Car Model textbox", false, this);
        submit = new Button("Submit button", false, this);
    }

    ~UI(){
        if (nameTextBox)
            delete nameTextBox;
        if (canDrive)
            delete canDrive;
        if (carModel)
            delete carModel;
        if (submit)
            delete submit;
    }

    void mediate(const std::string& event) override {
        std::cout << "Mediating event: " << event << std::endl;

        if (event == "Name textbox is empty") {
            submit->setVisibility(false);
        } else if (event == "Name textbox is NOT empty") {
            submit->setVisibility(true);
        } else if (event == "Can drive is checked") {
            carModel->setVisibility(true);
        } else if (event == "Can drive unchecked") {
            carModel->setVisibility(false);
        } else if (event == "Submit button is clicked") {
            std::cout << "Submit" << std::endl;
        } else {
            std::cout << "Unrecognized event" << std::endl;
        }
    }

    TextBox*    nameTextBox;
    CheckBox*   canDrive;
    TextBox*    carModel;
    Button*     submit;
private:
};

int main(void){
    UI* myUI = new UI;


    myUI->submit->click();

    delete myUI;
}