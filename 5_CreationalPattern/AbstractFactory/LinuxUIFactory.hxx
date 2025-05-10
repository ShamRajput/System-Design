#pragma once
#include "UIAbstractFactory.hxx"


class LinuxUIFactory : public UIAbstractFactory
{
public:
    IButton* createButton() override;
    IScroll* createScrollBar() override;
};
