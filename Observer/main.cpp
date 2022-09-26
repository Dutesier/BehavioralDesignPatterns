#include <iostream>
#include <vector>
#include <algorithm>

class ISubscriber {
public:
    virtual void Notify(const std::string& publisher_name, const std::string& message) = 0;
    virtual std::string getName() = 0;
    virtual ~ISubscriber(){};
};

class IPublisher {
public:
    virtual void Subscribe(ISubscriber* subscriber) = 0;
    virtual void Unsubscribe(ISubscriber* subscriber) = 0;
    virtual void Publish(const std::string& message) = 0;
    virtual ~IPublisher() {};
};

class ChatGroup: public IPublisher {
public:
    ChatGroup(std::string name): groupName(name) {

    }

    void Subscribe(ISubscriber* subscriber) override {
        subscribers.push_back(subscriber);
    }

    void Unsubscribe(ISubscriber* subscriber) override {
        subscribers.erase(std::remove_if(subscribers.begin(), subscribers.end(),
            [subscriber](ISubscriber *s){
                return (s->getName() == subscriber->getName());
            }
        )); // Erases every subscription where name = subscriber.name
    }

    void Publish(const std::string& message) override {
        for (auto subscriber : subscribers) {
            subscriber->Notify(groupName, message);
        }
    }

private:
    std::vector<ISubscriber*>   subscribers;
    std::string                 groupName;

};

class ChatUser: public ISubscriber {
public:
    ChatUser(const std::string& name): name(name) {

    }

    void Notify(const std::string& publisher_name, const std::string& message) override {
        std::cout << name << " received a new message from " << publisher_name << ":\n"
            << message << std::endl;
    }

    std::string getName() override {
        return name;
    }


private:
    std::string   name;
};

int main(){
    ChatUser* UserOne = new ChatUser("Jax");
    ChatUser* UserTwo = new ChatUser("Chibs");
    ChatUser* UserThree = new ChatUser("Tig");

    ChatGroup* mom = new ChatGroup("Men of Mayhem");

    mom->Subscribe(UserOne);
    mom->Subscribe(UserTwo);
    mom->Subscribe(UserThree);

    mom->Publish("Church is in session");
    

    delete UserOne;
    delete UserTwo;
    delete UserThree;

    delete mom;
}
