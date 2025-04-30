class IWorker
{
public:
    virtual void work() = 0;
    virtual void eat() = 0;
    virtual void sleep() = 0;

    virtual ~IWorker() {}
};

class Robot : public IWorker
{
public:
    void work() override
    {
        // Robot working
    }

    void eat() override
    {
        // Robot doesn't eat
        throw std::logic_error("Robot doesn't eat");
    }

    void sleep() override
    {
        // Robot doesn't sleep
        throw std::logic_error("Robot doesn't sleep");
    }
};
class Human : public IWorker
{   
public:
    void work() override
    {
        // Human working
    }

    void eat() override
    {
        // Human eating
    }

    void sleep() override
    {
        // Human sleeping
    }
};
void processWorker(IWorker& worker)
{
    worker.work();
    worker.eat();
    worker.sleep();
}
int main()
{
    Robot robot;
    Human human;

    processWorker(robot); // This will throw an exception
    processWorker(human);

    return 0;
}


/// purpose of this code is to demonstrate the Interface Segregation Principle (ISP) 
/// which states that no client should be forced to depend on methods it does not use.
/// In this case, the Robot class is forced to implement the eat() and sleep() methods,
/// even though it doesn't need them.
/// To fix this, we can create separate interfaces for different types of workers.

class IWorkable
{   
public:
    virtual void work() = 0;
    virtual ~IWorkable() {}
};

class IEatable
{
public:
    virtual void eat() = 0;
    virtual ~IEatable() {}
};

class ISleepable
{
public:
    virtual void sleep() = 0;
    virtual ~ISleepable() {}
};
class Robot : public IWorkable
{
public:
    void work() override
    {
        // Robot working
    }
};
class Human : public IWorkable, public IEatable, public ISleepable
{   
public:
    void work() override
    {
        // Human working
    }

    void eat() override
    {
        // Human eating
    }

    void sleep() override
    {
        // Human sleeping
    }
};
void processWorkable(IWorkable& worker)
{
    worker.work();
}
void processEatable(IEatable& worker)
{
    worker.eat();
}
void processSleepable(ISleepable& worker)
{
    worker.sleep();
}
int main()
{
    Robot robot;
    Human human;

    processWorkable(robot);
    processWorkable(human);

    // The following lines will work without any exceptions
    // because the Robot class doesn't implement eat() and sleep()
    // and the Human class implements all three interfaces.
    // processEatable(robot); // This will throw an exception
    processEatable(human);

    // processSleepable(robot); // This will throw an exception
    processSleepable(human);

    return 0;
}