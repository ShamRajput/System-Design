
#pragma once 
#include <iostream>
#include <memory>

class IShape
{
public:
    virtual void draw() = 0;
    virtual ~IShape() = default;
};
class Circle : public IShape
{
public:
    void draw() override {
        std::cout << "Drawing Circle" << std::endl;
    }
};
class Square : public IShape
{
public:
    void draw() override {
        std::cout << "Drawing Square" << std::endl;
    }
};
enum class Shapetype
{
    CircleType = 1,
    SquareType = 2
};


class IShapeFactory
{
    public:
    static IShape* createShape(Shapetype shapeType) {
        switch (shapeType) {
            case Shapetype::CircleType:
                return new Circle();
            case Shapetype::SquareType:
                return new Square();
            default:
                return nullptr;
        }
    }
};


class IShapeFactoryUniquePtr
{
    public:
    static std::unique_ptr<IShape> createShape(Shapetype shapeType) {
        switch (shapeType) {
            case Shapetype::CircleType:
                return std::make_unique<Circle>();
            case Shapetype::SquareType:
                return std::make_unique<Square>();
            default:
                return nullptr;
        }
    }
};
