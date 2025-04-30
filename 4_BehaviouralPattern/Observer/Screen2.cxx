#include "Screen2.hxx"
#include <iostream>

void Screen2::update(float temperature)
{
    std::cout << "Screen2: Temperature updated to " << temperature << " degrees." << std::endl;
}