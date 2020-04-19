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
  src/member.h
  src/member.cpp
  src/memberlisttab.cpp
  src/memberlisttab.h
  src/memberlisttab.ui
  src/membersmodel.h
  src/membersmodel.cpp
  src/item.h
  src/item.cpp
  src/purchase.h
  src/purchase.cpp
  src/seedData.h
  src/inventorylisttab.cpp
  src/inventorylisttab.ui
  src/inventorylisttab.h
  src/inventorymodel.cpp
  src/inventorymodel.h
  src/dayprocessing.cpp
  src/dayprocessing.h
  src/utils.cpp
  src/utils.h
)

target_link_libraries(P2 PRIVATE Qt5::Widgets Qt5::Sql)
