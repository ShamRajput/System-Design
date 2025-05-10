#pragma once

class IButton
{
public:
    virtual void render() = 0;
    virtual ~IButton() = default;
};
