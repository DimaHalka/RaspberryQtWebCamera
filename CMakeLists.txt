cmake_minimum_required(VERSION 3.5)

project(QtWebCamera VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})

find_package(Qt6 REQUIRED COMPONENTS
    Widgets
)

set(PROJECT_SOURCES
        main.cpp
)

qt_add_executable(QtWebCamera MANUAL_FINALIZATION ${PROJECT_SOURCES})

target_link_libraries(QtWebCamera PRIVATE
    Qt6::Widgets
    ${OpenCV_LIBS}
)

install(TARGETS QtWebCamera
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

qt_finalize_executable(QtWebCamera)
