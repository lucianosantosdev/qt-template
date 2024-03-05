cmake_minimum_required(VERSION 3.5)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_NAME app-test)

project(${PROJECT_NAME} LANGUAGES CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if ($ENV{GOOGLETEST_DIR})
    get_filename_component(_GTEST_BASE $ENV{GOOGLETEST_DIR} REALPATH)
elseif (EXISTS "${ROOT_PROJECT_DIR}/googletest") # set by QC
    get_filename_component(_GTEST_BASE "${ROOT_PROJECT_DIR}/googletest" REALPATH) # set by QC
elseif (UNIX AND EXISTS "/usr/src/gtest")
    set(_GTEST_BASE "/usr/src/gtest")
endif()

if (_GTEST_BASE AND NOT EXISTS "${_GTEST_BASE}/googletest/src/gtest-all.cc"
        OR NOT EXISTS "${_GTEST_BASE}/googlemock/src/gmock-all.cc")
    message(ERROR "Missing source components (gtest-all.cc and/or gmock-all.cc).")
endif()

find_package(Threads REQUIRED)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Test Quick QuickControls2 Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Test Quick QuickControls2 Widgets)

include_directories(
    ${_GTEST_BASE}/googletest ${_GTEST_BASE}/googletest/include
    ${_GTEST_BASE}/googlemock ${_GTEST_BASE}/googlemock/include
)

set(TEST_SOURCES
    tst_mytestcase.cpp
    main.cpp
)

add_executable(
    ${PROJECT_NAME}
    ${TEST_SOURCES}
    ${_GTEST_BASE}/googletest/src/gtest-all.cc
    ${_GTEST_BASE}/googlemock/src/gmock-all.cc
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Threads::Threads
    app-lib
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Quick
    Qt${QT_VERSION_MAJOR}::QuickControls2
    Qt${QT_VERSION_MAJOR}::Test
)

target_include_directories(${PROJECT_NAME} PUBLIC ${ROOT_PROJECT_DIR}/app/applib/src)
