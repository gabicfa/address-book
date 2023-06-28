cmake_minimum_required(VERSION 3.5)

# Name of the project
project(AddressBook)

# use C++ 14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Option for building the tests
option(BUILD_TESTS "Build tests" OFF)

# Set the name of the executable we want to build
set(TargetName AddressBook)
add_executable(${TargetName})

target_sources(${TargetName} PRIVATE 
            ${PROJECT_SOURCE_DIR}/src/main.cpp 
)

if(BUILD_TESTS)
    # Google Test integration
    enable_testing()
    find_package(GTest CONFIG)
    if(GTest_FOUND)
        include(GoogleTest)
        set(TestName AddressBookTests)
        add_executable(${TestName})
        include_directories(include)
        target_sources(${TestName} PRIVATE tests/tests.cpp
        )
        target_link_libraries(${TestName} PRIVATE GTest::gtest GTest::gtest_main)
        gtest_discover_tests(${TestName})
    endif()
endif()
