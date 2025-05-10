#pragma once
class IButton;
class IScroll;

class UIAbstractFactory
{
public:
    virtual ~UIAbstractFactory() = default;

    virtual IButton* createButton() = 0;
    virtual IScroll*  createScrollBar() = 0;
};