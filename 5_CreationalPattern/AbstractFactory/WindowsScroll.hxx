#pragma once
#include "IScroll.hxx"

class WindowsScroll :public IScroll
{
public:
    void scroll() override;
    ~WindowsScroll() override = default;
};