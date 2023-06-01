# CMakeList.txt : CMake project for GameOfLife, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("GameOfLife")

# Add source to this project's executable.
add_executable (GameOfLife "GameOfLife.cpp" "GameOfLife.h" "Board.cpp" "Board.h" "Keyboard.cpp" "Keyboard.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET GameOfLife PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
