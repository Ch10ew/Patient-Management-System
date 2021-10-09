cmake_minimum_required(VERSION 3.0.0)  # CMake version check
project(PMS VERSION 0.1.0)  # Project name & Version
set(CMAKE_CXX_STANDARD 11)  # C++ Standard
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(PMS
    src/main.cpp 
    src/Application/Application.cpp
    src/Application/ResourcePool.cpp 
    src/Module/DoctorModule.cpp
    src/Module/NurseModule.cpp
    src/Module/Module.cpp
    src/Structures/Doctor.cpp
    src/Structures/Nurse.cpp
    src/Structures/Patient.cpp 
    src/Structures/Role.cpp)

target_include_directories(PMS PUBLIC
    $(CMAKE_CURRENT_SOURCE_DIR)/Structures
    $(CMAKE_CURRENT_SOURCE_DIR)/Module
    $(CMAKE_CURRENT_SOURCE_DIR)/Application
    $(CMAKE_CURRENT_SOURCE_DIR)/Util)

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)