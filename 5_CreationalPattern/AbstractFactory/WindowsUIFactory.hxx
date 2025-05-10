#pragma once
#include "UIAbstractFactory.hxx"


class WindowsUIFactory : public UIAbstractFactory
{
public:
    IButton* createButton() override;
    IScroll* createScrollBar() override;
};

