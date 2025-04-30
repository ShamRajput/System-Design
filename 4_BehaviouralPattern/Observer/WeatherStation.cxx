#include "WeatherStation.hxx"
#include <iomanip>
#include <iostream>

void WeatherStation::attach(std::shared_ptr<IObserver> &observer)
{
    mObservers.push_back(observer);
    mObservers.back()->update(mTemperature);
}
void WeatherStation::detach(std::shared_ptr<IObserver> &observer)
{
    auto it = std::remove_if(mObservers.begin(), mObservers.end(),
        [&observer](const std::shared_ptr<IObserver>& obs) {
            std::cout << "Observer to detach: " << observer.get() << std::endl;
            std::cout << "Observer in list: " << obs.get() << std::endl;
            std::cout << "Comparing: " << obs.get() << " == " << observer.get() << std::endl;
            return obs.get() == observer.get();
        });
    
    std::cout << "Observers to detach: " << mObservers.size() << std::endl;

    if (it != mObservers.end()) {
        std::cout << "Observer detached: " << observer.get() << std::endl; 
    } else {
        std::cout << "Observer not found: " << observer.get() << std::endl; 
    }
    mObservers.erase(it, mObservers.end());
  
}

void WeatherStation::notify()
{
    for (const auto& observer : mObservers) {
        observer->update(mTemperature);
    }
}

void WeatherStation::setTemperature(float temperature)
{
    mTemperature = temperature;
    notify();
}

float WeatherStation::getTemperature() const
{
    return mTemperature;
}
