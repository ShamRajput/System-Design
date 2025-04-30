#include "Screen1.hxx"
#include <iostream>

void Screen1::update(float temperature)
{
    std::cout << "Screen1: Temperature updated to " << temperature << " degrees." << std::endl;
}