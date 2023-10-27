cmake_minimum_required(VERSION 3.26)
project(cpp)

set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main main.cpp
        FileReader.h
        SplitService.h service/SplitService.cpp
        CSVFileWriter.h service/CSVFileWriter.cpp
        StatisticStorage.h service/StatisticStorage.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()


add_executable(
        StatisticStorageTest
        test/StatisticStorageTest.cc
)

add_executable(
        SplitServiceTest
        test/SplitServiceTest.cc
)

add_executable(
        FileReaderTest
        test/FileReaderTest.cc
)

add_executable(
        CSVFileWriterTest
        test/CSVFileWriterTest.cc
)

target_link_libraries(
        StatisticStorageTest
        GTest::gtest_main
)

target_link_libraries(
        SplitServiceTest
        GTest::gtest_main
)

target_link_libraries(
        FileReaderTest
        GTest::gtest_main
)

target_link_libraries(
        CSVFileWriterTest
        GTest::gtest_main
)


include(GoogleTest)
gtest_discover_tests(StatisticStorageTest SplitServiceTest FileReaderTest CSVFileWriter)