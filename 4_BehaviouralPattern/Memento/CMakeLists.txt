cmake_minimum_required(VERSION 3.10)

# Set the project name
project(MementoPattern)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(MementoPattern main.cxx
TextEditor.cxx
TextEditorMemento.cxx
History.cxx)

# Include directories
include_directories(include)

# Include directories (if needed)
# target_include_directories(MementoPattern PRIVATE include)

# Link libraries (if needed)
# target_link_libraries(MementoPattern PRIVATE some_library)