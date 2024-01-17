cmake_minimum_required(VERSION 3.5)

project(MyTestCase LANGUAGES CXX)

enable_testing()

SET(CMAKE_CXX_STANDARD 11)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui)

add_executable(MyTestCase tst_mytestcase.cpp main.cpp
    Base.h Base.cpp)
add_test(NAME MyTestCase COMMAND MyTestCase)

target_link_libraries(MyTestCase PRIVATE Qt${QT_VERSION_MAJOR}::Gui)

if (DEFINED ENV{CATCH_INCLUDE_DIR})
    set(CATCH_INCLUDE_DIR $ENV{CATCH_INCLUDE_DIR})
else ()
    set(CATCH_INCLUDE_DIR "") # set by Qt Creator wizard
endif ()
if (CATCH_INCLUDE_DIR STREQUAL "")
    message("CATCH_INCLUDE_DIR is not set, assuming Catch2 can be found automatically in your system")
elseif (EXISTS ${CATCH_INCLUDE_DIR})
    include_directories(${CATCH_INCLUDE_DIR})
endif ()