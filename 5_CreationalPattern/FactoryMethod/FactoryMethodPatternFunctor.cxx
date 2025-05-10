#include <iostream>
#include <functional>
#include <memory>
#include <stdexcept>

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


class IShapeFactory final
{
   inline static std::function<std::unique_ptr<IShape>()> mCreateShape;
public:
    IShapeFactory(const IShapeFactory&) = delete;
    IShapeFactory& operator=(const IShapeFactory&) = delete;
    IShapeFactory(IShapeFactory&&) = delete;
    IShapeFactory& operator=(IShapeFactory&&) = delete;
    IShapeFactory() = delete;
    ~IShapeFactory() = default;
    static void registerFactory(const std::function<std::unique_ptr<IShape>()>& factory) {
        mCreateShape = factory;
    }
    static std::unique_ptr<IShape> getInstance() {
        if (mCreateShape) {
            return mCreateShape();
        }
        return nullptr;
    }
};

int main() {
    

    IShapeFactory::registerFactory([]()-> std::unique_ptr<IShape> {
        return std::make_unique<Circle>();
    });

    std::unique_ptr<IShape> shape = IShapeFactory::getInstance();
    shape->draw();
    
   
    
    return 0;
}
