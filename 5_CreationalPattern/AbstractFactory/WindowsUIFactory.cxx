#include "WindowsUIFactory.hxx"
#include "IButton.hxx"
#include "IScroll.hxx"
#include "WindowsButton.hxx"
#include "WindowsScroll.hxx"

IButton* WindowsUIFactory::createButton()
{
    return new WindowsButton();
}

IScroll* WindowsUIFactory::createScrollBar()
{
    return new WindowsScroll();
}
