#include <iostream>
#include <vector>
class Canvas;

class CanvasMemento{
    friend class Canvas;
public:
    CanvasMemento(std::vector<std::string> shapes): shapes(shapes){

    }
private:
    const std::vector<std::string> shapes;
};

class Canvas{
public:
    ~Canvas(){
        for (auto i : oldStates){
            delete i;
        }
        oldStates.clear();
    }
    void addShape(const std::string& newShape){
        oldStates.push_back(new CanvasMemento(shapes));
        shapes.push_back(newShape);
    }

    void undo(){
        CanvasMemento *previousState = oldStates.back();
        oldStates.pop_back();
        shapes = previousState->shapes;
        delete previousState;
    }

    void clearAll(){
        shapes.clear();
    }

    std::vector<std::string> getShapes() {
        return shapes;
    }
private:
    std::vector<std::string> shapes;
    std::vector<CanvasMemento*> oldStates;
};

int main(){
    Canvas cv;

    cv.addShape("rhombus");
    cv.addShape("circle");
    cv.addShape("square");
    cv.addShape("triangle");

    for (auto shape : cv.getShapes()){
        std::cout << shape << std::endl;
    }
    std::cout << std::endl;

    cv.undo();
    for (auto shape : cv.getShapes()){
        std::cout << shape << std::endl;
    }
    std::cout << std::endl;


    cv.addShape("rhombus");
    cv.addShape("circle");
    cv.addShape("square");
    cv.addShape("triangle");
    cv.undo();

    for (auto shape : cv.getShapes()){
        std::cout << shape << std::endl;
    } 
}