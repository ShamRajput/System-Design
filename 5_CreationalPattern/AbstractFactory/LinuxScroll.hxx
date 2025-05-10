#pragma once
#include "IScroll.hxx"

class LinuxScroll :public IScroll
{
public:
    void scroll() override;
    ~LinuxScroll() override = default;
};