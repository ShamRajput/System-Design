cmake_minimum_required(VERSION 3.16)
project(AbstractFactory)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

add_executable(AbstractFactory main.cxx
    LinuxUIFactory.cxx
    WindowsUIFactory.cxx
    LinuxScroll.cxx
    LinuxButton.cxx
    WindowsButton.cxx
    WindowsScroll.cxx
    Application.cxx
)