cmake_minimum_required(VERSION 3.16)
project(FactoryMethodApproach1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Add the source files
set(SOURCES
    main.cxx
    factorymethod.cxx
)

# Add the executable target
add_executable(${PROJECT_NAME} ${SOURCES})
# Add the include directories       