cmake_minimum_required(VERSION 3.5)
project(SimpleKeypad CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5Widgets REQUIRED)

add_executable(simple_keypad main.cpp keypad_widget.h keypad_widget.cpp)
set_property(TARGET simple_keypad PROPERTY CXX_STANDARD 11)
target_link_libraries(simple_keypad Qt5::Widgets)
