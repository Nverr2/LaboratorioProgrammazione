cmake_minimum_required(VERSION 3.27)
project(LaboratorioProgrammazione)

set(CMAKE_CXX_STANDARD 17)

add_executable(LaboratorioProgrammazione main.cpp
        Transazione.h
        Tingresso.cpp
        Tingresso.h
        Tuscita.cpp
        Tuscita.h
        ContoCorrente.cpp
        ContoCorrente.h
        test_main.cpp)


# Scarica GoogleTest (solo una volta per il progetto)
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
# Imposta GTest per non installarlo nel sistema
set(BUILD_GMOCK OFF)
set(INSTALL_GTEST OFF)

# Scarica e rendi disponibile GoogleTest
FetchContent_MakeAvailable(googletest)

# Aggiungi il target per i test
enable_testing()

add_executable(my_tests
        test_main.cpp # File principale dei test
)
target_link_libraries(my_tests
        gtest
        gtest_main
)

add_test(NAME MyTests COMMAND my_tests)

