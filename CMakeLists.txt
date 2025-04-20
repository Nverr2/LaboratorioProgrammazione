cmake_minimum_required(VERSION 3.27)
project(LaboratorioProgrammazione)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
        ContoCorrente.cpp
        ContoCorrente.h
        Transazione.cpp
)

# Eseguibile dei test
add_executable(AppTests
        test/test_main.cpp
        Transazione.h
        Transazione.cpp
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
