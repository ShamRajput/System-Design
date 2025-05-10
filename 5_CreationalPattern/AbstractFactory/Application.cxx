#include "Application.hxx"
#include "UIAbstractFactory.hxx"
#include "IButton.hxx"
#include "IScroll.hxx"  
#include <iostream>

Application::Application(UIAbstractFactory *factory)
{
    mButton = factory->createButton();
    mScrollBar = factory->createScrollBar();
}

Application::~Application()
{
    delete mButton;
    delete mScrollBar; 
    mButton = nullptr;
    mScrollBar = nullptr;
}

void Application::run()
{
   mButton->render();
   mScrollBar->scroll();
}
