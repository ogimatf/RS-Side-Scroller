project( side-scroller )

cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

set (CMAKE_CXX_STANDARD 11)

file(GLOB my_sources *.h *.cpp *.qrc)

set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

add_executable(side-scroller ${my_sources})

find_package(Qt5Widgets REQUIRED)

target_link_libraries(side-scroller Qt5::Widgets)
