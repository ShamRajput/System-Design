#pragma once
class IButton;
class IScroll;
class UIAbstractFactory;


class Application
{
private:
    IButton* mButton;
    IScroll*  mScrollBar;
public:
    Application(UIAbstractFactory* factory);
    ~Application();

    void run();
};