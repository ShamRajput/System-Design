#include "IObserver.hxx"
#include "ISubject.hxx"
#include "WeatherStation.hxx"
#include "Screen1.hxx"
#include "Screen2.hxx"
#include <iostream>
#include <memory>

int main() {
    // Create a WeatherStation instance
    WeatherStation weatherStation;

    // Create observer instances
    std::shared_ptr<IObserver> screen1 = std::make_shared<Screen1>();
    std::shared_ptr<IObserver> screen2 = std::make_shared<Screen2>();

    // Attach observers to the weather station
    weatherStation.attach(screen1);
    weatherStation.attach(screen2);

    // Set temperature and notify observers
    weatherStation.setTemperature(25.0f);
    weatherStation.setTemperature(30.0f);

    // Detach an observer and set temperature again
    weatherStation.detach(screen1);
    weatherStation.detach(screen2);
    weatherStation.setTemperature(35.0f);

    return 0;
}