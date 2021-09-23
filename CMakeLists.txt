cmake_minimum_required(VERSION 3.0.0)
project(ChewAssignment VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 11)
include(CTest)
enable_testing()

include_directories(Structures Module Application Util)
add_executable(ChewAssignment 
    main.cpp 
    Application/Application.cpp 
    Application/ResourcePool.cpp 
    Module/DoctorModule.cpp
    Module/NurseModule.cpp
    Module/UI.cpp
    Structures/Doctor.cpp
    Structures/Nurse.cpp
    Structures/Patient.cpp 
    Structures/Role.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)