#pragma

// Wrong coding example which violates the Open/Closed Principle (OCP)


class Shape
{
public:
    virtual ~Shape() = default;
};

class Circle : public Shape
{
private:
    double mRadius;
public:
    Circle(double radius) : mRadius(radius) {}
 
};
class Rectangle : public Shape
{
private:
    double mWidth;
    double mHeight;
public:
    Rectangle(double width, double height) : mWidth(width), mHeight(height) {}
   
};

void createShape(const std::string& s)
{
    // code to create shape 
    if (s == "Circle")
    {
        Circle circle(5.0);
    }
    else if (s == "Rectangle")
    {
        Rectangle rectangle(4.0, 5.0);
    }
    else
    {
        /* code */
    }
    
}

//In this code class Shape is an abstract class that defines a common interface for all shapes.
//The Circle and Rectangle classes inherit from the Shape class and implement the area() method.
//The createShape function creates a shape based on the input string.
// This code violates the Open/Closed Principle (OCP) because if we want to add a new shape,
// we have to modify the createShape function.


class Shape
{
public:
    virtual ~Shape() = default;
    virtual void draw() const = 0; // pure virtual function
};

class Circle : public Shape
{
private:
    double mRadius;
public:
    Circle(double radius) : mRadius(radius) {}
    void draw() const override
    {
        // code to draw circle
    }
 
};
class Rectangle : public Shape
{
private:
    double mWidth;
    double mHeight;
public:
    Rectangle(double width, double height) : mWidth(width), mHeight(height) {}
    double draw() const override
    {
    }
   
};

void createShape(Shape& s  )  
{
    s.draw();
}

void main()
{
    Circle circle(5.0);
    Rectangle rectangle(4.0, 5.0);
    createShape(circle);
    createShape(rectangle);
}