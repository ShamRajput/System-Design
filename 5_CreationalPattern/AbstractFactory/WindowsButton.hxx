#pragma once
#include "IButton.hxx"

class WindowsButton :public IButton
{
public:
    void render() override;
    ~WindowsButton() override = default;
};