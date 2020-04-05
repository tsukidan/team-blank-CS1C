cmake_minimum_required(VERSION 3.5)

project(P2 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets Sql REQUIRED)

add_executable(P2
  src/main.cpp
  src/mainwindow.cpp
  src/mainwindow.h
  src/mainwindow.ui
  src/loginwindow.cpp
  src/loginwindow.h
  src/loginwindow.ui
  src/setupwindow.cpp
  src/setupwindow.h
  src/setupwindow.ui
  src/user.h
  src/user.cpp
  src/dbutils.h
  src/dbutils.cpp
)

target_link_libraries(P2 PRIVATE Qt5::Widgets Qt5::Sql)
