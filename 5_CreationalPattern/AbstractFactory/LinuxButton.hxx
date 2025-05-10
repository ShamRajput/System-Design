#pragma once
#include "IButton.hxx"

class LinuxButton :public IButton
{
public:
    void render() override;
    ~LinuxButton() override = default;
};