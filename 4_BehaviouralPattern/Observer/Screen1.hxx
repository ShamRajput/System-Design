#pragma once

#include "IObserver.hxx"

class Screen1 : public IObserver {
public:
    Screen1() = default;
    ~Screen1() override = default;

    void update(float temperature) override;
};

