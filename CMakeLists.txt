cmake_minimum_required(VERSION 3.27)
project(LaboratorioProgrammazione)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(googletest)

include_directories(
        ${PROJECT_SOURCE_DIR}/googletest/googletest/include
        ${PROJECT_SOURCE_DIR}/googletest/googlemock/include
)

add_executable(LaboratorioProgrammazione main.cpp
        Transazione.h
        Tingresso.cpp
        Tingresso.h
        Tuscita.cpp
        Tuscita.h
        ContoCorrente.cpp
        ContoCorrente.h
        test_main.cpp)


# Linka Google Test
target_link_libraries(LaboratorioProgrammazione gtest gmock gtest_main)

