#include <iostream>

class ILogger {
public:
    virtual ~ILogger(){}
    virtual void log(const std::string& message) = 0;
};

class ConsoleLogger: public ILogger {
public:
    void log(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

class FileLogger: public ILogger {
public:
    FileLogger(const std::string& file): file(file){

    }
    void log(const std::string& message) override {
        std::cout << "printing " << message << " to " << file << std::endl;
    }

private:
    std::string file;
};

class NullLogger: public ILogger{
public:
    void log(const std::string& message){
        static_cast<void>(message);
    }
};

class Task {
public:
    Task(){
        logger = new NullLogger;
    }

    ~Task(){
        delete logger;
    }

    Task(ILogger* logger): logger(logger){

    }

    void doSomething(){
        logger->log("[LOG] user x logged at xxxx@zzzz");
    }

private:
    ILogger* logger;
};

int main(){
    Task someTask(new ConsoleLogger);
    Task someOtherTask(new FileLogger("logs.txt"));
    Task anotherTask;

    someTask.doSomething();
    someOtherTask.doSomething();
    anotherTask.doSomething();
}