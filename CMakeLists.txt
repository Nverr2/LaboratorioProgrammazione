cmake_minimum_required(VERSION 3.27)
project(LaboratorioProgrammazione)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(googletest)
enable_testing()

include_directories(
        ${PROJECT_SOURCE_DIR}/googletest/googletest/include
        ${PROJECT_SOURCE_DIR}/googletest/googlemock/include
)

# Eseguibile prog
add_executable(AppMain
        main.cpp
        Transazione.h
        Tingresso.cpp
        Tingresso.h
        Tuscita.cpp
        Tuscita.h
        ContoCorrente.cpp
        ContoCorrente.h
)

# Eseguibile dei test
add_executable(AppTests
        test_main.cpp
        Transazione.h
        Tingresso.cpp
        Tingresso.h
        Tuscita.cpp
        Tuscita.h
        ContoCorrente.cpp
        ContoCorrente.h
)

target_link_libraries(AppTests
        gtest
        gmock
        gtest_main
        pthread
)

add_test(NAME AppTests COMMAND AppTests)
