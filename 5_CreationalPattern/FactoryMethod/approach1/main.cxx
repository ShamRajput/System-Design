#include <iostream>
#include "factorymethod.hpp"

int main() {
    
    Shapetype shapeType = Shapetype::CircleType;
    auto* shape = IShapeFactory::createShape(shapeType);
    shape->draw();
    delete shape;
    shape = nullptr;
    std::cout << "------------------------" << std::endl;
    // Create a square
    shapeType = Shapetype::SquareType;
    shape = IShapeFactory::createShape(shapeType);
    shape->draw();

    delete shape;
    shape = nullptr;


    shapeType = Shapetype::CircleType;
    std::unique_ptr<IShape> cirFactory = IShapeFactoryUniquePtr::createShape(shapeType);
    cirFactory->draw();
    std::cout << "------------------------" << std::endl;
    // Create a square
    shapeType = Shapetype::SquareType;
    std::unique_ptr<IShape> sqFactory = IShapeFactoryUniquePtr::createShape(shapeType);
    sqFactory->draw();

    return 0;
}