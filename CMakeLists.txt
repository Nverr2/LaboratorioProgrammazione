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


# Aggiungi GoogleTest
add_subdirectory(googletest)

# Includi header e GTest
include_directories(
        ${PROJECT_SOURCE_DIR}
        googletest/googletest/include
)

# Eseguibile per i test
add_executable(runTests
        test_main.cpp
        ContoCorrente.cpp
)

# Linka Google Test
target_link_libraries(runTests gtest gtest_main pthread)

