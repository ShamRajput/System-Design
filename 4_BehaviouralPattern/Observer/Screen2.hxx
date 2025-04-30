#pragma once

#include "IObserver.hxx"

class Screen2 : public IObserver {
public:
    Screen2() = default;
    ~Screen2() override = default;

    void update(float temperature) override;
};

