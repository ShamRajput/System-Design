CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
# Set the project name
PROJECT(ObserverPattern)
# Set the C++ standard
SET(CMAKE_CXX_STANDARD 17)  
SET(CMAKE_CXX_STANDARD_REQUIRED True)
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -Wpedantic -Werror -g -O0")
SET(CMAKE_BUILD_TYPE Debug)
# Add the executable
ADD_EXECUTABLE(ObserverPattern main.cxx WeatherStation.cxx Screen2.cxx Screen1.cxx)
