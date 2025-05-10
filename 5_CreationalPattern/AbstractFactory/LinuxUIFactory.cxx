#include "LinuxUIFactory.hxx"
#include "IButton.hxx"
#include "IScroll.hxx"
#include "LinuxButton.hxx"
#include "LinuxScroll.hxx"

IButton* LinuxUIFactory::createButton()
{
    return new LinuxButton();
}

IScroll* LinuxUIFactory::createScrollBar()
{
    return new LinuxScroll();
}
