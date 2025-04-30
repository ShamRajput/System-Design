#pragma once

#include "ISubject.hxx"
#include "IObserver.hxx"
#include <vector>
#include <memory>
#include <algorithm>

class WeatherStation : public ISubject {
    public:
        WeatherStation() = default;
        ~WeatherStation() override = default;

        void attach(std::shared_ptr<IObserver>& observer) override;
        void detach(std::shared_ptr<IObserver>& observer) override;
        void notify() override;

        void setTemperature(float temperature);
        float getTemperature() const;

    private:
        std::vector<std::shared_ptr<IObserver>> mObservers;
        float mTemperature;
};