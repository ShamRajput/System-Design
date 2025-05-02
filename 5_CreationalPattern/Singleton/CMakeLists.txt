cmake_minimum_required(VERSION 3.16)
project(Singleton)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")



# Add the source files
set(SOURCES
    main.cxx
    Singleton.cxx
)   
# Add the header files
set(HEADERS
    Singleton.hpp
)

# Add the executable
add_executable(Singleton ${SOURCES} ${HEADERS})
# Add the include directories
target_include_directories(Singleton PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
# Add the libraries
 set(LIBRARIES
    pthread
 )

target_link_libraries(Singleton ${LIBRARIES})



